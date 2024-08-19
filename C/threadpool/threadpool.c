#include "threadpool.h"

typedef struct {
    tpool_t * pool;
    int id;
} arg_t;

void init_tpool(tpool_t * pool) {
    pthread_mutex_init(&pool -> mutex, NULL);
    pthread_cond_init(&pool -> cond, NULL);
    constructor(&pool->queue);

    for (size_t i = 0; i < THREADS_COUNT; i++)
    {   
        arg_t * arg = malloc(sizeof(arg_t));
        arg -> pool = pool;
        arg -> id = i;

        pthread_create(&pool->threads[i], NULL, thread_main, arg);
    }
}

void * thread_main (void * arg) {
    arg_t* a = (arg_t*) arg;
    tpool_t* p = a -> pool;

    for (;;)
    {
        pthread_mutex_lock(&p->mutex);

        while (p->queue.head == NULL) {
            pthread_cond_wait(&p->cond, &p->mutex);
        }

        task_t task = pop(&p->queue);
        pthread_mutex_unlock(&p->mutex);

        task.current_job(&a->id);
    }
}

void submit_task(tpool_t * pool, task_t task) {
    push_back(&pool->queue, task);
    pthread_cond_broadcast(&pool->cond);
}