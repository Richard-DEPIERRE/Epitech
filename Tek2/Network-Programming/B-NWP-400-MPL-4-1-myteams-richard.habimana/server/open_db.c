/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** open_db
*/

#include "server.h"

int open_db(char *path, char *writing)
{
    int fdUser = open(path, O_RDWR | O_APPEND |
    O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (fdUser == -1) {
        write(2, writing, strlen(writing));
        exit(84);
    }
    return (fdUser);
}