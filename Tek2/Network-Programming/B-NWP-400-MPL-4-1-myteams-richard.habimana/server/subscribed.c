/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "server.h"

void write_team(char uuid[37], int sd)
{
    int fdTeams = open_db("db/team.db", "Can't open to Teams database\n\0");
    team_t team;

    while (read(fdTeams, &team, sizeof(team_t)) > 0)
        if (strcmp(team.uuid, uuid) == 0) {
            write(sd, &team, sizeof(team_t));
            close(fdTeams);
            return;
        }
    close(fdTeams);
}

void my_subscribed_two(team_t team, char *buff, user_t user, int sd)
{
    int fd = open_db("db/team.db", "Can't connect to Teams database\n\0");
    int fdLink = open_db("db/links.db", "Can’t open Links database\n\0");
    link_t link;

    while (read(fd, &team, sizeof(team_t)) > 0)
        if (strcmp(team.uuid, buff) == 0)
            break;
    close(fd);
    send_length(1, user, sd, team);
    while (read(fdLink, &link, sizeof(link_t)) > 0) {
        if (strcmp(link.team_uuid, team.uuid) == 0 &&
        strcmp(link.user_uuid, user.uuid) == 0)
            write_user(link.user_uuid, sd);
    }
    close(fdLink);
}

void read_length(user_t user, int sd)
{
    link_t link;
    int fdLink = open_db("db/links.db", "Can’t open Links database\n\0");

    while (read(fdLink, &link, sizeof(link_t)) > 0)
        if (strcmp(link.user_uuid, user.uuid) == 0)
            write_team(link.team_uuid, sd);
    close(fdLink);
}

void my_subscribed(server_t *server, int sd)
{
    char *buff = malloc(sizeof(char) * 1024);
    user_t user;
    team_t team;

    memset(buff, '\0', 1024);
    read(sd, buff, sizeof(char)*1024);
    for (node_t *t = server->users; t; t = t->next)
        if (t->user.fd == sd)
            user = set_user(t->user.fd, t->user.status,
            t->user.username, t->user.uuid);
    if (strcmp(buff, "null\n\0") == 0) {
        send_length(0, user, sd, team);
        read_length(user, sd);
        return;
    }
    my_subscribed_two(team, buff, user, sd);
}