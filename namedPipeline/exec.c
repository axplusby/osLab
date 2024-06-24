#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid_ls, pid_wc;
    
    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    // Fork first child process for ls -l
    pid_ls = fork();
    if (pid_ls == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid_ls == 0) {
        // Child process for ls -l
        // Close read end of the pipe
        close(pipefd[0]);
        
        // Redirect stdout to write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        // Execute ls -l
        execlp("ls", "ls", "-l", NULL);
        
        // If execlp fails
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }
    
    // Fork second child process for wc -l
    pid_wc = fork();
    if (pid_wc == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid_wc == 0) {
        // Child process for wc -l
        // Close write end of the pipe
        close(pipefd[1]);
        
        // Redirect stdin to read end of the pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        
        // Execute wc -l
        execlp("wc", "wc", "-l", NULL);
        
        // If execlp fails
        perror("execlp wc");
        exit(EXIT_FAILURE);
    }
    
    // Parent process closes both ends of the pipe
    close(pipefd[0]);
    close(pipefd[1]);
    
    // Wait for both children to complete
    waitpid(pid_ls, NULL, 0);
    waitpid(pid_wc, NULL, 0);
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        // Close write end of the pipe
        close(pipefd[1]);

        // Redirect stdin to read end of the pipe
        if (dup2(pipefd[0], STDIN_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(pipefd[0]);

        // Execute wc -l
        execlp("wc", "wc", "-l", NULL);

        // If execlp fails
        perror("execlp wc");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Close read end of the pipe
        close(pipefd[0]);

        // Redirect stdout to write end of the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(pipefd[1]);

        // Execute ls -l
        execlp("ls", "ls", "-l", NULL);

        // If execlp fails
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    // Wait for child process to complete
    waitpid(pid, NULL, 0);

    return 0;
}
*/
