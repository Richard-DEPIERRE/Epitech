/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** check
*/

#include "server.h"

int check_team_list(char uuid[37])
{
    team_t team;
    int fd = open_db("db/team.db", "Can’t open Team database\n\0");

    while (read(fd, &team, sizeof(team_t)) > 0)
        if (strcmp(uuid, team.uuid) == 0)
            return (0);
    return (-1);
}

int check_channel_list(char uuid[37])
{
    channel_t channel;
    int fd = open_db("db/channel.db", "Can’t open Channel database\n\0");

    while (read(fd, &channel, sizeof(channel_t)) > 0)
        if (strcmp(uuid, channel.uuid) == 0)
            return (0);
    return (-1);
}

int check_thread_list(char uuid[37])
{
    thread_t thread;
    int fd = open_db("db/thread.db", "Can’t open Thread database\n\0");

    while (read(fd, &thread, sizeof(thread_t)) > 0) {
        if (strcmp(uuid, thread.uuid) == 0)
            return (0);
    }
    return (-1);
}