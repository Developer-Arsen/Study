#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

    int fds[2];

    if (pipe(fds) == -1) {
        perror("pipe is not created");
        exit(EXIT_FAILURE);
    }

    __pid_t pid = fork();

    if (pid == 0) {
        close(fds[0]);
        int x;
        scanf("%d", &x);
        write(fds[1], &x, sizeof(int));
    }
    else if (pid > 0) {
        close(fds[1]);
        int y;
        read(fds[0], &y, sizeof(int));
        printf("%d from parent", y);
        close(fds[0]);
    } else {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    // int fds[2];
    // if (pipe(fds) == -1) {
    //     perror("pipe is not created");
    //     exit(EXIT_FAILURE);
    // }

    // __pid_t pid = fork();

    // if (pid == -1) {
    //     perror("fork error");
    //     exit(EXIT_FAILURE);
    // }
    // else if (pid == 0) {
    //     close(fds[0]);
    //     int x;
    //     scanf("%d", &x);
    //     write(fds[1], &x, sizeof(int));
    //     close(fds[1]);
    // } 
    // else {
    //     close(fds[1]);
    //     int y;
    //     read(fds[0], &y, sizeof(int));
    //     printf("%d", y);
    //     close(fds[0]);
    // } 
}