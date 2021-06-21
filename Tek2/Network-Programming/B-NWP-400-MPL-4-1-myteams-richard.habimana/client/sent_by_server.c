/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** received
*/

#include "client.h"

void r_quit(int sd UNUSED)
{
    exit(0);
}

void r_message(int sd)
{
    messages_t message;
    read(sd, &message, sizeof(messages_t));
    client_event_private_message_received(message.uuid_sender,
    message.message);
}

void r_connect(int sd)
{
    user_t user;
    read(sd, &user, sizeof(user_t));
    client_event_logged_in(user.uuid, user.username);
}

void r_disconnect(int sd)
{
    user_t user;
    read(sd, &user, sizeof(user_t));
    client_event_logged_out(user.uuid, user.username);
}

void r_team(int sd)
{
    team_t team;
    read(sd, &team, sizeof(team_t));
    client_event_team_created(team.uuid, team.name, team.description);
}