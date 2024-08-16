#include <pthread.h>
#include <stdio.h>
#include <stdatomic.h>

static int glob = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void * threadFunc(void *arg)
{
    int loops = *((int *) arg);
    int loc, j;
    for (j = 0; j < loops; j++) {

        // atomic_fetch_add(&glob, 1);
        pthread_mutex_lock(&mtx);
        glob++;
        // // loc = glob;
        // // loc++;
        // // glob = loc;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}
int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;
    loops = 10000000;
    s = pthread_create(&t1, NULL, threadFunc, &loops);
    s = pthread_create(&t2, NULL, threadFunc, &loops);

    s = pthread_join(t1, NULL);
    s = pthread_join(t2, NULL);
    printf("glob = %d\n", glob);
    
    return 0;
}