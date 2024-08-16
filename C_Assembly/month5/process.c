#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <string.h>
#include <sys/signal.h>

// incha process y an instance of a program being in execution called process
// PCB -ira andamnery 
// user-id neri tesaknery effective, real , file, 

// user neri tesaknery {
//     real-id : pahuma ira mej ova stexcel file y
//     effecitve-id : ova ashxatacnum hima
//     saved-id : amen exec hramanic heto stex pahuma real-id
//     file-id : nuyn real-id na file eri het ashxatanqi hamara 
// }


// members of PCB - task struct 
// process states  TASK_RUN stopped traced

// PROCESS i vichaknery states of the project
// TASK_RUNNING: The process is runnable; it is either running or ready to run.
// TASK_INTERRUPTIBLE: The process is sleeping (waiting for some condition to become true) and will wake up if it receives a signal.
// TASK_UNINTERRUPTIBLE: The process is sleeping and does not wake up on receiving a signal (typically used when waiting for I/O operations).
// TASK_STOPPED: Process execution has been stopped; the process is not running.
// TASK_TRACED: The process is being traced by another process such as a debugger.
// TASK_DEAD: The process is about to be destroyed.
// TASK_ZOMBIE: Process has died and is waiting for its parent to retrieve its exit status.

struct task_struct {
    volatile long state; // processi vichaky
    int prio; // process i priorityin
    int stat_prio; // static prion
    int normal_prio; // normal prion
    unsigned int rt_priority; // round robin prion
    struct task_struct__rcu *  parent; // ira himikva parenty
    struct task_struct__rcu * real_parent; // ira irakan cnoxy
    struct task_struct * group_leader; // process i group leader y
    struct list_head * sibling; // process i qur y kam axpery
    struct list_head * child; // process i erexen
    pid_t pid; // process id
    pid_t tgid; // thread group id
    uid_t uid, ueid, suid, fsuid; // user -real id, user effective id, saved user id, file-saved user id
    gid_t guid, geuid, gsuid, gfsuid; //group user
    struct group_info * group; // parunakuma info te process y inch group neri meja 
    struct user_struct* user; // parunakuma info user i masin te inchqan process ner u thread nera user y bacel u inchqan hnaravrutyun uni der bacelu, nayev useri permisson neri het kapvac info ner en pahvum, blockavorvac shared memory chapsy, qani hat pending signal ka hima
};

extern char ** environ;

void atexit_handler(void) {
    printf("atexit handler: No parameters passed\n");
}

void on_exit_handler(int status, void *arg) {
    printf("on_exit handler: Exit status %d, Arg value: %s\n", status, (char *)arg);
}

void handleusr1 () {
    puts("in child");
}

int main () {
    // atexit(atexit_handler);
    // on_exit(on_exit_handler, "some text");
    // exit(0);

    pid_t pid = getpid();
    gid_t gid = getgid();
    pid_t ppid = getppid();
    // printf("Pid is : %d  group id is: %d   parent pid is: %d  \n", pid, gid, ppid);
    
    char * anun = "inchvorbar";
    char * arjeq = "Hello, World!";
    
    setenv(anun, arjeq, 0);
    unsetenv(anun);
    // printf("%s \n", getenv(anun));

    char ** env = environ;

    while(*env) {
        // printf("%s \n", *env);
        env++;
    }
    

    pid = fork(); 
    if (pid == 0) {
        // execl("/bin/ls", "ls", "-l", NULL);
        // execlp("ls", "ls", "-l", NULL);
        // execle("/bin/ls", "ls", "-l", NULL, env);

        // char * const args[3] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);
        // execvp("ls", args);
        // execve("/bin/ls", args, env);
        signal(SIGUSR1, handleusr1);

        printf("from child   %d \n", getpid());
        pause();
        exit(100);
    } 
    else {
        int status;
        kill(pid, SIGUSR1);
        wait(&status);

        if (WIFEXITED(status)) {
            printf("from parent child exit status is %d \n", WEXITSTATUS(status));
        }

        if (WIFSIGNALED(status) && WIFSTOPPED(status)) {
            printf("from parent child stopped by signal status is %d \n", WSTOPSIG(status));
        }

        if (WIFSIGNALED(status)) {
            printf("from parent child signaled by signal status is %d \n", WTERMSIG(status));
        }

        if (WIFCONTINUED(status)) {
            printf("from parent child signaled by signal status is %d \n", WTERMSIG(status));
        }


    }

    return 0;

}






