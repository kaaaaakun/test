#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
void dup2_close_pipe(int *pipefd, int flag)
{
        dup2(pipefd[flag], flag);
        close(pipefd[0]);
        close(pipefd[1]);
}
void close_pipe(int *pipefd)
{
        close(pipefd[0]);
        close(pipefd[1]);
}

int main() {
    int pipe1[2];
    pid_t pid1, pid2, pid3;

	int stdin_fd = dup(STDOUT_FILENO);
	int stdout_fd = dup(STDIN_FILENO);

////////////////////////////一つ目
    // Create pipes
    if (pipe(pipe1) < 0)
        error_exit("pipe");

    // Fork first process
    if ((pid1 = fork()) == 0) {
        // Child process: cat
		dup2_close_pipe(pipe1, 1);
        execlp("cat", "cat", NULL);
        error_exit("execlp cat");
    }

////////////////////////////２つ目

    int pipe2[2];
    if (pipe(pipe2) < 0)
        error_exit("pipe");

    
	// Fork second process
    if ((pid2 = fork()) == 0) {
        // Child process: cat 
		dup2_close_pipe(pipe1, 0);
		dup2_close_pipe(pipe2, 1);
        execlp("cat", "cat", NULL);
        error_exit("execlp cat");
    }
		close_pipe(pipe1);

////////////////////////////////最後
 
	// Fork third process
    if ((pid3 = fork()) == 0) {
        // Child process: ls
		dup2_close_pipe(pipe1, 0);
        execlp("ls", "ls", NULL);
        error_exit("execlp ls");
    }

    // Close unused pipe ends in the parent process
    close_pipe(pipe2);

///////////////////////////////

    // Wait for each child process to finish
	write(1,"!",1);
    waitpid(-1, NULL, 0);
	write(1,"!",1);
    waitpid(-1, NULL, 0);
	write(1,"!",1);
    waitpid(-1, NULL, 0);
	write(1,"!",1);

    return 0;
}

