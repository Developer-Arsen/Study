#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024
#define FILE_PATH "./error.txt"

struct Log {
    char level[10];
    char message[1024];
} typedef Log;

struct LvlCounts {
    int info_count;
    int warning_count;
    int error_count;
} typedef LvlCounts;

void handle(const char * type, const char * buff, Log ** arr, int * arrIndex) {
    Log * tmpLog = (Log*) malloc(sizeof(Log));
    strncpy(tmpLog->level, type, strlen(type));

    int index = strlen(type);
    while (buff[index] == ' ') index++;
    
    char tmp[BUFF_SIZE];
    strcpy(tmpLog->message, buff + index);

    arr[(*arrIndex)++] = tmpLog;
}

int main() {
    FILE * file = fopen(FILE_PATH, "r");
    char * WARNING = "WARNING";
    char * INFO    = "INFO";
    char * ERROR   = "ERROR";

    if (file == NULL) {
        puts("error on file");
        exit(EXIT_FAILURE);
    }

    Log * arr[200];
    int arrIndex = 0;

    char buff[BUFF_SIZE];
    while (fgets(buff, 100, file))
    {
        if (strncmp(buff, WARNING, strlen(WARNING)) == 0) {
            handle(WARNING, buff, arr, &arrIndex);
        } 
        else if (strncmp(buff, INFO, strlen(INFO)) == 0) { 
            handle(INFO, buff, arr, &arrIndex);
        }
        else if (strncmp(buff, ERROR, strlen(ERROR)) == 0) { 
            handle(ERROR, buff, arr, &arrIndex);
        } 
    }

    int * msgCounts = (int*) malloc(sizeof(int) * arrIndex);
    LvlCounts lvlCounts = {0,0,0};

    int maxIndex = 0;
    int max = 0;
    for (size_t i = 0; i < arrIndex; i++)
    {
        if (strcmp(arr[i]->level, INFO) == 0) lvlCounts.info_count++;
        else if (strcmp(arr[i]->level, ERROR) == 0) lvlCounts.error_count++;
        else if (strcmp(arr[i]->level, WARNING) == 0) lvlCounts.warning_count++;

        for (size_t j = 0; j < arrIndex; j++)
        {
            if (strcmp(arr[i]->message, arr[j]->message) == 0) msgCounts[i]++;
            if (msgCounts[i] > max) {
                max = msgCounts[i];
                maxIndex = j;
            }
        }
    }

    printf("\n----------------\n ");
    printf("\nInfo Count : %d \nError count: %d   \nWarning count: %d", lvlCounts.info_count, lvlCounts.error_count, lvlCounts.warning_count);
    printf("\n\n----------------\n ");
    printf("most repeated msg : %s \n", arr[maxIndex]->message);

    for (size_t i = 0; i < arrIndex; i++)
    {
        printf("%d \n", msgCounts[i]);
    }
}
