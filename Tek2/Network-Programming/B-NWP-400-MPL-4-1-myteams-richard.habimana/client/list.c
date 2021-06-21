/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "client.h"

static functList_t listTable[] = {
    {GLOBAL, my_list_team},
    {TEAM, my_list_channel},
    {CHANNEL, my_list_thread},
    {THREAD, my_list_reply},
};

void my_list_team(int sd, client_t *client UNUSED)
{
    int size = 0;
    team_t team;

    read(sd, &size, sizeof(int));
    for (int i = 0; i < size; i++) {
        read(sd, &team, sizeof(team_t));
        client_print_teams(team.uuid, team.name, team.description);
    }
}

void my_list_channel(int sd, client_t *client)
{
    int size = 0;
    channel_t channel;

    strcpy(channel.team_uuid, client->teamuuid);
    write(sd, &channel, sizeof(channel_t));
    read(sd, &size, sizeof(int));
    if (size == -1) {
        client_error_unknown_team(client->teamuuid);
        return;
    }
    for (int i = 0; i < size; i++) {
        read(sd, &channel, sizeof(channel_t));
        client_team_print_channels(channel.uuid,
        channel.name, channel.description);
    }
}

void my_list_thread(int sd, client_t *client)
{
    int size = 0;
    thread_t thread;

    strcpy(thread.channel_uuid, client->channeluuid);
    strcpy(thread.team_uuid, client->teamuuid);
    write(sd, &thread, sizeof(thread_t));
    read(sd, &size, sizeof(int));
    if (size == -1) {
        client_error_unknown_team(client->teamuuid);
        return;
    }
    if (size == -2) {
        client_error_unknown_channel(client->channeluuid);
        return;
    }
    for (int i = 0; i < size; i++) {
        read(sd, &thread, sizeof(thread_t));
        client_channel_print_threads(thread.uuid, thread.user_uuid,
        thread.timestamp, thread.name, thread.description);
    }
}

void my_list_reply(int sd, client_t *client)
{
    int size = 0;
    reply_t reply;

    strcpy(reply.channel_uuid, client->channeluuid);
    strcpy(reply.team_uuid, client->teamuuid);
    strcpy(reply.thread_uuid, client->threaduuid);
    write(sd, &reply, sizeof(reply_t));
    read(sd, &size, sizeof(int));
    if (size == -1) {
        client_error_unknown_team(client->teamuuid);
        return;
    }
    if (size == -2) {
        client_error_unknown_channel(client->channeluuid);
        return;
    }
    my_list_reply_two(sd, size, client);
}

void my_list(int sd, char *buff UNUSED, client_t *client)
{
    for (int i = 0; i < 4; i++)
        if (listTable[i].use == client->use) {
            write(sd, &(client->use), sizeof(enum useType));
            listTable[i].ptr(sd, client);
        }
}