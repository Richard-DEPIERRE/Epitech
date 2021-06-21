/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "client.h"

void my_unsubscribe_two(int sd, char uuid[37])
{
    link_t link;

    read(sd, &link, sizeof(link_t));
    if (strcmp(link.user_uuid, "null\n\0") == 0) {
        client_error_unauthorized();
        return;
    }
    if (strcmp(link.user_uuid, "unknown\n\0") == 0) {
        client_error_unknown_team(uuid);
        return;
    }
    client_print_unsubscribed(link.user_uuid, link.team_uuid);
}

void my_unsubscribe(int sd, char *buff, client_t *client UNUSED)
{
    char uuid[37];
    int i = 0;

    for (i = 0; buff[i] && buff[i] != 34; i++);
    i++;
    memset(uuid, '\0', sizeof(char)*37);
    for (int size = 0; buff[i + size] != 34 && buff[i + size]; size++) {
        uuid[size] = buff[i + size];
    }
    write(sd, uuid, 37);
    my_unsubscribe_two(sd, uuid);
}