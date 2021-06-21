/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create
*/

#include "server.h"

static functCreate_t createTable[] = {
    {GLOBAL, my_create_team},
    {TEAM, my_create_channel},
    {CHANNEL, my_create_thread},
    {THREAD, my_create_reply},
};

void my_create(server_t *server, int sd)
{
    enum useType use;

    read(sd, &use, sizeof(enum useType));
    for (int i = 0; i < 4; i++)
        if (createTable[i].use == use)
            createTable[i].ptr(server, sd);
}