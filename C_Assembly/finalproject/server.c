#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>
#include <signal.h>

#include "headers/messages.c"

#define MAXCONN 100
#define FILENAMEMAX 30
#define PATH "./db/"

int fds[MAXCONN];
pthread_mutex_t mtx;

struct ERR {
    char * msg;
    int sockfd;
} typedef ERR;

typedef enum {CREATE, READ, UPDATE, DELETE, EXIT} METHODS;

// CRUD Functions
char * cmd_create(char *);
char * cmd_read(char *);
char * cmd_update(char *);
char * cmd_delete(char *);
char * cmd_exit(char *);

char * (*methods_arr[5]) (char*) = {cmd_create, cmd_read, cmd_update, cmd_delete, cmd_exit};

void printError(ERR *);
void * client_thread(void *);
METHODS isValidCommand(char *);
void handleCommand(char *, int);
bool validFile(char *);
void handle_sigint(int);

int main () {
    signal(SIGINT, handle_sigint);

    pthread_t tid[MAXCONN];
    pthread_mutex_init(&mtx, NULL);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt SO_REUSEADDR");
    }

    if (sockfd < 0) {
        ERR err = {"socket error", sockfd};
        printError(&err);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        ERR err = {"bind error", sockfd};
        printError(&err);
    }

    if (listen(sockfd, MAXCONN) < 0) {
        ERR err = {"listen error", sockfd};
        printError(&err);
    }    

    while (1)
    {
        struct sockaddr_in client;
        memset(&client, 0, sizeof(client));

        socklen_t size = sizeof(client);
        int new_client_fd = accept(sockfd, (struct sockaddr*) &client, &size);
        
        if (new_client_fd < 0) {
            ERR err = {"bind error", sockfd};
            printError(&err);
        }

        for (int i = 0; i < MAXCONN - 1; i++)
        {
          if (fds[i] == 0) {
            fds[i] = new_client_fd;
            pthread_create(&tid[i], NULL, client_thread, &new_client_fd);
            break;
          }
        }
        
    }
    
}

void* client_thread(void* arg) {
    int client_fd = *(int*)arg;
    char readBuffer[512];
    while (1) {
        memset(readBuffer, 0, 512);
        int bytes_received = read(client_fd, readBuffer, sizeof(readBuffer) - 1);

        if (bytes_received <= 0) {
            for (int i = 0; i < 100; i++) {
                if (fds[i] == client_fd) {
                   fds[i] = 0;
                    break;
                }
            }
            return NULL;
        }

        handleCommand(readBuffer, client_fd);
    }
}

METHODS isValidCommand(char * buff) {
    if (strstr(buff, "create")) return CREATE;
    if (strstr(buff, "read"))   return READ;
    if (strstr(buff, "update")) return UPDATE;
    if (strstr(buff, "delete")) return DELETE;
    if (strstr(buff, "exit"))   return EXIT;

    return -1;
}

void handleCommand (char * buff, int client_fd) {
    int commandNumber = isValidCommand(buff);
    if (commandNumber < 0) {
        char * msg = "Command is not valid ❌";
        write(client_fd, msg, strlen(msg));
        return;
    }

    char * response = methods_arr[commandNumber](buff);
    write(client_fd, response, strlen(response));
    if (commandNumber == EXIT) { 
        close(client_fd);
    }
}

bool validFile (char * filename) {
    DIR* dir;
    struct dirent *entry;
    dir = opendir(PATH);
    if (dir == NULL) {
        perror("dir open failed");
        return false;
    }


    while((entry = readdir(dir)) != NULL) {
        if (!strncmp(entry->d_name, filename, strlen(filename))) return true;
    }

    return false;
}

char * cmd_create(char * command) {
    strtok(command, " ");
    char * name = strtok(NULL, " ");

    if (name == NULL) return ERR_NOFILENAME;
    if (strlen(name) > FILENAMEMAX) return ERR_FILENAMEMAX;

    char path[100];
    sprintf(path, "%s%s", PATH, name);

    pthread_mutex_lock(&mtx);
    int fd = open(path, O_CREAT | O_EXCL, 0666);
    if (fd < 0) {
        pthread_mutex_unlock(&mtx);
        return ERR_FILEEXIST;
    } 

    pthread_mutex_unlock(&mtx);
    return CREATESUCCESS;
}

char * cmd_read(char * command) {
    strtok(command, " ");
    char * name = strtok(NULL, " ");

    if (name == NULL) return ERR_NOFILENAME;
    if (strlen(name) > FILENAMEMAX) return ERR_FILENAMEMAX;
    if (!validFile(name)) return ERR_FILENOTEXIST;

    char path[100];
    sprintf(path, "%s%s", PATH, name);

    struct stat info;
    stat(path, &info);

    char* content = malloc(info.st_size + 1);
    content[info.st_size + 1] = '\0';

    pthread_mutex_lock(&mtx);
    int fd = open(path, O_RDONLY, 0666);
    if (fd < 0) {
        pthread_mutex_unlock(&mtx);
        return ERR_FILEEXIST;
    } 
    long read_bytes = read(fd, content, info.st_size);
    if (read_bytes < 0) {
        perror("read failed");
    }

    pthread_mutex_unlock(&mtx);    

    return content;
}

char * cmd_update(char * command) {
    strtok(command, " ");
    char * name = strtok(NULL, " ");
    
    if (name == NULL) return ERR_NOFILENAME;
    if (strlen(name) > FILENAMEMAX) return ERR_FILENAMEMAX;
    if (!validFile(name)) return ERR_FILENOTEXIST;
    
    char * content = strtok(NULL, "");
    if (content == NULL) return ERR_NOCONTENT;

    long position = -1;
    char * pos = strtok(content, " ");
    pos = strtok(NULL, " ");

    char path[100];
    sprintf(path, "%s%s", PATH, name);
    struct stat info;
    if (pos != NULL) {
        position = atoi(pos);
        stat(path, &info);
        if (position > info.st_size) return ERR_INVALIDPOSITION;
    }

    pthread_mutex_lock(&mtx);
    int fd = open(path, O_RDWR);

    if (position > 0) {
        lseek(fd, position, SEEK_SET);
        long leftread = info.st_size - position;
        char * lefttext = malloc(leftread);

        read(fd, lefttext, leftread);
        ftruncate(fd, position);
        lseek(fd, position, SEEK_SET);

        write(fd, content, strlen(content));
        lseek(fd, 0, SEEK_END);
        write(fd, lefttext, leftread);
    } else if (position == 0) {
        char * lefttext = malloc(info.st_size);
        read(fd, lefttext, info.st_size);

        ftruncate(fd, position);
        lseek(fd, position, SEEK_SET);

        write(fd, content, strlen(content));
        write(fd, lefttext, strlen(lefttext));
    } else {
        lseek(fd, 0, SEEK_END);
        write(fd, content, strlen(content));
    }

    pthread_mutex_unlock(&mtx);    

    return UPDATESUCCESS;
}

char * cmd_delete(char * command) {
    strtok(command, " ");
    char * name = strtok(NULL, " ");

    if (name == NULL) return ERR_NOFILENAME;
    if (strlen(name) > FILENAMEMAX) return ERR_FILENAMEMAX;
    if (!validFile(name)) return ERR_FILENOTEXIST;

    char path[100];
    sprintf(path, "%s%s", PATH, name);
    
    pthread_mutex_lock(&mtx);    

    int res = remove(path); 
    if (res < 0) {
        pthread_mutex_unlock(&mtx);    
        return DELETEFAIL;
    }

    pthread_mutex_unlock(&mtx);    
    return DELETESUCCESS;
}

char * cmd_exit(char * command) {
    return EXITSUCCESS;
}

void printError(ERR * err) {
    perror(err->msg);
    close(err->sockfd);
    exit(EXIT_FAILURE);
}

void handle_sigint(int sig) {
    printf("\n****************************************\n");
    printf("*                                      *\n");
    printf("*     You pressed Ctrl+C (SIGINT)!     *\n");
    printf("*   Thank you for using our program!   *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
    exit(0);  // Exit the program
}