/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** commands
*/

#include "server.h"

static funct_t funct[] = {
    {"USER", user},
    {"PASS", password},
    {"CWD", cwd},
    {"CDUP", cdup},
    {"QUIT", quit},
    {"PORT", port},
    {"PASV", pasv},
    {"STOR", stor},
    {"RETR", retr},
    {"LIST", list},
    {"DELE", delete_file},
    {"PWD", pwd},
    {"HELP", help},
    {"NOOP", noop}
};

command_t get_commands(char *p)
{
    int i = 0;
    command_t com;

    for (i = 0; p[i] != ' ' && p[i] != '\n' && p[i] != '\r' && p[i]; i++);
    com.command = malloc(sizeof(char) * (i + 1));
    for (i = 0; p[i] != ' ' && p[i] != '\n' && p[i] != '\r' && p[i]; i++)
        com.command[i] = p[i];
    com.command[i] = '\0';
    i++;
    if (strlen(p) > (size_t)i) {
        com.body = malloc(sizeof(char) * (strlen(p) - i));
        for (int pos = i; p[pos] != '\r' && p[pos] != '\n' && p[pos]; pos++)
            com.body[pos - i] = p[pos];
        com.body[strlen(p) - i - 1] = '\0';
    } else {
        com.body = malloc(sizeof(char));
        com.body[0] = '\0';
    }
    return com;
}

connected_t send_message(connected_t com)
{
    size_t res = (size_t)write(com.fd, com.message, strlen(com.message));
    if (res != strlen(com.message))
        perror("send");
    printf("message sent to %d : %s\n", com.fd, com.message);
    if (com.username)
        if (!strcmp(com.username, "QUIT")) {
            close(com.fd);
            com.fd = 0;
            com.username = malloc(sizeof(char));
            com.username[0] = '\0';
            com.password = malloc(sizeof(char));
            com.password[0] = '\0';
            com.passif = false;
            com.connected = false;
            com = fill_cwd(com.pwd, com);
        }
    return com;
}

connected_t modify_command(char *line, connected_t com)
{
    command_t comm;
    int a = 0;

    com = fill_message("xxx Error unknown.\r\n", com);
    for (int i = 0; line[i] != '\r' && line[i]; i++)
        if (line[i] != ' ')
            a = 1;
    if (a == 0)
        com = fill_message("500 Error only spaces or empty.\r\n", com);
    else
        comm = get_commands(line);
    for (int i = 0; i <= 14 && a == 1; i++)
        if (i == 14)
            com = fill_message("500 wrong command.\r\n", com);
        else if (!strcmp(comm.command, funct[i].command)) {
            com = funct[i].ptr(comm.body, com);
            break;
        }
    return send_message(com);
}

server_t init_server_struct(server_t server, char **av)
{
    char buf[PATH_MAX];
    char *res = realpath(av[2], buf);
    if (!res || errno)
        exit(84);
    server.opt = 1;
    server.addrlen = sizeof(server.address);
    server.buffer = calloc(1024, sizeof(char));
    server.maxFd = 0;
    server.activity = 0;
    for (int i = 0; i < MAX_SIZE; i++)
        server = set_socket_struct(server, res, i);
    return server;
}

void check_errors(int ac)
{
    if (ac != 3) {
        printf("Usage: ./server [port] [path]\n");
        exit(84);
    }
}