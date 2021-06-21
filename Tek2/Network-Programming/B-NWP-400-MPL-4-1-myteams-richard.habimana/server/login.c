/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** connect
*/

#include "server.h"
#include "../libs/myteams/logging_server.h"

int open_file(void)
{
    int fd = open("db/users.db", O_RDWR | O_APPEND | O_CREAT,
    S_IRWXU | S_IRWXG | S_IRWXO);
    if (fd == -1) {
        write(2, "Can't connect to database\n", 26);
        exit(84);
    }
    return (fd);
}

void already_exists(server_t *server, char user[1024],
user_t buffUser, int sd)
{
    node_t *head = malloc(sizeof(node_t));
    for (head = server->users; head != NULL && head->next != NULL;
    head = head->next);
    node_t *new = malloc(sizeof(node_t));
    new->user = set_user(sd, 1, buffUser.username, buffUser.uuid);
    new->next = NULL;
    server_event_user_logged_in(buffUser.uuid);
    if (head)
        head->next = new;
    else
        server->users = new;
    update_user_db(user, 1);
    write(sd, &buffUser, sizeof(user_t));
    for (node_t *tmp = server->users; tmp != NULL; tmp = tmp->next)
        if (tmp->user.status == 1 && tmp->user.fd != sd) {
            write(tmp->user.fd, "connect\n\0", 9);
            usleep(1000);
            write(tmp->user.fd, &buffUser, sizeof(user_t));
        }
}

void does_not_exist_two(server_t *server, int sd, user_t res, char *uuid)
{
    server_event_user_logged_in(uuid);
    if (uuid)
        free(uuid);
    write(sd, &(res), sizeof(user_t));
    for (node_t *tmp = server->users; tmp != NULL; tmp = tmp->next)
        if (tmp->user.status == 1 && tmp->user.fd != sd) {
            write(tmp->user.fd, "connect\n\0", 9);
            usleep(1000);
            write(tmp->user.fd, &(res), sizeof(user_t));
        }
}

void does_not_exist(server_t *server, int sd, char user[1024], int fd)
{
    uuid_t binuuid;
    char *uuid = malloc(37);
    node_t *new = malloc(sizeof(node_t));
    node_t *head = malloc(sizeof(node_t));
    user_t res;

    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    res = set_user(sd, 1, user, uuid);
    write(fd, &res, sizeof(user_t));
    for (head = server->users; head != NULL && head->next != NULL;
    head = head->next);
    new->user = set_user(sd, 1, user, uuid);
    new->next = NULL;
    (head) ? (head->next = new) : (server->users = new);
    server_event_user_created(uuid, user);
    does_not_exist_two(server, sd, new->user, uuid);
    close(fd);
}

void my_login(server_t *server, int sd)
{
    char user[1024];
    user_t buffUser;
    int fd;

    memset(user, '\0', 1024);
    read(sd, user, 1024);
    fd = open_file();
    while (read(fd, &buffUser, sizeof(user_t)) > 0)
        if (strcmp(user, buffUser.username) == 0) {
            already_exists(server, user, buffUser, sd);
            close(fd);
            return;
        }
    does_not_exist(server, sd, user, fd);
}