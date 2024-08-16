#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {
    // int fifo = mkfifo("chlp", 0666);

    // if (fifo == -1) {
    //     perror("fifo error");
    // }

    int fd = open("./chlp", O_WRONLY);
    if (fd == -1) {
        perror("open error");
    }
    printf("dd\n");
    char buff[512];
    dup2(fd, STDOUT_FILENO);
    close(fd);
    while (1)
    {
        scanf("%s", buff);
        printf("%s\n", buff);
        // int size = write(fd, buff, strlen(buff));
        // if (size <= 0) {
            // perror("size error");
        // }

        sleep(1);
    }
}