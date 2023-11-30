#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Open file
    fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write to file
    write(fd, "Hello, World!\n", 13);

    // Read from file
    lseek(fd, 0, SEEK_SET);  // Move file pointer to the beginning
    read(fd, buffer, sizeof(buffer));
    printf("Read from file: %s", buffer);

    // Close file
    close(fd);

    return 0;
}
