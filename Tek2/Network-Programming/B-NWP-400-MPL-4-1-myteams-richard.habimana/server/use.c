/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** use
*/

#include "server.h"

void my_use(server_t *server, int sd)
{
    node_t *tmp;
    int a = -1;

    for (tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd)
            break;
    if (tmp == NULL) {
        write(sd, &a, sizeof(int));
        return;
    }
    a = 0;
    write(sd, &a, sizeof(int));
}