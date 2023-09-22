#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int pipe1[2];
    int pipe2[2];
    pid_t pid1, pid2, pid3;

    // Create pipes
    if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
        error_exit("pipe");

    // Fork first process
    if ((pid1 = fork()) == 0) {
        // Child process: cat
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("cat", "cat", NULL);
        error_exit("execlp cat");
    }

    // Fork second process
    if ((pid2 = fork()) == 0) {
        // Child process: cat
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("cat", "cat", NULL);
        error_exit("execlp cat");
    }

    // Fork third process
    if ((pid3 = fork()) == 0) {
        // Child process: ls
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("ls", "ls", NULL);
        error_exit("execlp ls");
    }

    // Close unused pipe ends in the parent process
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // Wait for each child process to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}

