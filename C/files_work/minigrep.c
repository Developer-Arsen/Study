#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

int main (int argc, char* argv[]) {
    if (argc < 3) {
        printf("argument error");
        exit(EXIT_FAILURE);
    }

    char * fileName = argv[1];
    char * bar = argv[2];
    bool caseSens = false;
    if (argc >= 4 && !strcmp(argv[3], "-i")) {
        caseSens = true;
    }

    short buffSize = 1024; 
    char buff[buffSize];
    int fd = open(fileName, O_RDONLY);
    char tmpBuff[buffSize];

    while(read(fd, buff, buffSize)) {
    
        int mainIndex = 0;
        int index = 0;

        while (buff[mainIndex])
        {
            if (buff[mainIndex] != '\n')
            {
                tmpBuff[index] = buff[mainIndex];
                index++;
            } else {
                if (caseSens) {
                    if (strcasestr(tmpBuff, bar)) {
                        puts(tmpBuff); 
                    }
                }
                else {
                    if (strstr(tmpBuff, bar)) {
                        puts(tmpBuff); 
                    }
                }
                memset(tmpBuff, 0 , buffSize);
                index = 0;
            }
            mainIndex++;
        }
        memset(buff, 0, buffSize);
    }
}