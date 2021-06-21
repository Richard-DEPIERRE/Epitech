/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "client.h"

static functList_t listTable[] = {
    {GLOBAL, my_info_team},
    {TEAM, my_info_channel},
    {CHANNEL, my_info_thread},
    {THREAD, my_info_reply},
};

void my_info_reply(int sd, client_t *client)
{
    thread_t thread;
    info_t info;

    strcpy(info.uuidTeam, client->teamuuid);
    strcpy(info.uuidChannel, client->channeluuid);
    strcpy(info.uuidThread, client->threaduuid);
    write(sd, &info, sizeof(info_t));
    read(sd, &thread, sizeof(thread_t));
    if (strcmp(thread.uuid, "none\n\0") == 0) {
        client_error_unauthorized();
        return;
    }
    if (strcmp(thread.uuid, "none1\n\0") == 0) {
        client_error_unknown_team(client->teamuuid);
        return;
    }
    my_info_reply_two(client, thread);
}

void my_info_thread(int sd, client_t *client)
{
    channel_t channel;
    info_t info;

    strcpy(info.uuidTeam, client->teamuuid);
    strcpy(info.uuidChannel, client->channeluuid);
    write(sd, &info, sizeof(info_t));
    read(sd, &channel, sizeof(channel_t));
    if (strcmp(channel.uuid, "none\n\0") == 0) {
        client_error_unauthorized();
        return;
    }
    if (strcmp(channel.uuid, "none1\n\0") == 0) {
        client_error_unknown_team(client->teamuuid);
        return;
    }
    if (strcmp(channel.uuid, "none2\n\0") == 0) {
        client_error_unknown_channel(client->channeluuid);
        return;
    }
    client_print_channel(channel.uuid, channel.name, channel.description);
}

void my_info_channel(int sd, client_t *client)
{
    team_t team;

    write(sd, client->teamuuid, strlen(client->teamuuid));
    read(sd, &team, sizeof(team_t));
    if (strcmp(team.uuid, "none\n\0") == 0) {
        client_error_unauthorized();
        return;
    }
    if (strcmp(team.uuid, "none1\n\0") == 0) {
        client_error_unknown_team(client->teamuuid);
        return;
    }
    client_print_team(team.uuid, team.name, team.description);
}

void my_info_team(int sd, client_t *client UNUSED)
{
    user_t user;

    read(sd, &user, sizeof(user_t));
    if (strcmp(user.uuid, "none\n\0") == 0) {
        client_error_unauthorized();
        return;
    }
    client_print_user(user.uuid, user.username, user.status);
}

void my_info(int sd, char *buff UNUSED, client_t *client)
{
    for (int i = 0; i < 4; i++)
        if (listTable[i].use == client->use) {
            write(sd, &(client->use), sizeof(enum useType));
            listTable[i].ptr(sd, client);
        }
}