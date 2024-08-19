#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

struct tmp {
    int size;
    int * arr;
} typedef Tmp;

void * sum (void * tmp) {
    struct tmp * tmpstruct = (struct tmp*) tmp;

    int * res = (int*) malloc(sizeof(int));
    *res = 0;

    for (size_t i = 0; i < tmpstruct->size; i++)
    {
        *res += tmpstruct->arr[i];
    }
    return (void *) res;
}

void * printArr(void * obj) {
    struct tmp * structtmp = (struct tmp *) obj;
    for (size_t i = 0; i < structtmp->size; i++)
    {
        printf("%d ", structtmp->arr[i]);
    }

    free(structtmp);
} 

int main () {
    pid_t pid;
    pid = fork();
    
    if (pid == 0) {
        int size = 5;
        int * arr = (int*) malloc(size * sizeof(int));
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = i;
        }
        Tmp * tmpstr = (Tmp*) malloc(sizeof(Tmp));
        tmpstr -> size = size;
        tmpstr -> arr = arr;

        void * returnval;
        pthread_t thread;
        pthread_create(&thread, NULL, sum, (void*) tmpstr);
        pthread_join(thread, (void**)&returnval);

        int * val  = (int*) returnval;
        printf("%d", *val);
        exit(EXIT_SUCCESS);


    } else if (pid > 0) {
        wait(NULL);
        fflush(stdout);
    }

} 



    // int size = 5;
    // int * arr = (int*) malloc(size * sizeof(int));
    // for (size_t i = 0; i < size; i++)
    // {
    //     arr[i] = i;
    // }
    
    // struct tmp * tmpstruct = (struct tmp *) malloc(sizeof(struct tmp));
    // tmpstruct -> size = size;
    // tmpstruct -> arr = arr;

    // int * t;
    // pthread_t thread ;
    // pthread_create(&thread, NULL, sum, tmpstruct);
    // pthread_join(thread, (void**)&t);

    // // int b = (int) t;
    // printf("%d", *t);