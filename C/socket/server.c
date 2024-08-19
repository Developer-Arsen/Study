#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main () {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0 , sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening... \n");

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(12345);
    client.sin_addr.s_addr = INADDR_ANY;

    socklen_t size = sizeof(client);
    int accept_fd = accept(sockfd, (struct addr*) &client, &size);


    if (accept_fd == -1) {
        perror("accept is failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char buffer[512];
    int rbytes = read(accept_fd, buffer, 512);
    printf("message %s", buffer);
    char msg[100];struct ERR {
    char * msg;
    int sockfd;
} typedef ERR;

void printError(ERR * err);
    scanf("%s", msg);
    int wbytes = write(accept_fd, msg, sizeof(msg));

    close(accept_fd);
}
