/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** fill
*/

#include "server.h"

connected_t fill_message(char *message, connected_t command)
{
    command.message = calloc(strlen(message) + 1, sizeof(char));
    strcpy(command.message, message);
    return command;
}

connected_t fill_password(char *password, connected_t command)
{
    command.password = calloc(strlen(password) + 1, sizeof(char));
    strcpy(command.password, password);
    return command;
}

connected_t fill_username(char *user, connected_t command)
{
    command.username = calloc(strlen(user) + 1, sizeof(char));
    strcpy(command.username, user);
    return command;
}

connected_t fill_cwd(char *cwd, connected_t command)
{
    command.cwd = calloc(strlen(cwd) + 1, sizeof(char));
    strcpy(command.cwd, cwd);
    return command;
}