/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** server
*/

#include "server.h"

void end_server(server_t *server)
{
    for (server->i = 0; server->i < MAX_SIZE; server->i++)
        if (server->sockerFdNew[server->i].fd != 0)
            write(server->sockerFdNew[server->i].fd, "/quit\n", 6);
    for (node_t *tmp = NULL; server->users;) {
        tmp = server->users;
        server->users = server->users->next;
        free(tmp);
    }
    destruct_server();
    exit(0);
}

server_t *return_int(int check, server_t *serv)
{
    static server_t *server;
    if (check == 2)
        server = serv;
    if (check == 1)
        end_server(server);
    return (server);
}

void int_handler(int res UNUSED)
{
    return_int(1, NULL);
}

int main(int ac, char **av)
{
    server_t *server = malloc(sizeof(server_t));
    user_t buffUser;
    int fd = open("db/users.db", O_RDONLY | O_APPEND);
    char recvBuf[1024] = {0};

    signal(SIGINT, int_handler);
    check_errors(ac);
    init_server_struct(server);
    init_server(server, av);
    return_int(2, server);
    while (read(fd, &buffUser, sizeof(user_t)) > 0)
        server_event_user_loaded(buffUser.uuid, buffUser.username);
    close(fd);
    while (1)
        loop(server, recvBuf);
    end_server(server);
    return (0);
}