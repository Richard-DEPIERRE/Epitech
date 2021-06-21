/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "client.h"

void my_list_reply_two(int sd, int size, client_t *client)
{
    reply_t reply;

    if (size == -3) {
        client_error_unknown_thread(client->threaduuid);
        return;
    }
    for (int i = 0; i < size; i++) {
        read(sd, &reply, sizeof(reply_t));
        client_thread_print_replies(reply.thread_uuid, reply.user_uuid,
        reply.timestamp, reply.body);
    }
}

void my_info_reply_two(client_t *client, thread_t thread)
{
    if (strcmp(thread.uuid, "none2\n\0") == 0) {
        client_error_unknown_channel(client->channeluuid);
        return;
    }
    if (strcmp(thread.uuid, "none3\n\0") == 0) {
        client_error_unknown_thread(client->threaduuid);
        return;
    }
    client_print_thread(thread.uuid, thread.user_uuid, thread.timestamp,
    thread.name, thread.description);
}
