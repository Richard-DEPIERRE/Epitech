/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "server.h"

static functList_t listTable[] = {
    {GLOBAL, my_info_team},
    {TEAM, my_info_channel},
    {CHANNEL, my_info_thread},
    {THREAD, my_info_reply},
};

void my_info_team(server_t *server UNUSED, int sd)
{
    user_t user;

    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd) {
            user = set_user(tmp->user.fd, tmp->user.status,
            tmp->user.username, tmp->user.uuid);
            write(sd, &user, sizeof(user_t));
            return;
        }
    memset(user.uuid, '\0', 37);
    strcpy(user.uuid, "none\n\0");
    write(sd, &user, sizeof(user_t));
}

void my_info_channel(server_t *server UNUSED, int sd)
{
    int fd = open_db("db/team.db", "Can’t open Team database\n\0");
    team_t team;
    char uuid[37] = {0};

    read(sd, &uuid, 37);
    memset(team.uuid, '\0', 37);
    strcpy(team.uuid, "none\n\0");
    if (check_connect(server->users, &team, sizeof(team_t), sd) == -1)
        return;
    while (read(fd, &team, sizeof(team_t)) > 0) {
        if (strcmp(team.uuid, uuid) == 0) {
            write(sd, &team, sizeof(team_t));
            return;
        }
    }
    memset(team.uuid, '\0', 37);
    strcpy(team.uuid, "none1\n\0");
    write(sd, &team, sizeof(team_t));
}

void my_info_thread(server_t *server UNUSED, int sd)
{
    int fdChannel = open_db("db/channel.db", "Can’t open Channel db\n\0");
    channel_t channel;
    info_t info;

    read(sd, &info, sizeof(info_t));
    memset(channel.uuid, '\0', 37);
    strcpy(channel.uuid, "none\n\0");
    if (check_connect(server->users, &channel, sizeof(channel_t), sd) == -1)
        return;
    strcpy(channel.uuid, "none1\n\0");
    if (info_check_team(info, sd, &channel, sizeof(channel_t)) == 1)
        return;
    while (read(fdChannel, &channel, sizeof(channel_t)) > 0)
        if (strcmp(channel.uuid, info.uuidChannel) == 0) {
            write(sd, &channel, sizeof(channel_t));
            return;
        }
    memset(channel.uuid, '\0', 37);
    strcpy(channel.uuid, "none2\n\0");
    write(sd, &channel, sizeof(channel_t));
}

void my_info_reply(server_t *server UNUSED, int sd)
{
    thread_t thread;
    info_t info;

    read(sd, &info, sizeof(info_t));
    memset(thread.uuid, '\0', 37);
    strcpy(thread.uuid, "none\n\0");
    if (check_connect(server->users, &thread, sizeof(thread_t), sd) == -1)
        return;
    strcpy(thread.uuid, "none1\n\0");
    if (info_check_team(info, sd, &thread, sizeof(thread_t)) == 1)
        return;
    my_info_reply_two(sd, info);
}

void my_info(server_t *server, int sd)
{
    enum useType use;

    read(sd, &use, sizeof(enum useType));
    for (int i = 0; i < 4; i++)
        if (listTable[i].use == use)
            listTable[i].ptr(server, sd);
}