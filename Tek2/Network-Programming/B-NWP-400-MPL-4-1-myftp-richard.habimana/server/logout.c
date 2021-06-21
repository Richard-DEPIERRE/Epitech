/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** logout
*/

#include "server.h"

connected_t quit(char *line, connected_t command)
{
    char *message =
    "221 Service closing control connection.\r\n";
    (void)line;
    command = fill_username("QUIT", command);
    command = fill_message(message, command);
    return command;
}