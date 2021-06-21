/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_team
*/

#include "server.h"

void read_write_reply(server_t *server, int sd, reply_t reply)
{
    uuid_t binuuid;
    char *uuid = malloc(37);
    int fd = open_db("db/reply.db", "Can't connect to Reply database\n");

    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    memset(reply.uuid, '\0', 37);
    strcpy(reply.uuid, uuid);
    write(fd, &reply, sizeof(reply_t));
    write(sd, &reply, sizeof(reply_t));
    server_event_reply_created(reply.thread_uuid,
    reply.user_uuid, reply.body);
    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.status == 1 && tmp->user.fd != sd &&
        check_sub(reply.team_uuid, tmp->user.uuid) == 0) {
            write(tmp->user.fd, "reply\n\0", 9);
            usleep(1000);
            write(tmp->user.fd, &reply, sizeof(reply_t));
        }
    close(fd);
}

void my_create_reply(server_t *server, int sd)
{
    reply_t reply;
    reply_t error;

    memset(error.uuid, '\0', 37);
    strcpy(error.uuid, "null\n\0");
    read(sd, &reply, sizeof(reply_t));
    if (check_connect(server->users, &error, sizeof(reply_t), sd) == 1)
        return;
    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd)
            strcpy(reply.user_uuid, tmp->user.uuid);
    read_write_reply(server, sd, reply);
}