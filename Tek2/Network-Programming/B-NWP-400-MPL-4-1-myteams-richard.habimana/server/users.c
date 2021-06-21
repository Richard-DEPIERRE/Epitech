/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** users
*/

#include "server.h"

void get_number(int sd)
{
    int fd = open("db/users.db", O_RDONLY | O_APPEND);
    user_t buffUser;
    int num = 0;

    for (num = 0; read(fd, &buffUser, sizeof(user_t)) > 0; num++);
    write(sd, &num, sizeof(int));
    close(fd);
}

void my_users(server_t *server UNUSED, int sd)
{
    int fd = open("db/users.db", O_RDONLY | O_APPEND);
    user_t buffUser;
    int error = -1;

    if (check_connect(server->users, &error, sizeof(int), sd) == 1)
        return;
    get_number(sd);
    while (read(fd, &buffUser, sizeof(user_t)) > 0)
        write(sd, &buffUser, sizeof(user_t));
    close(fd);
}

void my_user(server_t *server, int sd)
{
    int fd = 0;
    user_t buffUser;
    user_t error;
    char uuid[37] = {0};

    strcpy(error.uuid, "null\0");
    if (check_connect(server->users, &error, sizeof(user_t), sd) == 1)
        return;
    read(sd, uuid, 37);
    fd = open("db/users.db", O_RDONLY | O_APPEND);
    while (read(fd, &buffUser, sizeof(user_t)) > 0) {
        if (strcmp(buffUser.uuid, uuid) == 0) {
            write(sd, &buffUser, sizeof(user_t));
            return;
        }
    }
    strcpy(error.uuid, "unknown\0");
    write(sd, &error, sizeof(user_t));
    close(fd);
}
