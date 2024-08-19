#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void desctructor(void* arg) {
    free(arg);
    printf("thread_sepficic data cleaned");
}

pthread_key_t key;


void * thread(void * arg) {
    int *counter = pthread_getspecific(key);
    if(counter == NULL) {
        counter = malloc(4);
        *counter = 0;
        pthread_setspecific(key, (void*)counter);
    }
    printf("%p\n", counter);
    for (size_t i = 0; i < 5; i++)
    {
        (*counter)++;
        printf("thread %ld count %d\n", i,  *counter);
    }
    int * res = (int*) pthread_getspecific(key);
    printf("final counter is : %d \n", *res);
    return NULL;
}

int main () {
    pthread_key_create(&key, NULL);
    thread(NULL);
    thread(NULL);
    thread(NULL);
    // pthread_key_create(&key, )(void*)counter



}