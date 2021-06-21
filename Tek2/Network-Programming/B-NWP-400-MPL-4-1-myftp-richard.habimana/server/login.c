/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** login
*/

#include "server.h"

connected_t user(char *line, connected_t command)
{
    char *message = "331 Service ready for new user.\r\n";
    if (!command.username) {
        if (!command.password) {
            command = fill_username(line, command);
            command = fill_message(message, command);
        } else if (command.password && !strcmp(line, "Anonymous")) {
            command = fill_username(line, command);
            command =
            fill_message("230 User logged in, proceed.\r\n", command);
            command.connected = true;
        } else if (command.password)
            command = fill_message("xxx Error (RFC compliant)\r\n", command);
    } else
        command = fill_message("xxx Error (RFC compliant)\r\n", command);
    return command;
}

connected_t password(char *line, connected_t command)
{
    if (command.password)
        return fill_message("xxx Error (RFC compliant)\r\n", command);
    if (!command.username) {
        if (strlen(line) != 0)
            command = fill_password(line, command);
        else
            command = fill_password("\0", command);
        command = fill_message("332 Need account for login.\r\n", command);
    } else if (strcmp(command.username, "Anonymous") == 0) {
        if (strlen(line) != 0)
            command = fill_password(line, command);
        else
            command = fill_password("\0", command);
        command = fill_message("230 User logged in, proceed.\r\n", command);
        command.connected = true;
    } else
        command = fill_message("530 Error wrong login\r\n", command);
    return command;
}

char *get_correct_path(char *line, connected_t command)
{
    char *res = malloc(sizeof(char) *
    (strlen(command.cwd) + strlen(line) + 2));
    int i = 0;

    for (; command.cwd[i]; i++)
        res[i] = command.cwd[i];
    res[i++] = '/';
    for (int a = i; line[i - a]; i++)
        res[i] = line[i - a];
    res[i] = '\0';
    return res;
}

connected_t cwd(char *line, connected_t command)
{
    char *message = "250 Requested file action okay, completed.\r\n";
    char *res = get_correct_path(line, command);

    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    if (chdir(res) == -1)
        command = fill_message("550 Error wrong directory\r\n", command);
    else {
        command = fill_cwd(res, command);
        command = fill_message(message, command);
    }
    return command;
}

connected_t cdup(char *line, connected_t command)
{
    if (command.connected == false) {
        command = fill_message("530 Authentification required.\r\n", command);
        return command;
    }
    char *message = "250 Requested file action okay, completed.\r\n";
    (void)line;
    command = fill_cwd(command.pwd, command);
    command = fill_message(message, command);
    return command;
}