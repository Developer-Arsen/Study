#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

char * filename = "./records.txt";
int ID = 1;

struct Student {
    int id;
    char name[50];
    float grade;

} typedef Student;

enum actions
{
    ADD = 1,
    FIND,
    DELTE,
    UPDATE,
    VIEW,
    EXIT
};

void printMenu() {
    printf("Please Enter Your Action \n 1. Add Rdcord \n 2. Find Student By Id \n 3. Delete \n 4. Update by Id \n 5. View All \n 6. Exit \n ");
}

void printItem(const char * tmpbuff, int index) {
    printf("\n---------------------------------------");
    printf("\n\n");
    while(tmpbuff[index] != '\n' && tmpbuff[index]) {
        printf("%c", tmpbuff[index]);
        index++;
    }
    printf("\n \n");
    printf("--------------------------------------- \n \n \n");
}

void addStudent(FILE * file) {
    char * name = (char*) malloc(50);
    float grade;

    printf("Enter Student name \n");
    getchar();
    scanf("%49s", name);

    printf("%s", "Enter Student grade \n");
    scanf("%f" , &grade);

    char buff[1024];
    struct stat info;
    stat(filename, &info);

    if (!info.st_size) {
        sprintf(buff, "%d\t  %s\t  %f\t", ID, name, grade);
        fprintf(file, "%s" , buff);    
    } else {
        char tmpbuff[1024];
        fread(tmpbuff, 1024, 1, file);
        
        char * ptr = NULL;
        while (strstr(tmpbuff, "\n"))
        {
            ptr = strstr(tmpbuff, "\n");
            char * tmpptr = strstr(tmpbuff, "\n");

            strncpy(tmpptr, "+", 1);
        }

        if (ptr == NULL) {
            ID++;
        } else {
            ptr++;
            int num = atoi(ptr);
            ID = ++num;        
        }

        sprintf(buff, "\n%d\t  %s\t  %f\t", ID, name, grade);
        fprintf(file, "%s" , buff);    
    }
}

void findStudent(FILE * file) {
    int searchingId = 0;
    printf("Please enter Id \n");
    scanf("%d", &searchingId);

    struct stat info;
    stat(filename, &info);

    if (!info.st_size) {
        printf("Nothing to Search: empty");    
    } else {
        fseek(file, 0, SEEK_SET);
        char tmpbuff[1024];
        memset(tmpbuff, 0, 1024);
        fread(tmpbuff, 1024, 1, file);
        
        if (searchingId == atoi(tmpbuff)) {
            printItem(tmpbuff, 0);
        } else {
            while (strstr(tmpbuff, "\n"))
            {
                char * tmpptr = strstr(tmpbuff, "\n");
                strncpy(tmpptr, "+", 1);
                int num = atoi(tmpptr);
                if (searchingId == num) {
                    int add = ID != num ? 1 : 0;
                    int length = (int) (tmpptr - tmpbuff) + add; // +1 for sign 
                    printItem(tmpbuff, length);
                }
            }
        }
    }
}               

void printAll(FILE * file) {
    char buff[1024];
    fseek(file, 0 , SEEK_SET);

    printf("\n---------------------------------------");
    printf("\n\n");

    while ((fread(buff, 1, 1024, file)) > 0) {
        puts(buff);
    }

    printf("\n \n");
    printf("--------------------------------------- \n \n \n");
 
}

void delete(FILE * file) {
    int searchingId = 0;
    printf("Please enter Id \n");
    scanf("%d", &searchingId);

    struct stat info;
    stat(filename, &info);

    if (!info.st_size) {
        printf("Nothing to Delete: empty");    
    } else {
        fseek(file, 0, SEEK_SET);
        char tmpbuff[1024];
        memset(tmpbuff, 0, 1024);
        fread(tmpbuff, 1024, 1, file);
        
        if (searchingId == atoi(tmpbuff)) {
            char * tmpptr = strstr(tmpbuff, "\n");
            int length = (int) (tmpptr - tmpbuff) + 1;
            fseek(file, 0 , SEEK_SET);
            fwrite(tmpbuff + length, strlen(tmpbuff), 1, file);
        } 
        // else {
        //     while (strstr(tmpbuff, "\n"))
        //     {
        //         char * tmpptr = strstr(tmpbuff, "\n");
        //         strncpy(tmpptr, "+", 1);
        //         int num = atoi(tmpptr);
        //         if (searchingId == num) {
        //             int add = ID != num ? 1 : 0;
        //             int length = (int) (tmpptr - tmpbuff) + add; // +1 for sign 
        //             printItem(tmpbuff, length);
        //         }
        //     }
        // }
    }

}



int main () {
    FILE * file = fopen(filename, "a+");

    int actionNum = 0;
    
    do {
        printMenu();
        scanf("%d", &actionNum);

        switch (actionNum)
        {
            case ADD:
                addStudent(file);
                break;
            case FIND:
                findStudent(file);
                break;
            case DELTE:
                delete(file);
                break;
            case UPDATE:
                break;
            case VIEW:
                printAll(file);
                break;
            default:
                printf("Good Bye \n");
                exit(EXIT_SUCCESS);
                break;
        }
        fflush(file);
    } while (1);
    
    return 0;
}