/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** sent_by_server_two
*/

#include "client.h"

void r_channel(int sd)
{
    channel_t channel;
    read(sd, &channel, sizeof(channel_t));
    client_event_channel_created(channel.uuid, channel.name,
    channel.description);
}

void r_thread(int sd)
{
    thread_t thread;
    read(sd, &thread, sizeof(thread_t));
    client_event_thread_created(thread.uuid, thread.user_uuid,
    thread.timestamp, thread.name, thread.description);
}

void r_reply(int sd)
{
    reply_t reply;
    read(sd, &reply, sizeof(reply_t));
    client_event_thread_reply_received(reply.team_uuid, reply.thread_uuid,
    reply.user_uuid, reply.body);
}