#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define SHM_SIZE 100
int main() {
    const char *path = "./file1.txt";
    int proj_id = 3;
    key_t key = ftok(path, proj_id);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    // ssize_t bytes_read = read(fd, shmaddr, SHM_SIZE - 1);
    // if (bytes_read == -1) {
    //     perror("read");
    //     exit(EXIT_FAILURE);
    // }
    // shmaddr[bytes_read] = '\0';
    scanf("%s", shmaddr);
    close(fd);
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
    shmdt(shmaddr);
    return 0;
}
