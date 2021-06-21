/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** help
*/

#include "client.h"

void my_help(int sd, char *buff UNUSED, client_t *client UNUSED)
{
    char readBuff[997];
    read(sd, (char *)readBuff, 997);
    write(0, readBuff, 997);
}

int mystrcmp(char *command, char *buff)
{
    int i = 0;
    for (; command[i] && buff[i]; i++)
        if (command[i] != buff[i])
            return (1);
    if ((buff[i] != ' ' && buff[i] != '\n' && buff[i] != '\0') ||
    command[i] != '\0')
        return (1);
    return (0);
}