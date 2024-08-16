#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void * printFoo(void*) {
    printf("foo \n");
    fflush(stdout);
}

void * printBar(void*) {
    printf("Bar \n");
    fflush(stdout);
    
}

int main () {
    pthread_t pthread1,pthread2;
    
    pthread_create(&pthread1, NULL, printFoo, NULL);
    pthread_create(&pthread2, NULL, printBar, NULL);

    while (1);
    
}