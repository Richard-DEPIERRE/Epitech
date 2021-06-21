/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** sonetDatabase
*/

#include "server.h"

user_t set_user(int fd, int status, char *username, char *uuid)
{
    user_t user;
    user.fd = fd;
    memset(user.uuid, '\0', 37);
    strcpy(user.uuid, uuid);
    memset(user.username, '\0', MAX_NAME_LENGTH);
    strcpy(user.username, username);
    user.status = status;
    return (user);
}

node_t *get_user(void)
{
    int fd = open("db/users.db", O_RDONLY | O_APPEND);
    node_t *head = NULL;
    node_t *tmp = NULL;
    node_t *res = NULL;
    user_t bf;

    while (read(fd, &bf, sizeof(user_t)) > 0)
        if (head == NULL) {
            head = malloc(sizeof(node_t));
            head->user = set_user(bf.fd, bf.status, bf.username, bf.uuid);
            head->next = NULL;
        } else {
            for (tmp = head; tmp->next != NULL; tmp = tmp->next);
            res = malloc(sizeof(node_t));
            res->user = set_user(bf.fd, bf.status, bf.username, bf.uuid);
            res->next = NULL;
            tmp->next = res;
        }
    close(fd);
    return (head);
}

void update_users(char *name, int status, node_t *users)
{
    for (node_t *tmp = users; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->user.username, name) == 0) {
            tmp->user.status = status;
            break;
        }
}

int update_user_db(char *name, int status)
{
    node_t *users = get_user();
    int fd = open("db/users.db", O_WRONLY | O_CREAT | O_TRUNC);

    update_users(name, status, users);
    for (node_t *tmp = users; tmp != NULL; tmp = tmp->next)
        write(fd, &(tmp->user), sizeof(user_t));
    return (0);
}