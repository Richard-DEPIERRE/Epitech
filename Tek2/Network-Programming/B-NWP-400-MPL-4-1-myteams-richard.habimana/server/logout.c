/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** logout
*/

#include "server.h"

void my_logout_three(server_t *s, int sd, user_t nullUser)
{
    node_t *head = malloc(sizeof(node_t));

    for (head = s->users; head->next != NULL; head = head->next)
        if (sd == head->next->user.fd) {
            head->next->user.status = 0;
            head->next->user.fd = -1;
            update_user_db(head->next->user.username, 0);
            server_event_user_logged_out(head->next->user.uuid);
            write(sd, &(head->next->user), sizeof(user_t));
            send_end_to_everyone(s, sd, head->next);
            return;
        }
    write(sd, &nullUser, sizeof(user_t));
}

void my_logout_two_res(server_t *s, int sd, user_t nullUser)
{
    if (s->users->next->next == NULL && sd != s->users->next->user.fd
    && sd != s->users->user.fd) {
        write(sd, &nullUser, sizeof(user_t));
        return;
    }
    if (s->users->next->next == NULL && sd == s->users->user.fd) {
        s->users->user.status = 0;
        s->users->user.fd = -1;
        update_user_db(s->users->user.username, 0);
        server_event_user_logged_out(s->users->user.uuid);
        write(sd, &(s->users->user), sizeof(user_t));
        send_end_to_everyone(s, sd, s->users);
        return;
    }
    my_logout_three(s, sd, nullUser);
}

void my_logout_two(server_t *s, int sd, user_t nullUser)
{
    if (s->users->next->next == NULL && sd == s->users->next->user.fd) {
        s->users->next->user.status = 0;
        s->users->next->user.fd = -1;
        update_user_db(s->users->next->user.username, 0);
        server_event_user_logged_out(s->users->next->user.uuid);
        write(sd, &(s->users->next->user), sizeof(user_t));
        send_end_to_everyone(s, sd, s->users->next);
        return;
    }
    my_logout_two_res(s, sd, nullUser);
}

int check_logout(server_t *server, int sd, user_t nullUser)
{
    if (server->users == NULL) {
        write(sd, &nullUser, sizeof(user_t));
        return (-1);
    }
    if (server->users->next == NULL && sd == server->users->user.fd) {
        server->users->user.status = 0;
        server->users->user.fd = -1;
        update_user_db(server->users->user.username, 0);
        server_event_user_logged_out(server->users->user.uuid);
        write(sd, &server->users->user, sizeof(user_t));
        send_end_to_everyone(server, sd, server->users);
        return (-1);
    } else if (server->users->next == NULL && sd != server->users->user.fd) {
        write(sd, &nullUser, sizeof(user_t));
        return (-1);
    }
    return (0);
}

void my_logout(server_t *server, int sd)
{
    user_t nullUser;

    strcpy(nullUser.uuid, "null\0");
    strcpy(nullUser.username, "null\0");
    nullUser.status = -1;
    nullUser.fd = -1;
    if (check_logout(server, sd, nullUser) == -1)
        return;
    my_logout_two(server, sd, nullUser);
}
