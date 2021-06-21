/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** transfer
*/

#include "server.h"

connected_t port(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    (void)line;
    return command;
}

connected_t pasv(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    (void)line;
    return command;
}