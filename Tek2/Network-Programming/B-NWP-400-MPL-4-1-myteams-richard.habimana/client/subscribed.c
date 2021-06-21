/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "client.h"

void my_subscribed_three(int num, char uuid[37], int sd)
{
    user_t user;

    if (num == -1) {
        client_error_unauthorized();
        return;
    }
    if (num == -2) {
        client_error_unknown_team(uuid);
        return;
    }
    for (int i = 0; i < num; i++) {
        read(sd, &user, sizeof(user_t));
        client_print_users(user.uuid, user.username, user.status);
    }
}

void my_subscribed_two(int i, char *buff, int sd)
{
    int num;
    char uuid[37];

    i++;
    memset(uuid, '\0', sizeof(char)*37);
    for (int size = 0; buff[i + size] != 34 && buff[i + size]; size++) {
        uuid[size] = buff[i + size];
    }
    write(sd, uuid, 37);
    read(sd, &num, sizeof(int));
    my_subscribed_three(num, uuid, sd);
}

void my_subscribed(int sd, char *buff, client_t *client UNUSED)
{
    int i = 0;
    int num;
    team_t team;

    for (i = 0; buff[i] && buff[i] != 34; i++);
    if (!buff[i]) {
        write(sd, "null\n\0", 6);
        read(sd, &num, sizeof(int));
        if (num == -1) {
            client_error_unauthorized();
            return;
        }
        for (int i = 0; i < num; i++) {
            read(sd, &team, sizeof(team_t));
            client_print_teams(team.uuid, team.name, team.description);
        }
        return;
    }
    my_subscribed_two(i, buff, sd);
}