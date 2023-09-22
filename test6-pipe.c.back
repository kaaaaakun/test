#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command1> [<args>] | <command2> [<args>] | ...\n", argv[0]);
        return 1;
    }

    int num_pipes = argc - 1;
    int pipes[num_pipes - 1][2];

    // Create pipes
    for (int i = 0; i < num_pipes - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Pipe creation failed");
            return 1;
        }
    }

    for (int i = 0; i < num_pipes; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            return 1;
        }

        if (pid == 0) {
            // Child process
            if (i > 0) {
                // Redirect input from the previous pipe
                dup2(pipes[i - 1][0], STDIN_FILENO);
                close(pipes[i - 1][0]);
                close(pipes[i - 1][1]);
            }

            if (i < num_pipes - 1) {
                // Redirect output to the next pipe
                dup2(pipes[i][1], STDOUT_FILENO);
                close(pipes[i][0]);
                close(pipes[i][1]);
            }

            execlp(argv[i + 1], argv[i + 1], NULL);
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipes in the parent process
    for (int i = 0; i < num_pipes - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_pipes; i++) {
        wait(NULL);
    }

    return 0;
}

