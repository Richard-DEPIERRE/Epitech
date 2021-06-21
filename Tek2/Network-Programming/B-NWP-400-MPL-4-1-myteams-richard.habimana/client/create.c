/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** creat
*/

#include "client.h"

static functCreate_t createTable[] = {
    {GLOBAL, my_create_team},
    {TEAM, my_create_channel},
    {CHANNEL, my_create_thread},
    {THREAD, my_create_reply},
};

void my_create(int sd, char *buff, client_t *client)
{
    for (int i = 0; i < 4; i++)
        if (createTable[i].use == client->use) {
            write(sd, &(client->use), sizeof(enum useType));
            createTable[i].ptr(sd, buff, client);
        }
}