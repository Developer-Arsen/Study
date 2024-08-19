#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef void *(*job) (void*);

typedef struct {
    job current_job;
    void * arg;
} task_t;

typedef struct node_t {
    task_t task;
    struct node_t * next;
} node_t;

typedef struct {
    node_t * head;
    pthread_mutex_t mutex;
} queue_t;

void constructor(queue_t *);
void push_back(queue_t *, task_t task);
task_t pop(queue_t *);

#endif