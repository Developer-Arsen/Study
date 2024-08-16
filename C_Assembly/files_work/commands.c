#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define BUFF_SIZE 1024
#define FILE_PATH "./commands.txt"

int command_exists(const char *command) {
    char cmd[256];
    const char * space = strchr(cmd, ' ');
    if (space) {
        snprintf(cmd, space - cmd + 1, "%s", command);
    } else {
        snprintf(cmd, sizeof(cmd), "%s", command);
    }

    char check_cmd[1024];
    snprintf(check_cmd, sizeof(check_cmd), "which %s > /dev/null 2>&1", cmd);

    return system(check_cmd) == 0;
}


int main(int argc, char *argv[]) {
    FILE * file = fopen(FILE_PATH, "w+");

    if (file == NULL) {
        puts("exited on null");
        exit(EXIT_FAILURE);
    }

    
    int index = 0;
    while(1) {
        char command[256];
        printf("Enter Command \n");
        fgets(command, 256, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "break") == 0) {
            break;
        }
        else if (command_exists(command)) {
            fprintf(file, " %d: %s \n", ++index, command);
        } 
        else {
            puts("command does not exist");

        }
        fflush(file);
        fflush(stdin);
        fflush(stdout);
    }

    fseek(file, 0, SEEK_SET);
    char buff[1024];
    fread(buff, 1024, 1 , file);
    
    printf("\n----------------\n ");
    printf("%s \n \n", buff);
    printf("\n----------------\n ");

    int number = 0;
    puts("Enter Command number");
    scanf("%d", &number);

    if (number < 1) {
        puts("wrong number");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_SET);
    truncate(file, 0);
    while (fgets(buff, 1024, file))
    {
        int lineNumber = atoi(buff);
        if (number == lineNumber) {
            char * ptr = buff;

            while ((*ptr) != ':') {
                ptr++;
            }
            ptr += 2;
            system(ptr);
        }
    }

    return 0;
}