/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** temp
*/

#include "server.h"

void write_user(char uuid[37], int sd)
{
    int fdUsers = open_db("db/users.db", "Can't open to Users database\n\0");
    user_t user;

    while (read(fdUsers, &user, sizeof(user_t)) > 0)
        if (strcmp(user.uuid, uuid) == 0) {
            write(sd, &user, sizeof(user_t));
            close(fdUsers);
            return;
        }
    close(fdUsers);
}

int check_connect(node_t *head, void *send, size_t size, int sd)
{
    node_t *tmp = head;
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->user.fd == sd && tmp->user.status == 1)
            break;
    if (tmp == NULL) {
        write(sd, send, size);
        return (1);
    }
    return (0);
}

void init_fd(server_t *server)
{
    FD_ZERO(&server->read_fd_set);
    FD_SET(server->server_fd, &server->read_fd_set);
    FD_SET(0, &server->read_fd_set);
    server->maxFd = (server->maxFd >= server->server_fd) ? server->maxFd :
    server->server_fd;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (server->sockerFdNew[i].fd > 0)
            FD_SET(server->sockerFdNew[i].fd, &server->read_fd_set);
        if (server->sockerFdNew[i].fd > server->server_fd)
            server->maxFd = server->sockerFdNew[i].fd;
    }
    server->activity = select(server->maxFd + 1,
    &server->read_fd_set, NULL, NULL, NULL);
    if (server->activity < 0 && errno != EINTR) {
        perror("select error");
        exit(84);
    }
}

void destruct_server(void)
{
    int fd = open("db/users.db", O_RDONLY | O_APPEND);
    user_t buffUser;

    while (read(fd, &buffUser, sizeof(user_t)) > 0)
        update_user_db(buffUser.username, 0);
    close(fd);
}

void loop(server_t *server, char recvBuf[1024])
{
    int ret;

    init_fd(server);
    if (FD_ISSET(0, &server->read_fd_set)) {
        ret = read(0 , recvBuf, strlen(recvBuf));
        if (ret > 0)
            (strcmp("quit\n", recvBuf) == 0) ? destruct_server() : 0;
    }
    if (FD_ISSET (server->server_fd, &server->read_fd_set))
        accept_new_connection(server);
    for (server->i = 0; server->i < MAX_SIZE; server->i++) {
        server->sd = server->sockerFdNew[server->i].fd;
        core_server(server, server->sd, server->i);
    }
}