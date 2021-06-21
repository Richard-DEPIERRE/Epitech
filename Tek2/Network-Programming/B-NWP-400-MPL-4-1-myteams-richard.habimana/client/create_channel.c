/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_channel
*/

#include "client.h"

void my_read_write_channel(int sd, channel_t channel)
{
    write(sd, &channel, sizeof(channel_t));
    read(sd, &channel, sizeof(channel_t));
    if (strcmp(channel.uuid, "unknown\n\0") == 0)
        client_error_already_exist();
    else if (strcmp(channel.uuid, "null\n\0") == 0)
        client_error_unauthorized();
    else
        client_print_channel_created(channel.uuid,
        channel.name, channel.description);
}

void my_create_channel(int sd, char *buff, client_t *client UNUSED)
{
    int i = 0;
    int size = 0;
    channel_t channel;

    memset(channel.name, '\0', sizeof(char) * MAX_NAME_LENGTH);
    memset(channel.description, '\0', sizeof(char) * MAX_DESCRIPTION_LENGTH);
    memset(channel.team_uuid, '\0', sizeof(char) * 37);
    for (i = 0; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        channel.name[size] = buff[i + size];
    i += size + 1;
    for (; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        channel.description[size] = buff[i + size];
    strcpy(channel.team_uuid, client->teamuuid);
    my_read_write_channel(sd, channel);
}