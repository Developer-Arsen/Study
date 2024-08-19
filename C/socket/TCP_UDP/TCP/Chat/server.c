#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

int fd[100];

void* client_thread(void* arg) {
    int client_fd = *(int*)arg;
    char buffer[512];
    read(client_fd, buffer, sizeof(buffer));
    printf("the %s is connect to chat\n", buffer);
    while (1) {
        memset(buffer, 0, 512);
        int bytes_received = read(client_fd, buffer, sizeof(buffer) - 1);
        if (bytes_received <= 0) {
            perror("recv failed");
            close(client_fd);
            for (int i = 0; i < 100; i++) {
                if (fd[i] == client_fd) {
                   fd[i] = 0;
                    break;
                }
            }
            return NULL;
        }
        buffer[bytes_received] = '\0';
        

       for(int i = 0; i < 100; ++i) {
            if(fd[i] != 0 && fd[i] != client_fd) {
                write(fd[i], buffer, strlen(buffer));
            }
       }

    }

}


int main () {
    pthread_t tid[100];

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("socket error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(12345);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("bind error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, SOMAXCONN) == -1) {
        perror("bind error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct sockaddr_in client;
        memset(&client, 0, sizeof(client));

        socklen_t size = sizeof(client);
        int new_client_fd = accept(server_fd, (struct sockaddr*) &client, &size);

        if(new_client_fd == -1) {
            perror("accept failed");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < 100; i++) {
            if(fd[i] == 0) {
                fd[i] = new_client_fd;
                pthread_create(&tid[i], NULL, client_thread, &new_client_fd);
                break;
            }
        }
    }
}