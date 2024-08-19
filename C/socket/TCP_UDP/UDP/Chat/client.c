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
        server.sin_addr.s_addr = inet_addr("192.168.32.242");

        char buff[512] = "hello";
        while (1) {

            sendto(sockfd, buff, strlen(buff),0, (struct sockaddr*) &server, sizeof(server));
        }
    }