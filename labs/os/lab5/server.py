#!/usr/bin/env python

from miniboa import TelnetServer

IDLE_TIMEOUT = 300
CLIENT_LIST = []
SERVER_RUN = True
DATABASE = []
lockDatabase = False
WELCOME_MSG = """\
Welcome to our library 
Enter:
    author [name of author] - to find book by author
    [title] - to find book by title
"""

def read_database(filename):
    f = open(filename, 'r')
    for line in f:
        signature, author, title, borrowed_by = line.split(' : ')
        DATABASE.append({'signature': signature.strip(), "author": author.strip(),
            "title" :  title.strip(), "borrowed_by" :  borrowed_by.strip()})
    f.close()
    for n in DATABASE:
        print n


def on_connect(client):
    """
    Sample on_connect function.
    Handles new connections.
    """
    print "++ Opened connection to %s" % client.addrport()
    broadcast('%s joins the conversation.\n' % client.addrport() )
    CLIENT_LIST.append(client)
    print(client)
    client.send(WELCOME_MSG)


def on_disconnect(client):
    """
    Sample on_disconnect function.
    Handles lost connections.
    """
    print "-- Lost connection to %s" % client.addrport()
    CLIENT_LIST.remove(client)


def kick_idle():
    """
    Looks for idle clients and disconnects them by setting active to False.
    """
    ## Who hasn't been typing?
    for client in CLIENT_LIST:
        if client.idle() > IDLE_TIMEOUT:
            print('-- Kicking idle lobby client from %s' % client.addrport())
            client.active = False


def process_clients():
    """
    Check each client, if client.cmd_ready == True then there is a line of
    input available via client.get_command().
    """
    for client in CLIENT_LIST:
        if client.active and client.cmd_ready:
            ## If the client sends input echo it to the chat room
            process_find(client)


def broadcast(msg):
    """
    Send msg to every client.
    """
    for client in CLIENT_LIST:
        client.send(msg)


def process_find(client):
    """
    Search book in database
    """
    msg = client.get_command()
    try:
        action, what = msg.split(' ', 1)
        print '%s search for %s "%s"' % (client.addrport(), action, what)
        print action == author
        if action == 'author':
            for n in DATABASE:
                print n[author]
                if n[author].find(what):
                    print n
                else:
                    print "don't found"
    except:
        pass



    ## bye = disconnect


#------------------------------------------------------------------------------
#       Main
#------------------------------------------------------------------------------

if __name__ == '__main__':

    ## Simple chat server to demonstrate connection handling via the
    ## async and telnet modules.

    ## Create a telnet server with a port, address,
    ## a function to call with new connections
    ## and one to call with lost connections.

    telnet_server = TelnetServer(
        port=7777,
        address='',
        on_connect=on_connect,
        on_disconnect=on_disconnect,
        timeout = .05 # length of time to wait on user input during a pol()
        )

    read_database("data.dat")

    print(">> Listening for connections on port %d.  CTRL-C to break."
        % telnet_server.port)

    ## Server Loop
    while SERVER_RUN:
        telnet_server.poll()        ## Send, Recv, and look for new connections
        kick_idle()                 ## Check for idle clients
        process_clients()           ## Check for client input

    print(">> Server shutdown.")
