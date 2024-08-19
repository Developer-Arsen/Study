#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

#define MAX_BUF_SIZE 1024

int get_pid_by_name(const char *pname) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_BUF_SIZE];
    char cmd[MAX_BUF_SIZE];
    FILE *fp;
    int pid = -1;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && sscanf(entry->d_name, "%d", &pid) == 1) {
            snprintf(path, sizeof(path), "/proc/%s/cmdline", entry->d_name);
            fp = fopen(path, "r");
            if (fp) {
                if (fgets(cmd, sizeof(cmd), fp) != NULL) {
                    if (strcmp(pname, cmd) == 0) {
                        closedir(dir);
                        fclose(fp);
                        return pid;
                    }
                }
                fclose(fp);
            }
        }
    }
    closedir(dir);
    return -1; 
}

int main() {
    const char *process_name = "./a.out";
    int pid = get_pid_by_name(process_name);
    
    if (pid != -1) {
        printf("PID of process '%s' is %d\n", process_name, pid);
    } else {
        printf("Process '%s' not found\n", process_name);
    }

    kill(pid, 10);
    
    return 0;
}
