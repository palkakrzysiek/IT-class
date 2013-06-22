#! /usr/bin/python3

from socket import *    # get socket constructor and constants
import signal, os       # for Control-C handling
import struct


myHost = 'localhost'
myPort = 12345
loginSize=30
nameSize=255
msgSize=819200


sockobj = socket(AF_INET, SOCK_STREAM)

def signal_handler(signum, frame):
    print('\nCaught signal %d. Exiting...' % signum)
    exitProgram(sockobj)

signal.signal(signal.SIGINT, signal_handler)

def exitProgram(sock):
    sock.close()
    exit(0)


def clear():
    os.system('cls' if os.name=='nt' else 'clear')

if __name__ == '__main__':

    try:
        sockobj.connect((myHost, myPort))
    except:
        print("Cannot connect to the server")
        exit(1)

    login = ''
    clear()
    do_continue = True
    while do_continue:

        if login != '':
            print("Your are logged as", login)
        else:
            print("You are not logged in")

        print("What do you want to do?")
        print("Enter according to schemat")
        print("login [username] - to enter your login")
        print("author [phrase] - search book by author]")
        print("title [phrase] - search book by title]")
        print("borrow [signature] - borrow a book")
        print("return [signature] - return a book")
        print("exit or press Ctrl-C - exit the program")

        answer = input("\>")
        try:
            action, what = answer.split(' ', 1)
        except:
            action = answer
            what=''

        if action == 'login':
            login = what
            clear()
        if action == 'author' or action == 'title':
            if action == 'author': act = b'a'
            else: act = b't'
            msg = struct.pack("".join(('s', str(loginSize), 's',
                str(nameSize), 's')), act, login.encode('utf8'),
                what.encode('utf8'))
            sockobj.send(msg)
            results = sockobj.recv(msgSize).decode()
            print(results)
        if action == 'borrow':
            msg = struct.pack("".join(('s', str(loginSize), 's',
                str(nameSize), 's')), b'b', login.encode('utf8'),
                what.encode('utf8'))
            sockobj.send(msg)
            results = sockobj.recv(msgSize).decode()
            print(results)


        if action == 'return':
            msg = struct.pack("".join(('s', str(loginSize), 's',
                str(nameSize), 's')), b'r', login.encode('utf8'),
                what.encode('utf8'))
            sockobj.send(msg)
            results = sockobj.recv(msgSize).decode()
            print(results)

        if action == 'exit':
            exitProgram(sockobj)
