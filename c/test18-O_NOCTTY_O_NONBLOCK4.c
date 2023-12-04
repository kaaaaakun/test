#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_fd = open("test.txt", O_RDWR);
    if (file_fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // パイプを作成
    int pipe_fds[2];
    pipe(pipe_fds);
    
        char buffer[1024];
        ssize_t bytesRead;

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        dup2(pipe_fds[0], STDIN_FILENO);
        // パイプの読み取り側は不要
        close(pipe_fds[1]);

        while ((bytesRead = read(file_fd, buffer, sizeof(buffer))) > 0)
            write(file_fd, buffer, bytesRead);
    }
    else
    {
        while ((bytesRead = read(file_fd, buffer, sizeof(buffer))) > 0)
            write(STDOUT_FILENO, buffer, bytesRead);

        close(file_fd);
    }
//    else
//    {
//        // Parent process
//        char buffer[1024];
//        ssize_t bytesRead;
//
//        while ((bytesRead = read(file_fd, buffer, sizeof(buffer))) > 0) {
//            write(STDOUT_FILENO, buffer, bytesRead);
//        }
//
//        close(file_fd);
//    }

    return 0;
}

