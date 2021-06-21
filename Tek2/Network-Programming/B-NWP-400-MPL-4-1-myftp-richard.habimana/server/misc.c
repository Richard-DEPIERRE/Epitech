/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** misc
*/

#include "server.h"

connected_t noop(char *line, connected_t command)
{
    (void)line;
    command.message = calloc(strlen("200 Command okay.\r\n") + 1,
    sizeof(char));
    strcpy(command.message, "200 Command okay.\r\n");
    return command;
}

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
    return server;
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
    return server;
}

server_t close_fd(server_t server, int pos)
{
    char *ip = inet_ntoa(server.address.sin_addr);
    int port = ntohs(server.address.sin_port);
    getpeername(server.sd, (struct sockaddr *)&server.address,
    (socklen_t *)&server.addrlen);
    printf("Client disconnected\nip : <%s>   port : <%d>\n",
    ip, port);
    close(server.sd);
    server.sockerFdNew[pos].fd = 0;
    return server;
}

server_t set_socket_struct(server_t server, char *res, int i)
{
    server.sockerFdNew[i].fd = 0;
    server.sockerFdNew[i].username = NULL;
    server.sockerFdNew[i].password = NULL;
    server.sockerFdNew[i].passif = false;
    server.sockerFdNew[i].connected = false;
    server.sockerFdNew[i].cwd = malloc(sizeof(char) * (strlen(res) + 1));
    for (int a = 0; a < (int)strlen(res); a++)
        server.sockerFdNew[i].cwd[a] = res[a];
    server.sockerFdNew[i].cwd[strlen(res)] = '\0';
    server.sockerFdNew[i].pwd = malloc(sizeof(char) * (strlen(res) + 1));
    for (int a = 0; a < (int)strlen(res); a++)
        server.sockerFdNew[i].pwd[a] = res[a];
    server.sockerFdNew[i].pwd[strlen(res)] = '\0';
    return server;
}