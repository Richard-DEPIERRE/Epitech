/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "server.h"

void send_length_users(user_t user, int sd)
{
    int fdLink = open_db("db/links.db", "Can’t open Links database\n\0");
    int num = 0;
    link_t link;

    while (read(fdLink, &link, sizeof(link_t)) > 0)
        if (strcmp(link.user_uuid, user.uuid) == 0)
            num++;
    write(sd, &num, sizeof(int));
    close(fdLink);
}

void send_length(int a, user_t user, int sd, team_t team)
{
    int num = 0;
    int fdLink = 0;
    link_t link;

    if (a == 0)
        return (send_length_users(user, sd));
    fdLink = open_db("db/links.db", "Can’t open Links database\n\0");
    while (read(fdLink, &link, sizeof(link_t)) > 0)
        if (strcmp(link.team_uuid, team.uuid) == 0 &&
        strcmp(link.user_uuid, user.uuid) == 0)
            num++;
    write(sd, &num, sizeof(int));
    return;
}