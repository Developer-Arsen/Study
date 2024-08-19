#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define file "./words.txt"
#define size 1024

pthread_t th, th2;
sigset_t set;
FILE * stream;

void * thread1(void * arg) {
    printf("arajin \n");
    int sig = 0;

    sigwait(&set, &sig);
    char buff[1024];
        
    while(fgets(buff, 100, stream)) {
        printf("%s \n", buff);
        fflush(stdout);
    }
    
    pthread_kill(th2, SIGUSR2);

    printf("arajin verj \n");

}

void * thread2 (void * arg) {
    printf("erkrord \n");
    int sig;
    sigwait(&set, &sig);
    printf("\n\n%d\n\n", sig);
    printf("erkrord verj \n");

}

int main () {
    stream = fopen(file, "r+");

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);

    sigprocmask(SIG_BLOCK, &set, NULL);

    pthread_create(&th, NULL, thread1,  NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    pthread_kill(th, SIGUSR1);
    pthread_join(th, NULL);
    pthread_join(th2, NULL);
}