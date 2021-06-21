/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_channel
*/

#include "client.h"

void my_read_write_reply(int sd, reply_t reply)
{
    write(sd, &reply, sizeof(reply_t));
    read(sd, &reply, sizeof(reply_t));
    if (strcmp(reply.uuid, "unknown\n\0") == 0)
        client_error_already_exist();
    else if (strcmp(reply.uuid, "null\n\0") == 0)
        client_error_unauthorized();
    else
        client_print_reply_created(reply.team_uuid, reply.thread_uuid,
        reply.user_uuid, reply.body);
}

void my_create_reply(int sd, char *buff, client_t *client UNUSED)
{
    int i = 0;
    int size = 0;
    reply_t reply;

    memset(reply.body, '\0', sizeof(char) * MAX_DESCRIPTION_LENGTH);
    reply.timestamp = time(NULL);
    for (i = 0; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        reply.body[size] = buff[i + size];
    strcpy(reply.team_uuid, client->teamuuid);
    strcpy(reply.channel_uuid, client->channeluuid);
    strcpy(reply.thread_uuid, client->threaduuid);
    my_read_write_reply(sd, reply);
}