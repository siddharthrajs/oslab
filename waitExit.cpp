#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid, childPid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process\n");
        exit(0);
    } else if (pid > 0) {
        // Parent process
        childPid = wait(&status);
        printf("Parent process: Child %d terminated with status %d\n", childPid, status);
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
