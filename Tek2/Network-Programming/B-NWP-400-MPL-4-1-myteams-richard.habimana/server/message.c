/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** message
*/

#include "server.h"

int get_size_messages(char *uuidSender, char *uuid)
{
    int fdMessage = open("db/messages.db", O_RDONLY);
    int res = 0;
    messages_t message;

    if (fdMessage == -1) {
        write(2, "Can't connect to Messages database\n", 26);
        exit(84);
    }
    while (read(fdMessage, &message, sizeof(messages_t)) > 0) {
        if ((strcmp(message.uuid_receiver, uuid) == 0 &&
        strcmp(message.uuid_sender, uuidSender) == 0) ||
        (strcmp(message.uuid_receiver, uuidSender) == 0 &&
        strcmp(message.uuid_sender, uuid) == 0))
            res += 1;
    }
    close(fdMessage);
    return (res);
}

void my_messages_get(server_t *server, int sd, char uuid[37])
{
    node_t *tmp;
    char uuidSender[37];
    int size = 0;
    int fd = open_db("db/messages.db", "Can't connect to Mess database\n\0");
    messages_t message;

    for (tmp = server->users; tmp != NULL; tmp = tmp->next)
        if (tmp->user.fd == sd) {
            strcpy(uuidSender, tmp->user.uuid);
            break;
        }
    size = get_size_messages(uuidSender, uuid);
    write(sd, &size, sizeof(int));
    while (read(fd, &message, sizeof(messages_t)) > 0)
        if ((strcmp(message.uuid_receiver, uuid) == 0 &&
        strcmp(message.uuid_sender, uuidSender) == 0) ||
        (strcmp(message.uuid_receiver, uuidSender) == 0 &&
        strcmp(message.uuid_sender, uuid) == 0))
            write(sd, &message, sizeof(messages_t));
    close(fd);
}

void my_messages(server_t *server, int sd)
{
    char uuid[37];
    int fdUser = 0;
    user_t user;
    int size = -1;

    read(sd, uuid, 37);
    if (check_connect(server->users, &size, sizeof(int), sd) == 1)
        return;
    fdUser = open_db("db/users.db", "Can't connect to Messages database\n\0");
    while (read(fdUser, &user, sizeof(user_t)) > 0)
        if (strcmp(user.uuid, uuid) == 0) {
            my_messages_get(server, sd, uuid);
            close(fdUser);
            return;
        }
    size = -2;
    write(sd, &size, sizeof(int));
    close(fdUser);
}