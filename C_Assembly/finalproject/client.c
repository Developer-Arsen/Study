#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define EXITSUCESS   "✅🚪 Exit Successfully:"

struct ERR {
    char * msg;
    int sockfd;
} typedef ERR;

int sockfd;
char name[50];
char interfaceBuff[1024];

void printError(ERR *);
void makeInterface();
void printInterface();

void * thread_read(void  * arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int Rbytes = read(sockfd, buffer, sizeof(buffer) - 1);
        if (Rbytes <= 0) {
            ERR err = {"read error", sockfd};
            printError(&err);
        }
        buffer[Rbytes] = '\0'; 
        printf("Message from server: %s\n", buffer);
        if (!strncmp(buffer, EXITSUCESS, strlen(EXITSUCESS))) {
            close (sockfd);
            exit(EXIT_SUCCESS);
        }
    }
    return NULL;
}

void * thread_write(void  * arg) {
    char msg[BUFFER_SIZE];
    while (1) {
        printf("Enter command: \n");
        fgets(msg, sizeof(msg), stdin);
        int len = strlen(msg);
        
        if (msg[len - 1] == '\n') {
            msg[len - 1] = '\0'; 
            len--;
        }
        
        int WBytes = write(sockfd, msg, len);
        if (WBytes == -1) {
            ERR err = {"write error", sockfd};
            printError(&err);
        }
    }
    return NULL;

}

int main () {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        ERR err = {"socket error", sockfd};
        printError(&err);
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_port = htons(12345);
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");


    int connectresult = connect(sockfd, (struct sockaddr*) &client, sizeof(client));
    if (connectresult == -1) {
        ERR err = {"connect error", sockfd};
        printError(&err);
    }

    makeInterface();
    printInterface();

    pthread_t th_wr, th_rd;
    pthread_create(&th_wr, NULL, thread_write, NULL);
    pthread_create(&th_rd, NULL, thread_read, NULL);

    pthread_join(th_wr, NULL);
    pthread_join(th_rd, NULL);

    close(sockfd);
    return 0;
}

void printError(ERR * err) {
    perror(err->msg);
    close(err->sockfd);
    exit(EXIT_FAILURE);
}

void makeInterface() {
    sprintf(interfaceBuff, "%s\n   %s\n    -%s\n    -%s\n    -%s\n    -%s\n    -%s\n ", "Welcome to the RFMS Client Interface!", "Available Commands:",
    "create [filename]", "read [filename)", "update [filename] [data] {postion}", "delete [filename]", "exit");
}

void printInterface() {
    puts(interfaceBuff);
}