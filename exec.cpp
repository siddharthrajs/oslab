#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};

    execv("/bin/ls", args);

    // If execv fails
    perror("execv");
    return 1;
}
