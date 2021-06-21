/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** info
*/

#include "server.h"

connected_t help(char *line, connected_t command)
{
    (void)line;
    char *message =
    "214 USER PASS CWD CDUP QUIT DELE PWD PASV PORT"
    " HELP NOOP RETR STOR LIST \r\n";
    command.message = calloc(strlen(message) + 1, sizeof(char));
    strcpy(command.message, message);
    return command;
}