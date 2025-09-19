#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    struct sockaddr_in serv;
    int sd;
    char buf[80];
    sd = socket(AF_UNIX, SOCK_STREAM, 0);
    // Specify destination address of socket
    // INADDR_ANY = Automatically assign IP address (of current machine)
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(3558);    // Must be same port as specified in server

    // Connect client socket sd to server
    connect(sd, (void*) (&serv), sizeof(serv));
    // Send message to server
    write(sd, "Hello Server\n", 17);
    read(sd, buf, sizeof(buf));
    printf("Message from server: %s\n", buf);
}