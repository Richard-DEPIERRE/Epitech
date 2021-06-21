/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "client.h"

void my_subscribe(int sd, char *buff, client_t *client UNUSED)
{
    char uuid[37];
    int i = 0;
    user_t user;

    for (i = 0; buff[i] && buff[i] != 34; i++);
    if (!buff[i])
        return;
    i++;
    memset(uuid, '\0', sizeof(char)*37);
    for (int size = 0; buff[i + size] != 34 && buff[i + size]; size++) {
        uuid[size] = buff[i + size];
    }
    write(sd, uuid, sizeof(char) * 37);
    read(sd, &user, sizeof(user_t));
    if (strcmp(user.uuid, "null\0") == 0)
        client_error_unauthorized();
    else if (strcmp(user.uuid, "unknown\0") == 0)
        client_error_unknown_team(uuid);
    else
        client_print_subscribed(user.uuid, uuid);
}