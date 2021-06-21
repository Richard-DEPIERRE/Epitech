/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_team
*/

#include "client.h"

void my_read_write_team(int sd, team_t team)
{
    write(sd, &team, sizeof(team_t));
    read(sd, &team, sizeof(team_t));
    if (strcmp(team.uuid, "unknown\n\0") == 0)
        client_error_already_exist();
    else if (strcmp(team.uuid, "null\n\0") == 0)
        client_error_unauthorized();
    else
        client_print_team_created(team.uuid, team.name, team.description);
}

void my_create_team(int sd, char *buff, client_t *client UNUSED)
{
    int i = 0;
    int size = 0;
    team_t team;

    memset(team.name, '\0', sizeof(char) * MAX_NAME_LENGTH);
    memset(team.description, '\0', sizeof(char) * MAX_DESCRIPTION_LENGTH);
    for (i = 0; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        team.name[size] = buff[i + size];
    i += size + 1;
    for (; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        team.description[size] = buff[i + size];
    my_read_write_team(sd, team);
}