/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** commands
*/

#include "server.h"

void init_server_struct(server_t *server)
{
    server->opt = 1;
    server->addrlen = sizeof(server->address);
    server->buffer = calloc(1024, sizeof(char));
    server->maxFd = 0;
    server->activity = 0;
    server->users = NULL;
    for (int i = 0; i < MAX_SIZE; i++)
        set_socket_struct(server, i);
    server->fdUsers = -1;
    server->fdMessages = -1;
}