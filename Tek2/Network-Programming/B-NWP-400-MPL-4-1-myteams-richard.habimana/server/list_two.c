/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** list
*/

#include "server.h"

int check_list_replys(int size, int sd, reply_t reply)
{
    if (check_team_list(reply.team_uuid) == -1) {
        write(sd, &size, sizeof(int));
        return (-1);
    }
    if (check_channel_list(reply.channel_uuid) == -1) {
        size = -2;
        write(sd, &size, sizeof(int));
        return (-1);
    }
    if (check_thread_list(reply.thread_uuid) == -1) {
        size = -3;
        write(sd, &size, sizeof(int));
        return (-1);
    }
}