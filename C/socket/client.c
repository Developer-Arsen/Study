#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main () {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

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

    connect(sock, (struct sockaddr*) &client, sizeof(client));

    char buffer[512];
    char msg[100];
    scanf("%s", msg);
    int wbytes = write(sock, msg, sizeof(msg));

    memset(buffer, 0, 512);
    int rbytes = read(sock, buffer, 512);
    printf("message %s", buffer);

    close(sock);

}