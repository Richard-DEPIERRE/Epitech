/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_team
*/

#include "server.h"

int check_team(char name[MAX_NAME_LENGTH])
{
    int fd = open_db("db/team.db", "Can't connect to Team database\n\0");
    team_t team;

    while (read(fd, &team, sizeof(team_t)) > 0)
        if (strcmp(team.name, name) == 0)
            return (-1);
    return (0);
}

void read_write_team(server_t *server, int sd, team_t team, char *uuid)
{
    int fd = open_db("db/team.db", "Can't connect to Team database\n\0");

    memset(team.uuid, '\0', 37);
    strcpy(team.uuid, uuid);
    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd)
            strcpy(team.user_uuid, tmp->user.uuid);
    write(fd, &team, sizeof(team_t));
    write(sd, &team, sizeof(team_t));
    server_event_team_created(team.uuid, team.name, team.user_uuid);
    for (node_t *tmp = server->users; tmp; tmp = tmp->next) {
        if (tmp->user.status == 1 && tmp->user.fd != sd) {
            write(tmp->user.fd, "team\n\0", 6);
            usleep(1000);
            write(tmp->user.fd, &team, sizeof(team_t));
        }
    }
    close(fd);
}

void my_create_team(server_t *server, int sd)
{
    team_t team;
    team_t error;
    uuid_t binuuid;
    char *uuid = malloc(37);

    memset(error.uuid, '\0', 37);
    strcpy(error.uuid, "null\n\0");
    read(sd, &team, sizeof(team_t));
    if (check_connect(server->users, &error, sizeof(team_t), sd) == 1)
        return;
    if (check_team(team.name) == -1) {
        memset(team.uuid, '\0', 37);
        strcpy(team.uuid, "unknown\n\0");
        write(sd, &team, sizeof(team_t));
        return;
    }
    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    read_write_team(server, sd, team, uuid);
}