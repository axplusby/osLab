#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define FIFO_NAME "myfifo"

int main() 
{
    // Create the FIFO (named pipe)
    if (mkfifo(FIFO_NAME, 0666) == -1) 
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) 
    { // Child process
        // Open the FIFO for writing
        int fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) 
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Redirect standard output to the FIFO
        if (dup2(fd, STDOUT_FILENO) == -1) 
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(fd);

        // Execute the "ls -l" command
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);

    } 
    else 
    { // Parent process
        // Open the FIFO for reading
        int fd = open(FIFO_NAME, O_RDONLY);
        if (fd == -1) 
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Redirect standard input to the FIFO
        if (dup2(fd, STDIN_FILENO) == -1) 
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(fd);

        // Execute the "wc -l" command
        execlp("wc", "wc", "-l", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Wait for the child process to finish
    wait(NULL);

    // Remove the FIFO
    unlink(FIFO_NAME);

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    int fd;
    char buf[256];
    struct stat st;

    // Check if the FIFO exists
    if (stat(FIFO_NAME, &st) == 0) {
        printf("FIFO already exists: %s\n", FIFO_NAME);
    } else {
        // Create the FIFO (named pipe)
        if (mkfifo(FIFO_NAME, 0666) == -1) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }

        printf("Created FIFO: %s\n", FIFO_NAME);
    }

    // Open the FIFO for reading and writing
    fd = open(FIFO_NAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Writing to FIFO...\n");
    strcpy(buf, "Hello, FIFO!");
    write(fd, buf, strlen(buf) + 1);

    printf("Reading from FIFO...\n");
    memset(buf, 0, sizeof(buf));
    read(fd, buf, sizeof(buf));
    printf("Received: %s\n", buf);

    close(fd);

    // Remove the FIFO
    if (unlink(FIFO_NAME) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}
*/