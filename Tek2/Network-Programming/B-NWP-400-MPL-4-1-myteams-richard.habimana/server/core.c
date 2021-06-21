/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** core
*/

#include "server.h"

static functServer_t functServer[] = {
    {HELP, my_help},
    {LOGIN, my_login},
    {LOGOUT, my_logout},
    {USERS, my_users},
    {USER, my_user},
    {SEND, my_send},
    {MESSAGES, my_messages},
    {CREATE, my_create},
    {LIST, my_list},
    {USE, my_use},
    {SUBSCRIBE, my_subscribe},
    {SUBSCRIBED, my_subscribed},
    {UNSUBSCRIBE, my_unsubscribe},
    {INFO, my_info}
};

void check_errors(int ac)
{
    if (ac != 2) {
        printf("Usage: ./myteams_server [port]\n");
        exit(84);
    }
}

void accept_new_connection(server_t *server)
{
    int new = accept(server->server_fd, (struct sockaddr *)&server->address,
    (socklen_t *)&server->addrlen);

    if (new < 0) {
        perror("accept");
        exit(84);
    }
    for (int i = 0; i < MAX_SIZE; i++)
        if (server->sockerFdNew[i].fd == 0) {
            server->sockerFdNew[i].fd = new;
            break;
        }
}

void core_server_two(server_t *server, int sd, int pos)
{
    enum command type = UNKNOWN;
    server->valread = read(sd, &type, sizeof(enum command));
    if (server->valread == 0) {
        close_fd(server, pos);
        return;
    }
    for (int i = 0; i < 14; i++) {
        if (functServer[i].received == type) {
            functServer[i].ptr(server, sd);
        }
    }
}

void core_server(server_t *server, int sd, int pos)
{
    server->buff = calloc(1024, sizeof(char));
    server->tmp = NULL;
    server->finish = 0;
    if (FD_ISSET(sd, &server->read_fd_set))
        core_server_two(server, sd, pos);
}