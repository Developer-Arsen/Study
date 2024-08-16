#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 1024
#define FILE_PATH1 "./git1.txt"
#define FILE_PATH2 "./git2.txt"

int main(int argc, char *argv[]) {
    FILE * file1 = fopen(FILE_PATH1, "r+");
    FILE * file2 = fopen(FILE_PATH2, "r+");

    if (file1 == NULL || file2 == NULL) {
        puts("exited on null");
        exit(EXIT_FAILURE);
    }

    // char buff[1024];
    // char tmpbuff[1024];
    // memset(tmpbuff, 0 ,1024);
    // memset(buff, 0 ,1024);
    
    // fread(buff, 1024, 1, file);
    
    // int count = 0;
    // int index = 0;
    // char c;

    // printf("Compress: 0 \nDecompress: 1 \n");
    // int flag = 0;
    // scanf("%d", &flag);

    // if (flag) {
    //     while (buff[index])
    //     {
    //         c = buff[index];
    //         if (flag) {
    //             if (buff[index+1] >= '1' && buff[index+1] <= '9') {
    //                 int number = atoi(buff + index + 1);
    //                 for (int i = 0; i < number; i++) {
    //                     sprintf(tmpbuff + strlen(tmpbuff), "%c", c);
    //                 }
    //             } 
    //         }
    //         index++;
    //     }
    // }
    // else {
    //     while (buff[index])
    //     {
    //         count++;
    //         c = buff[index];
    //         if (c != buff[index+1]) {
    //             sprintf(tmpbuff + strlen(tmpbuff), "%c%d", c, count);
    //             count = 0;
    //         }
    //         index++;
    //     }
    // }
    
    // truncate(FILE_PATH, 0);
    // fflush(file);

    // fwrite(tmpbuff, strlen(tmpbuff), 1, file);
    // fclose(file);

    // return 0;
}