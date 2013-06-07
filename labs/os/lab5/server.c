#include <sys/socket.h>
#include <arpa/inet.h> // for creating Internet address
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}

int listener_d; // This will store the main listener socket for server.

void handle_shutdown(int sig){ 
    /*
     * If someone hits Ctrl-C when the server
     * is running, this function will close the 
     * socket before the program ends.
     */
    if (listener_d)
        close(listener_d);
    fprintf(stderr, "Bye!\n");
    exit(0);
}

int read_in(int socket, char *buf, int len){
    // This reads all the characters until it reaches ‘\n’.
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while ((c > 0) && (s[c-1] != '\n')) {
        s += c; slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if (c < 0)
        return c; // In case there’s an error
    else if (c == 0)
        buf[0] = '\0'; // Nothing read; send back an empty string.
    else
        s[c-1]='\0'; // Replace the '\r' character with a '\0'
    return len - slen;
}

int open_listener_socket(){
    int s = socket(PF_INET, SOCK_STREAM, 0); 
    // Create an Internet streaming socket.
    if (s == -1)
        error("Can't open socket");
    return s;
}

void bind_to_port(int socket, int port){
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");
        /*
         * When you bind a socket to a port, the operating system will
         * prevent anything else from rebinding to it for the next 30
         * seconds or so, and that includes the program that bound the port
         * in the first place. To get around the problem, you just need to set
         * an option on the socket before you bind it:
         */
        int c = bind (socket, (struct sockaddr *) &name, sizeof(name)); 
        // Grab port 30000.
    if (c == -1)
        error("Can't bind to socket");
}

int say(int socket, char *s){
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        fprintf(stderr, "%s: %s\n", "Error talking to the client",
                strerror(errno));
    return result;
}


int main(int argc, char const* argv[])
{

    if (catch_signal(SIGINT, handle_shutdown) == -1)
        // This will call handle_shutdown() if Ctrl-C is hit.
        error("Can't set the interrupt handler"); 

    listener_d = open_listener_socket();
    bind_to_port(listener_d, 30000); // Create a socket on port 30000.
    if (listen(listener_d, 10) == -1) // Set the listen-queue length to 10.
        error("Can't listen");

    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    puts("Waiting for connection");
    char buf[255];
    while (1) {
        // Listen for a connection.
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr,
                &address_size);
        if (connect_d == -1)
            error("Can't open secondary socket");

        if(!fork()){
            // In the child, you need to close the main listener socket.
            // The child will use only the connect_d socket to talk to the client.
            close(listener_d);
            if (say(connect_d, "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ") != -1) {
            // Send data to the client.

                read_in(connect_d, buf, sizeof(buf)); // Read data from the client.
            if (strncasecmp("Who's there?", buf, 12))
                say(connect_d, "You should say 'Who's there?'!");
            else {
                if (say(connect_d, "Oscar\r\n> ") != -1) {
                    read_in(connect_d, buf, sizeof(buf));
                    if (strncasecmp("Oscar who?", buf, 10))
                        say(connect_d, "You should say 'Oscar who?'!\r\n");
                    else
                        say(connect_d,
                                "Oscar silly question, you get a silly answer\r\n");
                }
            }
            }
            close(connect_d); // Once the conversation’s over, the child
            exit(0);
            // Once the child process has finished talking, it should exit.
            // That will prevent it from falling into the main server loop.
        }
    close(connect_d);
    }

    return 0;
}
