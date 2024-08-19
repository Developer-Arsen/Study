#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>


int main () {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("socket error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0 , sizeof(server));
    server.sin_port = htons(12345);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("bind error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char buff[512];
    struct sockaddr_in client;
    memset(&server, 0 , sizeof(client));
    socklen_t size = 0;

    

    while (1) {
        recvfrom(sockfd, buff, 512, 0, (struct sockaddr*) &client, &size);
        printf("%s \n", buff);
        memset(buff, 0 , strlen(buff));
    }

}