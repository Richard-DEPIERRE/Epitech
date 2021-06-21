/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "server.h"

static functList_t listTable[] = {
    {GLOBAL, my_list_team},
    {TEAM, my_list_channel},
    {CHANNEL, my_list_thread},
    {THREAD, my_list_reply},
};

void my_list_team(server_t *server UNUSED, int sd)
{
    int fd = open_db("db/team.db", "Can’t open Team database\n\0");
    int size = 0;
    team_t team;

    for (;read(fd, &team, sizeof(team_t)) > 0; size++);
    write(sd, &size, sizeof(int));
    close(fd);
    fd = open_db("db/team.db", "Can’t open Team database\n\0");
    while (read(fd, &team, sizeof(team_t)) > 0)
        write(sd, &team, sizeof(team_t));
}

void my_list_channel(server_t *server UNUSED, int sd)
{
    int fd = open_db("db/channel.db", "Can’t open Channel database\n\0");
    int size = -1;
    channel_t channel;

    read(sd, &channel, sizeof(channel_t));
    if (check_team_list(channel.team_uuid) == -1) {
        write(sd, &size, sizeof(int));
        return;
    }
    for (size = 0;read(fd, &channel, sizeof(channel_t)) > 0; size++);
    write(sd, &size, sizeof(int));
    close(fd);
    fd = open_db("db/channel.db", "Can’t open Channel database\n\0");
    while (read(fd, &channel, sizeof(channel_t)) > 0)
        write(sd, &channel, sizeof(channel_t));
}

void my_list_thread(server_t *server UNUSED, int sd)
{
    int fd = open_db("db/thread.db", "Can’t open Thread database\n\0");
    int size = -1;
    thread_t thread;

    read(sd, &thread, sizeof(thread_t));
    if (check_team_list(thread.team_uuid) == -1) {
        write(sd, &size, sizeof(int));
        return;
    }
    if (check_channel_list(thread.channel_uuid) == -1) {
        size = -2;
        write(sd, &size, sizeof(int));
        return;
    }
    for (size = 0;read(fd, &thread, sizeof(thread_t)) > 0; size++);
    write(sd, &size, sizeof(int));
    close(fd);
    fd = open_db("db/thread.db", "Can’t open Thread database\n\0");
    while (read(fd, &thread, sizeof(thread_t)) > 0)
        write(sd, &thread, sizeof(thread_t));
}

void my_list_reply(server_t *server UNUSED, int sd)
{
    int fd = open_db("db/reply.db", "Can’t open Reply database\n\0");
    int size = -1;
    reply_t reply;

    read(sd, &reply, sizeof(reply_t));
    if (check_list_replys(size, sd, reply) == -1)
        return;
    for (size = 0;read(fd, &reply, sizeof(reply_t)) > 0; size++);
    write(sd, &size, sizeof(int));
    close(fd);
    fd = open_db("db/reply.db", "Can’t open Thread database\n\0");
    while (read(fd, &reply, sizeof(reply_t)) > 0)
        write(sd, &reply, sizeof(reply_t));
}

void my_list(server_t *server, int sd)
{
    enum useType use;

    read(sd, &use, sizeof(enum useType));
    for (int i = 0; i < 4; i++)
        if (listTable[i].use == use)
            listTable[i].ptr(server, sd);
}