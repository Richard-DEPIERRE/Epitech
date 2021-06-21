/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "server.h"

int info_check_team(info_t info, int sd, void *send, size_t size)
{
    int fdTeams = open_db("db/team.db", "Can’t open Team database\n\0");
    team_t team;

    while (read(fdTeams, &team, sizeof(team_t)) > 0)
        if (strcmp(team.uuid, info.uuidTeam) == 0) {
            close(fdTeams);
            fdTeams = -1;
        }
    if (fdTeams != -1) {
        write(sd, send, size);
        return (1);
    }
    return (0);
}

int info_check_channel(info_t info, int sd, void *send, size_t size)
{
    int fdChannel = open_db("db/channel.db",
    "Can’t open Channel database\n\0");
    channel_t channel;

    while (read(fdChannel, &channel, sizeof(channel_t)) > 0)
        if (strcmp(channel.uuid, info.uuidChannel) == 0) {
            close(fdChannel);
            fdChannel = -1;
        }
    if (fdChannel != -1) {
        write(sd, send, size);
        return (1);
    }
    return (0);
}

void my_info_reply_two(int sd, info_t info)
{
    int fdThread = open_db("db/thread.db", "Can’t open Thread database\n\0");
    thread_t thread;

    memset(thread.uuid, '\0', 37);
    strcpy(thread.uuid, "none2\n\0");
    if (info_check_channel(info, sd, &thread, sizeof(thread_t)) == 1)
        return;
    while (read(fdThread, &thread, sizeof(thread_t)) > 0)
        if (strcmp(thread.uuid, info.uuidThread) == 0) {
            write(sd, &thread, sizeof(thread_t));
            return;
        }
    strcpy(thread.uuid, "none3\n\0");
    write(sd, &thread, sizeof(thread_t));
}