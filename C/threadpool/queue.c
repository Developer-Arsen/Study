#include "queue.h"

void constructor (queue_t * queue) {
    queue->head = NULL;
    pthread_mutex_init(&queue->mutex, NULL);
}

void push_back(queue_t * queue, task_t task) {
    pthread_mutex_lock(&queue->mutex);
    node_t * newNode = (node_t *) malloc(sizeof(node_t));
    newNode ->next = NULL;
    newNode -> task = task;

    if (queue->head == NULL) {
        queue->head = newNode;
    } else {
        node_t * tmp = queue->head;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        
        tmp-> next = newNode;
    }
    
    pthread_mutex_unlock(&queue->mutex);
} 

task_t pop(queue_t * queue) {
    pthread_mutex_lock(&queue->mutex);

    if (queue -> head == NULL) {
        perror("queue is empty");
        pthread_mutex_unlock(&queue->mutex);
        pthread_exit(NULL);
    }

    task_t task = queue->head->task;

    node_t * tmp = queue->head;
    queue->head = queue->head->next;

    free(tmp);
    pthread_mutex_unlock(&queue->mutex);
    
    return task;
}