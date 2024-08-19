#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

int sock;
char readBuff[512]; 
char buff[512];

void * thr_read(void * arg) {
    while (1) {
        memset(readBuff, 0, sizeof(readBuff));
        read(sock, readBuff, 512);
        printf("%s \n", readBuff);
    }
}

void * thr_write(void * arg) {
    while (1) {
        fgets(buff, 512, stdin);
        write(sock, buff, strlen(buff));
        memset(buff, 0, 512);
    }
}

int main () {
    pthread_t tid, tid2;


    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket error");
        close(sock);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(12345);
    client.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = connect(sock, (struct sockaddr*) &client, sizeof(client));
    if (res == -1) {
        perror("connect error");
        close(sock);
        exit(EXIT_FAILURE);
    }

    pthread_create(&tid, NULL, thr_read, NULL);
    pthread_create(&tid2, NULL, thr_write, NULL);

    while(1) {
        sleep(1);
    }
    close(sock);
}
