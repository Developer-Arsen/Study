#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <string.h>


#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade;
} Student;


typedef struct  {
    int size;
    Student arr[10];
    int grade;
} Mec;

void * maxGradeStudent(void * studentsArr) {
    Mec *mec = (Mec *) studentsArr;

    int max = 0;
    Student * maxptr;
    for (int i = 0; i < mec->size; i++) {
        if ( max < mec->arr[i].grade) {
            max = mec->arr[i].grade;
        }
    }

    mec->grade = max;

    return (void*) mec;
}



int main() {
    int size = 10;
    Student students[10] = {
        {"Alice", 1},
        {"Bob", 2},
        {"Charlie", 3},
        {"David", 4},
        {"Eve", 5},
        {"Frank", 6},
        {"Grace", 7},
        {"Heidi", 8},
        {"Ivan", 9},
        {"Judy", 10}
    };

    Mec mec;
    memcpy(mec.arr, students, sizeof(Student) * size);
    mec.size = size;
    mec.grade = 0;

    void * ptr;
    pthread_t thread;
    pthread_create(&thread, NULL, maxGradeStudent, (void*)&mec);
    pthread_join(thread, (void**) &ptr);

    ptr = (Mec*) ptr;
    Mec* max = ptr;

    printf("%d ", max->grade);

    
    return 0;
}
