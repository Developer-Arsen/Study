#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define BUFFSIZE 1024
#define FILENAME "./numbers.txt"

int count = 0;
pthread_mutex_t mtx;
typedef struct {
    struct stat info;
    void * addr;
} TMP;


void read_and_write(int c,  int size , void * addr) {
    FILE * stream = fopen(FILENAME, "r+");
    fseek(stream, c, SEEK_SET);
    
    char buff[BUFFSIZE];

    for (size_t i = c; i < size;)
    {
        fgets(buff, 100, stream);
        i += strlen(buff);

        pthread_mutex_lock(&mtx);
        strcpy((char*)addr + count, buff);
        count += strlen(buff);
        pthread_mutex_unlock(&mtx);
        memset(buff, 0, strlen(buff));
    }
    fclose(stream);
}

void* startup(void * arg) {
    TMP * obj = (TMP*) arg;
    void * ptr =  obj->addr;

    pthread_mutex_lock(&mtx);
    if (count == 0) {
        count = 1;
        pthread_mutex_unlock(&mtx);
        read_and_write(0, obj->info.st_size / 2, ptr);
    } else {
        count = 0;
        pthread_mutex_unlock(&mtx);
        read_and_write(obj->info.st_size / 2, obj->info.st_size, ptr);
    }
}

int main () {
    
    struct stat info;
    stat(FILENAME, &info);    


    const char *path = "./numbers.txt";
    key_t key = ftok(path, 50);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    
    int shm_id = shmget(key, info.st_size, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmid ");
        exit(EXIT_FAILURE);
    }

    void* shm_addr = shmat(shm_id, NULL, 0);

    if (shm_addr == (char*) -1)
    {
        perror("shm addr");
        exit(EXIT_FAILURE);
    }
    
    // void * shm_addr = mmap(NULL, info.st_size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    TMP obj = {info, shm_addr};    

    pthread_mutex_init(&mtx, NULL);
    pthread_t tid[2];
    for (size_t i = 0; i < 2; i++)
    {
        pthread_create(&tid[i], NULL, startup, (void*) &obj);
    }
    
    for (size_t i = 0; i < 2; i++)
    {
        pthread_join(tid[i], NULL);
    }
   
    pthread_mutex_destroy(&mtx);

    char * a = (char *)shm_addr;
    int index  = 0;
    char buff[100];
    int i = 0;
    while (a[index])
    {
        if (a[index] == '\n' || a[index] == '\0') {
            int rep = 0;
            char * ptr = strstr(a, buff);
            if (!strstr(buff, "*")) {
                while (ptr) {
                    memset(ptr, '*', strlen(buff));
                    ptr = strstr(a, buff);
                    rep++;
                }
                printf(" %s : %d \n", buff ,rep);
            }
            memset(buff, 0, strlen(buff));
            
            i = 0;
            index++;

        } else {
            buff[i++] = a[index++];
        }
    }
}
  