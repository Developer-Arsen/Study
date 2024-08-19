#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char * filename = "aabbbceeee";
    int size = strlen(filename) * 2 + 1;
    char * new = (char*) malloc(size);

    int index = 0;
    char c;
    int count = 0;
    while(filename[index]) {
        c = filename[index];
        
        if (c != filename[index+1]) {
            int length = strlen(new);
            sprintf(new + length, "%c%d", c, count);
            count = 0;
        } else 
        
        index++;
    }

    new[strlen(new)] = '\0';
    puts(new);

    return 0;



    char * filename = "./test.txt";
    char * filename2 = "test.modified.txt";

    char * oldMsg = "oldString";
    char * newMsg = "newString";

    int fd = open(filename, O_RDWR);
    int fd2 = open(filename2, O_RDWR | O_CREAT, 0666);

    int buffSize = 1024;
    char buff[buffSize];
    memset(buff, 0, buffSize);

    while(read(fd, buff, buffSize )) {

        while (strstr(buff, oldMsg))
        {
            char * ptr = strstr(buff, oldMsg);
            strncpy(ptr, newMsg, strlen(oldMsg));
        }
        write(fd2, buff, strlen(buff));
    }

    close(fd);
    close(fd2);

    return 0;
}
