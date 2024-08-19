#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {
    // int fifo = mkfifo("chlp", 0666);

    int fd = open("./chlp", O_RDONLY);
    printf("dd\n");
    if (fd == -1) {
        perror("fd error");
    }

    char buff[512];
    while (1)
    {
        memset(buff, 0, strlen(buff));
        int size = read(fd, buff, 512);
        if (size <= 0) {
            perror("size error");
        }

        printf("%s\n", buff);
    }
    
}