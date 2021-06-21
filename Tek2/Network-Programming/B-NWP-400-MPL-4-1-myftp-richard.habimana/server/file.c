/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** file
*/

#include "server.h"

connected_t stor(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    (void)line;
    return command;
}

connected_t retr(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    (void)line;
    return command;
}

connected_t list(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    (void)line;
    return command;
}

connected_t delete_file(char *line, connected_t command)
{
    char *res = NULL;
    int i = 0;

    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    res = malloc(sizeof(char) * (strlen(command.cwd) + strlen(line) + 2));
    for (; command.cwd[i]; i++)
        res[i] = command.cwd[i];
    res[i++] = '/';
    for (int a = i; line[i - a]; i++)
        res[i] = line[i - a];
    res[i] = '\0';
    if (remove(res) == 0)
        command = fill_message("250 Requested file action okay.\r\n", command);
    else
        command = fill_message("550 File does not exist.\r\n", command);
    return command;
}

connected_t pwd(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    (void)line;
    char *res = malloc(sizeof(char) * (strlen(command.cwd) + 7));
    res[sizeof(command.cwd)] = '\0';
    res[0] = '2';
    res[1] = '5';
    res[2] = '7';
    res[3] = ' ';
    for (int i = 4; i < (int)strlen(command.cwd) + 4; i++)
        res[i] = command.cwd[i - 4];
    res[strlen(command.cwd) + 4] = '\r';
    res[strlen(command.cwd) + 5] = '\n';
    res[strlen(command.cwd) + 6] = '\0';
    command = fill_message(res, command);
    return command;
}