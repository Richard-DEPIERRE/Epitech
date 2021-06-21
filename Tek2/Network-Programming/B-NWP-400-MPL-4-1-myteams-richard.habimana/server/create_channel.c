/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_team
*/

#include "server.h"

int check_channel(char name[MAX_NAME_LENGTH])
{
    int fd = open_db("db/channel.db", "Can't connect to Channel database\n");
    channel_t team;

    while (read(fd, &team, sizeof(channel_t)) > 0)
        if (strcmp(team.name, name) == 0)
            return (-1);
    return (0);
}

void read_write_channel(server_t *server, int sd, channel_t channel,
char *uuid)
{
    int fd = open_db("db/channel.db", "Can't connect to Channel database\n");

    memset(channel.uuid, '\0', 37);
    strcpy(channel.uuid, uuid);
    write(fd, &channel, sizeof(channel_t));
    write(sd, &channel, sizeof(channel_t));
    server_event_channel_created(channel.team_uuid,
    channel.uuid, channel.name);
    for (node_t *tmp = server->users; tmp; tmp = tmp->next) {
        if (tmp->user.status == 1 && tmp->user.fd != sd &&
        check_sub(channel.team_uuid, tmp->user.uuid) == 0) {
            write(tmp->user.fd, "channel\n\0", 9);
            usleep(1000);
            write(tmp->user.fd, &channel, sizeof(channel_t));
        }
    }
    close(fd);
}

void my_create_channel(server_t *server, int sd)
{
    channel_t channel;
    channel_t error;
    uuid_t binuuid;
    char *uuid = malloc(37);

    memset(error.uuid, '\0', 37);
    strcpy(error.uuid, "null\n\0");
    read(sd, &channel, sizeof(channel_t));
    if (check_connect(server->users, &error, sizeof(channel_t), sd) == 1)
        return;
    if (check_channel(channel.name) == -1) {
        memset(channel.uuid, '\0', 37);
        strcpy(channel.uuid, "unknown\n\0");
        write(sd, &channel, sizeof(channel_t));
        return;
    }
    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    read_write_channel(server, sd, channel, uuid);
}