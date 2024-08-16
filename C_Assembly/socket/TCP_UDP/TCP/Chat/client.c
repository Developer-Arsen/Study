#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>


#define BUFFER_SIZE 512

int sockfd;
char name[50];

void* read_thread(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int Rbytes = read(sockfd, buffer, sizeof(buffer) - 1);
        if (Rbytes <= 0) {
            perror("read failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        buffer[Rbytes] = '\0'; 
        printf("Message from server: %s\n", buffer);
    }
    return NULL;
}

void* write_thread(void* arg) {
    char msg[BUFFER_SIZE];
    while (1) {
        printf("Enter message: ");
        fgets(msg, sizeof(msg), stdin);
        int len = strlen(msg);
        if (msg[len - 1] == '\n') {
            msg[len - 1] = '\0'; 
            len--;
        }
        int WBytes = write(sockfd, msg, len);
        if (WBytes == -1) {
            perror("write failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    }
    return NULL;
}

int main () {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_port = htons(12345);
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");


    int connectresult = connect(sockfd, (struct sockaddr*) &client, sizeof(client));

    if (connectresult == -1) {
        perror("connectresult error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }


    printf("Input your name... \n");
    fgets(name, sizeof(name), stdin);
    int len = strlen(name);
    if (name[len-1] == '\n'){
        name[len-1] == '\0';
        len--;
    }

    write(sockfd, name, strlen(name));

    pthread_t read_tid, write_tid;
    pthread_create(&read_tid, NULL, read_thread, NULL);
    pthread_create(&write_tid, NULL, write_thread, NULL);

    pthread_join(read_tid, NULL); 
    pthread_join(write_tid, NULL); 

    close(sockfd);
    return 0;


}