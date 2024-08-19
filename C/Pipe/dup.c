#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main () {
    int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

    if (fd < 0) {
        perror("file is not created");
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup error");
    }

    close(fd);
    while(1);
    printf("sadasdasd");

}