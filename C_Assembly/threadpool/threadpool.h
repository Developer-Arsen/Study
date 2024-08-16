#ifndef TPOOL
#define TPOOL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "queue.h"

#define THREADS_COUNT 4

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_t threads[THREADS_COUNT];
    queue_t queue;
} tpool_t;

void init_tpool(tpool_t *);
void submit_task(tpool_t*, task_t task);
void * thread_main(void *);

#endif