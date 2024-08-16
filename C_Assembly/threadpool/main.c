#include "threadpool.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void * foo(void * arg) {
    printf("the function f... ID : %d ", *(int*)arg);
    fflush(stdout);
    return NULL;
} 

void * goo(void * arg) {
    printf("the function g... ID : %d ", *(int*)arg);
    fflush(stdout);

    return NULL;
} 

tpool_t pool;
void handle() {
    printf("---------------------------------------- \n");
    printf("from cron ");
    printf("\n---------------------------------------- \n");
    submit_task(&pool, (task_t){foo, NULL});
}

int main () {
    signal(SIGUSR1, handle);

    init_tpool(&pool);

    for (size_t i = 0; i < 12; i++)
    {
        submit_task(&pool, (task_t){foo, NULL});
    }

    while(1);
}