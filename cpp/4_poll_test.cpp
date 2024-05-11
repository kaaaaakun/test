#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow multiple connections
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the given address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct pollfd fds[MAX_CLIENTS + 1];
    memset(fds, 0, sizeof(fds));

    // Add server socket to the poll descriptor set
    fds[0].fd = server_fd;
    fds[0].events = POLLIN;

    std::cout << "Server started. Listening on port " << PORT << std::endl;

    while(true) {
        // Poll for events
        int activity = poll(fds, MAX_CLIENTS + 1, -1);
        if (activity < 0) {
            perror("poll");
            exit(EXIT_FAILURE);
        }

        // If server socket has incoming connection
        if (fds[0].revents & POLLIN) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            std::cout << "New connection, socket fd is " << new_socket << ", ip is : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port) << std::endl;

            // Add new socket to poll descriptor set
            for (int i = 1; i <= MAX_CLIENTS; ++i) {
                if (fds[i].fd == 0) {
                    fds[i].fd = new_socket;
                    fds[i].events = POLLIN;
                    break;
                }
            }
        }

        // Check for data from clients
        for (int i = 1; i <= MAX_CLIENTS; ++i) {
            if (fds[i].revents & POLLIN) {
                valread = read(fds[i].fd, buffer, 1024);
                if (valread == 0) {
                    // Client disconnected
                    close(fds[i].fd);
                    fds[i].fd = 0;
                } else {
                    // Echo message back to client
                    send(fds[i].fd, buffer, valread, 0);
                }
            }
        }
    }

    return 0;
}
