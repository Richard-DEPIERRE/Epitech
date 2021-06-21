/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** fill
*/

#include "server.h"

connected_t fill_username(char *user, connected_t command)
{
    command.username = calloc(strlen(user) + 1, sizeof(char));
    strcpy(command.username, user);
    return (command);
}
