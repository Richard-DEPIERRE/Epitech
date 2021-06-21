/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "server.h"

int check_sub(char teamUuid[37], char userUuid[37])
{
    int fd = open_db("db/links.db", "Can’t open Links database\n\0");
    link_t link;

    while (read(fd, &link, sizeof(link_t)) > 0)
        if (strcmp(userUuid, link.user_uuid) == 0 &&
        strcmp(teamUuid, link.team_uuid) == 0)
            return (0);
    return (1);
}

int check_errors_sub(int sd, user_t user, char uuid[37])
{
    int fdTeam = open_db("db/team.db", "Can’t open Teams database\n\0");
    int check = 0;
    team_t team;

    while (read(fdTeam, &team, sizeof(team_t)) > 0)
        if (strcmp(team.uuid, uuid) == 0) {
            check = -1;
            break;
        }
    if (check != -1) {
        strcpy(user.uuid, "unknown\0");
        write(sd, &user, sizeof(user_t));
        close(fdTeam);
        return (-1);
    }
    return (0);
}

void my_subscribe_two(server_t *server, int sd, char uuid[37], user_t user)
{
    link_t link;
    int fd;

    if (check_errors_sub(sd, user, uuid) == -1)
        return;
    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd)
            user = set_user(tmp->user.fd, tmp->user.status,
            tmp->user.username, tmp->user.uuid);
    strcpy(link.user_uuid, user.uuid);
    strcpy(link.team_uuid, uuid);
    fd = open_db("db/links.db", "Can’t open Links database\n\0");
    write(fd, &link, sizeof(link_t));
    write(sd, &user, sizeof(user_t));
    server_event_user_subscribed(uuid, user.uuid);
    close(fd);
}

void my_subscribe(server_t *server, int sd)
{
    char uuid[37];
    user_t user;

    memset(uuid, '\0', 37);
    memset(user.uuid, '\0', 37);
    strcpy(user.uuid, "null\0");
    read(sd, uuid, sizeof(char) * 37);
    if (check_connect(server->users,  &user, sizeof(user_t), sd) == 1)
        return;
    my_subscribe_two(server, sd, uuid, user);
}