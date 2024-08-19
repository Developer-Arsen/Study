#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>


void parser(char *, int);
void lslogic(char*);
void printLongInfo(struct dirent * );

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

    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt SO_REUSEADDR");
    }

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
    memset(&client, 0 , sizeof(client));
    
    printf("hellllo \n");
    socklen_t size = sizeof(client);
    int accept_fd = accept(sockfd, (struct sockaddr *) &client, &size);

    if (accept_fd == -1) {
        perror("accept is failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char buff[512];
    dup2(accept_fd, STDOUT_FILENO);

    while (1) {
        memset(buff, 0 ,sizeof(buff));
        int r = read(accept_fd, buff, 512);

        if(r == 0) {
            printf("clinet is disconnect");
            break;
        } else if(r < 0) {
            perror("error");
        }
        parser(buff,accept_fd);
    }   
    close(accept_fd);
}

void parser (char * buff, int accept_fd) {
    if (strstr(buff, "ls") != NULL) {
        lslogic(buff);
        return;
    } 
    system(buff);
    
}

void lslogic(char * src) {
    DIR * dir;
    struct dirent *entry;

    dir = opendir("./");

    if (dir == NULL) {
        perror("dir open failed");
        return;
    }

    int hidden = 0;
    int longInfo = 0;
    if (strstr(src, "a") != NULL) {
        hidden = 1;
    }

    int size = 0;
    while(src[size] && src[size] != '-') size++;

    char * secondSlice = src + size;
    
    if (strstr(secondSlice, "l") != NULL) {
        longInfo = 1;
    }


    while((entry = readdir(dir)) != NULL) {
        if (!hidden && (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))) continue;


        if (longInfo) {
            printLongInfo(entry);
        } else {
            printf("%s \n", entry->d_name);
        }
    }
}

void printLongInfo(struct dirent * entry) {

    struct tm * time;
    struct stat info;
    stat(entry->d_name, &info);

    time = localtime(&info.st_mtime);

    char tmBuff[100] = {0};
    strftime(tmBuff, 100, "%b %d %H:%M \n", time);
    printf("%ld  %ld  %s %s \n", info.st_nlink, info.st_size, tmBuff, entry->d_name);

}