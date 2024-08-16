#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main () {
    int fds[2];
    if (pipe(fds) == -1) {
        perror("pipeline error");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid1, pid2;
    
    pid1 = fork();
    if (pid1 == 0) {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);

    } else {
        close(fds[1]);
        wait(NULL);
        pid2 = fork();

        if (pid2 == 0) {
            int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
            dup2(fds[0], STDIN_FILENO);
            dup2(fd, STDOUT_FILENO);
            execlp("grep", "grep", "a.out", NULL);
        }
    }
}