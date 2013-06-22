#! /usr/bin/python3

import asyncore
import signal, os       # for Control-C handling
import struct
from io import BytesIO  # for pickling the list 


myHost = ''             # '' = all available interfaces on host
myPort = 12345          # listen on a non-reserved port number
loginSize=30
nameSize=255
msgSize=1+loginSize+nameSize


def signal_handler(signum, frame):
    print('\nCaught signal %d. Exiting...' % signum)
    exit(0)

signal.signal(signal.SIGINT, signal_handler)


class Database:

    database = []
    filename = ''

    def __init__(self, filename):
        self.filename = filename
        f = open(self.filename, 'r')
        for line in f:
            try:
                signature, author, title, borrowed_by = line.split(' : ')
                self.database.append({'signature': signature.strip(),
                    "author": author.strip(), "title" :  title.strip(),
                    "borrowed_by" : borrowed_by.strip()})
            except:
                print('incorrect record: ', line)
        f.close()
        print ("Read %d records" % len(self.database))

    def print(self):
        for n in self.database:
            print(n)

    def find(self, what, phrase):
        """ what - 'author' or 'title' """
        result=''
        for n in self.database:

            author = n['author']
            title = n['title']
            if what == 'author': searched = author
            else: searched = title

            if searched.find(phrase) != -1:
                result += 'signature: '
                result += n['signature']
                result += ' | '
                result += title
                result += ' by '
                result += author
                if n['borrowed_by'] == '':
                    result += ' | Status: available\n'
                else:
                    result += ' | Status: is borrowed\n'
        if result == '': result = "Didn't found"
        return result

    def save(self):
        f = open(self.filename, 'w')
        for n in self.database:
            line = ''.join((n['signature'], ' : ', n['author'], ' : ',
                    n['title'], ' : ', n['borrowed_by'], '\n'))
            f.write(line)
        f.close()


    def borrow(self, login, what):
        for n in self.database:
            if n['signature'] == what:
                if n['borrowed_by'] == '':
                    n['borrowed_by'] = login
                    self.save()
                    return True
                else:
                    return False
        return False

    def returnBook(self, login, what):
        for n in self.database:
            if n['signature'] == what:
                if n['borrowed_by'] == login:
                    n['borrowed_by'] = ''
                    self.save()
                    return True
                else:
                    return False
        return False

database = Database('data.dat')
database.print()

def checkLogin(login):
    if login == '' or not login.find(':') == -1:
        return False
    else:
        return True


class QueryHandler(asyncore.dispatcher_with_send):

    def handle_read(self):
        data = self.recv(msgSize)
        if data:
            try:
                action, login, what = struct.unpack("".join(('s', str(loginSize), 's',
                str(nameSize), 's')), data)
                action = action.decode('utf8').split('\x00', 1)[0]
                what = what.decode('utf8').split('\x00', 1)[0]
                login = login.decode('utf8').split('\x00', 1)[0]
                print(action, what, login)

                if action == 'a' or action == 't':
                    results = ''
                    if action == 'a':
                        print('find by author %s' % what)
                        results = database.find('author', what)
                    if action == 't':
                        print('find by title %s' % what)
                        results = database.find('title', what)
                    msg = results.encode()
                    print(msg)
                    self.send(msg)

                if action == 'b':
                    if not checkLogin(login):
                        self.send(b'incorrect login')
                        print('Attempt to login with incorrect login')
                        return False
                    success = database.borrow(login, what);
                    if success:
                        self.send(b'Successfully borrowed')
                        print('borrowed', login, what)
                    else:
                        self.send(b'An error occurred, maybe someone else have borrowed the book before you')
                        print('Attempt to borrow reserved book')

                if action == 'r':
                    if not checkLogin(login):
                        self.send(b'incorrect login')
                        print('Attempt to login with incorrect login')
                        return False
                    success = database.returnBook(login, what);
                    if success:
                        self.send(b'Successfully returned')
                        print('returned', login, what)
                    else:
                        self.send(b'An error occurred, maybe you gave wrong login or signature')
                        print('Attempt to borrow reserved book')

            except UnicodeDecodeError:
                print("unknown characters")

class LibraryServer(asyncore.dispatcher):

    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket()
        self.set_reuse_addr()
        self.bind((host, port))
        self.listen(5)


    def handle_accepted(self, sock, addr):
        print('Incoming connection from %s' % repr(addr))
        handler = QueryHandler(sock)
    def handle_close():
        print('connection closed')

server = LibraryServer(myHost, myPort)
asyncore.loop()
