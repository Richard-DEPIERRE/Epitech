/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_team
*/

#include "server.h"

int check_thread(char name[MAX_NAME_LENGTH])
{
    int fd = open_db("db/thread.db", "Can't connect to Thread database\n");
    thread_t team;

    while (read(fd, &team, sizeof(thread_t)) > 0)
        if (strcmp(team.name, name) == 0) {
            close(fd);
            return (-1);
        }
    close(fd);
    return (0);
}

void read_write_thread(server_t *server, int sd, thread_t thread)
{
    uuid_t binuuid;
    char *uuid = malloc(37);
    int fd = open_db("db/thread.db", "Can't connect to Thread database\n");

    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    memset(thread.uuid, '\0', 37);
    strcpy(thread.uuid, uuid);
    write(fd, &thread, sizeof(thread_t));
    write(sd, &thread, sizeof(thread_t));
    server_event_thread_created(thread.channel_uuid, thread.uuid,
    thread.user_uuid, thread.name, thread.description);
    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.status == 1 && tmp->user.fd != sd &&
        check_sub(thread.team_uuid, tmp->user.uuid) == 0) {
            write(tmp->user.fd, "thread\n\0", 9);
            usleep(1000);
            write(tmp->user.fd, &thread, sizeof(thread_t));
        }
    close(fd);
}

void my_create_thread(server_t *server, int sd)
{
    thread_t thread;
    thread_t error;

    memset(error.uuid, '\0', 37);
    strcpy(error.uuid, "null\n\0");
    read(sd, &thread, sizeof(thread_t));
    if (check_connect(server->users, &error, sizeof(thread_t), sd) == 1)
        return;
    if (check_thread(thread.name) == -1) {
        memset(thread.uuid, '\0', 37);
        strcpy(thread.uuid, "unknown\n\0");
        write(sd, &thread, sizeof(thread_t));
        return;
    }
    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd)
            strcpy(thread.user_uuid, tmp->user.uuid);
    read_write_thread(server, sd, thread);
}