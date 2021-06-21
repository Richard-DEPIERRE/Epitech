/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** misc
*/

#include "server.h"

server_t fill_buffer(server_t server)
{
    server.tmp = malloc(sizeof(char) * (strlen(server.buffer) + 1));
    for (int i = 0; server.buffer[i]; i++)
        server.tmp[i] = server.buffer[i];
    server.tmp[strlen(server.buffer)] = '\0';
    server.buffer = malloc(sizeof(char) * (strlen(server.tmp) +
    strlen(server.buff) + 1));
    for (int i = 0; server.tmp[i]; i++)
        server.buffer[i] = server.tmp[i];
    for (int i = 0; server.buff[i]; i++)
        server.buffer[strlen(server.tmp) + i] = server.buff[i];
    server.buffer[strlen(server.tmp) + strlen(server.buff)] = '\0';
    return (server);
}

server_t read_file(server_t server)
{
    for (int i = 0; server.buff[i + 1]; i++)
        if (server.buff[i] == '\r' && server.buff[i+1] == '\n') {
            server.finish = 1;
            break;
        }
    if (server.buffer)
        server = fill_buffer(server);
    else {
        server.buffer = malloc(sizeof(char) * (strlen(server.buff) + 1));
        for (int i = 0; server.buff[i]; i++)
            server.buffer[i] = server.buff[i];
        server.buffer[strlen(server.buff)] = '\0';
    }
    return (server);
}

void close_fd(server_t *server, int pos)
{
    getpeername(server->sd, (struct sockaddr *)&server->address,
    (socklen_t *)&server->addrlen);
    close(server->sd);
    server->sockerFdNew[pos].fd = 0;
}

void set_socket_struct(server_t *server, int i)
{
    server->sockerFdNew[i].fd = 0;
    server->sockerFdNew[i].username = NULL;
    server->sockerFdNew[i].passif = false;
    server->sockerFdNew[i].connected = false;
}

void send_end_to_everyone(server_t *s, int sd, node_t *res)
{
    for (node_t *tmp = s->users; tmp != NULL; tmp = tmp->next)
        if (tmp->user.status == 1 && tmp->user.fd != sd) {
            write(tmp->user.fd, "disconnect\n\0", 12);
            usleep(1000);
            write(tmp->user.fd, &(res->user), sizeof(user_t));
        }
}