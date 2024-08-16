#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    FILE *stream;
    pid_t pid = fork();

    if (pid == 0) { // Child process
        // Use popen to run "ls" and read its output
        stream = popen("ls", "r");
        if (stream == NULL) {
            perror("popen ls");
            exit(EXIT_FAILURE);
        }

        
        exit(EXIT_SUCCESS);
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for the child process to finish
        char buffer[256];
        FILE *wcStream = popen("wc", "w");
        if (wcStream == NULL) {
            perror("popen wc");
            exit(EXIT_FAILURE);
        }

        // Read from the ls output and write to wc input
        while (fgets(buffer, sizeof(buffer), stream) != NULL) {
            fputs(buffer, wcStream);
        }

        // Close the streams
        pclose(stream);
        pclose(wcStream);

    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
