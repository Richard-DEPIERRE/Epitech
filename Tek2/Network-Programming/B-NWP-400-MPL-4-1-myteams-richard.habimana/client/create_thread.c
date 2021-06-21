/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** create_channel
*/

#include "client.h"

void my_read_write_thread(int sd, thread_t thread)
{
    write(sd, &thread, sizeof(thread_t));
    read(sd, &thread, sizeof(thread_t));
    if (strcmp(thread.uuid, "unknown\n\0") == 0)
        client_error_already_exist();
    else if (strcmp(thread.uuid, "null\n\0") == 0)
        client_error_unauthorized();
    else
        client_print_thread_created(thread.uuid, thread.user_uuid,
        thread.timestamp, thread.name, thread.description);
}

void my_create_thread(int sd, char *buff, client_t *client UNUSED)
{
    int i = 0;
    int size = 0;
    thread_t thread;

    memset(thread.name, '\0', sizeof(char) * MAX_NAME_LENGTH);
    memset(thread.description, '\0', sizeof(char) * MAX_DESCRIPTION_LENGTH);
    thread.timestamp = time(NULL);
    for (i = 0; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        thread.name[size] = buff[i + size];
    i += size + 1;
    for (; buff[i] && buff[i] != 34; i++);
    i++;
    for (size = 0; buff[i + size] && buff[i + size] != 34; size++)
        thread.description[size] = buff[i + size];
    strcpy(thread.team_uuid, client->teamuuid);
    strcpy(thread.channel_uuid, client->channeluuid);
    my_read_write_thread(sd, thread);
}