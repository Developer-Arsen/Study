#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void doubleintstacks(int arr[2]) {
    arr[1];
    printf("%p", &arr);
    int * ptr = malloc(100);
    int * ptr2 = malloc(100);
    int * ptr3 = malloc(100);
    ptr2 = malloc(100);
}

int a = 10;
void * add(void* arg) {
    while(1){
        sleep(1);
        a++;
    }
}

int factorial(int num) {
    int sum = 1; // 1

    if (num == 0) return sum;
    

    return sum;
}




int main() {
    printf("%d \n", factorial(5));
    // pthread_t tid;
    
    // pthread_create(&tid, NULL, add, NULL);
    // printf("%d \n" , a);

    // pthread_detach(tid);
    // int i = 10;
    // while (i--) {
    //     sleep(1);
    //     printf("%d \n" , a);
    // }

    // pthread_join(tid, NULL);
    // i = 10;
    // while (i--) {
    //     sleep(1);
    //     printf("%d \n" , a);
    // }
    // int arr[] = {1,2};
    // printf("%p \n", arr);
    // doubleintstacks(arr);


}