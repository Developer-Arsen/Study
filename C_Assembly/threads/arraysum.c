#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


// understand cpu set work with it
// try scheduler functions use them
// 

struct tmp {
    int size;
    int * arr;
};


// void * sum (void * tmp) {
//     struct tmp * tmpstruct = (struct tmp*) tmp;

//     int * res = (int*) malloc(sizeof(int));
//     *res = 0;

//     for (size_t i = 0; i < tmpstruct->size; i++)
//     {
//         *res += i;
//     }
//     return (void *) res;
// }

void * primeNumber(void * number) {
    printf("test\n");
    fflush(stdin);
    fflush(stdout);
    return NULL;
    // int * num = (int*) number;
    // int * arr = (int*) malloc(sizeof(int) * (*num));

    // int index = 0;
    // int size = 0;
    // for (size_t i = 3; i <= *num; i++)
    // {
    //     int flag = 1;
    //     for (int j = 2; j <= i / 2; j++) {
    //         if (i % j == 0) {
    //             flag = 0;
    //             break;
    //         }
    //     }
    //     if (flag) {
    //         arr[index++] = i;
    //         size++;
    //     }
    // }
    
    // struct tmp * structtmp = (struct tmp *) malloc(sizeof(struct tmp ));
    // structtmp->size = size;
    // structtmp->arr = arr;

    // return (void*) structtmp;
}

// void * printArr(void * obj) {
//     struct tmp * structtmp = (struct tmp *) obj;
//     for (size_t i = 0; i < structtmp->size; i++)
//     {
//         printf("%d ", structtmp->arr[i]);
//     }

//     free(structtmp);
// } 

int main () {
    pthread_t thread;
    pthread_create(&thread, NULL, primeNumber, NULL);
    // void * ptr;
    // int * num = (int*) malloc(sizeof(int));
    // *num = 15;

    // pthread_t thread;
    // pthread_create(&thread, NULL, primeNumber, (void*)num);
    // pthread_join(thread, (void**)&ptr);

    // pthread_t second_thread;
    // pthread_create(&second_thread, NULL, printArr, ptr);
    // pthread_join(second_thread, NULL);

} 
