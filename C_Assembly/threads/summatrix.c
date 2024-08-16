#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


struct Tmp {
    int ** arr;
    int sum;
} typedef  Tmp;

pthread_mutex_t imutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t jmutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t incMutex;

int n = 0;
static int threadI = 0;
static int threadJ = 0;
static int flag = 0;

void zero(ZeroEvenOdd* obj) {
    for (int i = 1 ; i <= obj->n; i++) {
        pthread_mutex_lock(&mtx);

        while (flag != 0) {
            pthread_cond_wait(&cond, &mtx);
        }

        int x = 0;
        printNumber(x);
        flag = 1;

        if (i % 2 == 0) {
            isOdd = 2;
        }
        else {
            isOdd = 1;
        }
        
        pthread_mutex_unlock(&mtx);
        pthread_cond_broadcast(&cond);
    }
}

void even(ZeroEvenOdd* obj) {
    while (number <= obj-> n) {

        pthread_mutex_lock(&mtx);

        while (flag == 0 || isOdd == 1) {
            pthread_cond_wait(&cond, &mtx);
        }
        
        printNumber(number);
        number++;
        flag = 0;

        pthread_mutex_unlock(&mtx);
        pthread_cond_broadcast(&cond);
    }    
}

void odd(ZeroEvenOdd* obj) {
    while (number <= obj-> n) {
        pthread_mutex_lock(&mtx);

        while (flag == 1 || isOdd == 2) {
            pthread_cond_wait(&cond, &mtx);
        }
        
        printNumber(number);
        number++;
        flag = 0;

        pthread_mutex_unlock(&mtx);
        pthread_cond_broadcast(&cond);
    }   
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    free(obj);
}




void * addSum(void * arg) {
    Tmp * obj = (Tmp*) arg;
    int ** arr = obj->arr;
    for (; threadI < n; threadI++)
    {
        pthread_mutex_lock(&imutex);
        

        for (;threadJ < n; threadJ++)
        {
            // pthread_mutex_lock(&incMutex);
            // pthread_mutex_lock(&jmutex);
            
            obj->sum += arr[threadI][threadJ];
            // pthread_mutex_unlock(&jmutex);
            
            // pthread_mutex_unlock(&incMutex);
        }

        pthread_mutex_unlock(&imutex);
        
    }

}


int main () {
    scanf("%d", &n);

    int ** arr = (int**) malloc(sizeof(int*) * n);

    int inc = 0;
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = (int*) malloc(sizeof(int) * n);
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            arr[i][j] = inc++;
        }
    }

    Tmp* obj = (Tmp*) malloc(sizeof(Tmp));
    obj->arr = arr;
    obj->sum = 0;
    

    pthread_mutex_init(&incMutex, NULL);
    void * sum = 0;
    pthread_t thread1, thread2;
    int s = pthread_create(&thread1, NULL, addSum, (void*)obj);
    if (s > 0) {
        perror("error");
        exit(EXIT_FAILURE);
    }
    
    s = pthread_create(&thread2, NULL, addSum, (void*)obj);
    if (s > 0) {
        perror("error");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_destroy(&incMutex);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("%d", obj->sum);

    // for (size_t i = 0; i < n; i++)
    // {
    //     for (size_t j = 0; j < n; j++)
    //     {
    //         printf("%d \t", arr[i][j]);
    //         sum += arr[i][j];
    //     }
    //     printf("\n");
    // }

    




    

}