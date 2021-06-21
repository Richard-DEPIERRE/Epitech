/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** server
*/

#include "server.h"

server_t init_fd(server_t server)
{
    FD_ZERO(&server.read_fd_set);
    FD_SET(server.server_fd, &server.read_fd_set);
    server.maxFd = server.server_fd;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (server.sockerFdNew[i].fd > 0)
            FD_SET(server.sockerFdNew[i].fd, &server.read_fd_set);
        if (server.sockerFdNew[i].fd > server.server_fd)
            server.maxFd = server.sockerFdNew[i].fd;
    }
    server.activity = select(server.maxFd + 1,
    &server.read_fd_set, NULL, NULL, NULL);
    if (server.activity < 0 && errno != EINTR) {
        perror("select error");
        exit(84);
    }
    return server;
}

server_t accept_new_connection(server_t server)
{
    int new = accept(server.server_fd, (struct sockaddr *)&server.address,
    (socklen_t *)&server.addrlen);
    char *message = "220 Service ready for new user.\r\n";

    if (new < 0) {
        perror("accept");
        exit(84);
    }
    if ((size_t)write(new, message, strlen(message)) != strlen(message))
        perror("send");
    printf("Welcome Message Sent");
    for (int i = 0; i < MAX_SIZE; i++)
        if (server.sockerFdNew[i].fd == 0) {
            server.sockerFdNew[i].fd = new;
            printf("Adding to list socket[%d] : %d\n", i, new);
            break;
        }
    return server;
}

server_t core_server_two(server_t server, int sd, int pos)
{
    while (read(sd, server.buff, 1024) != 0) {
        server = read_file(server);
        if (server.finish == 1)
            break;
    }
    if (server.valread == 0 && server.finish == 0)
        server = close_fd(server, pos);
    else
        server.sockerFdNew[pos] = modify_command(server.buffer,
        server.sockerFdNew[pos]);
    free(server.buffer);
    server.buffer = NULL;
    return server;
}

server_t core_server(server_t server, int sd, int pos)
{
    server.buff = calloc(1024, sizeof(char));
    server.tmp = NULL;
    server.finish = 0;
    if (FD_ISSET(sd, &server.read_fd_set))
        server = core_server_two(server, sd, pos);
    return server;
}

int main(int ac, char **av)
{
    server_t server;

    check_errors(ac);
    server = init_server_struct(server, av);
    server = init_server(server, av);
    while (1) {
        server = init_fd(server);
        if (FD_ISSET (server.server_fd, &server.read_fd_set)) {
            server = accept_new_connection(server);
        }
        for (server.i = 0; server.i < MAX_SIZE; server.i++) {
            server.sd = server.sockerFdNew[server.i].fd;
            server = core_server(server, server.sd, server.i);
        }
    }
    return 0;
}