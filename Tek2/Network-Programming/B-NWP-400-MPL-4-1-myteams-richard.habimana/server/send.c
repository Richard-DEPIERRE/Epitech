/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** send
*/

#include "server.h"

void write_message(server_t *server, int sd, messages_t mes)
{
    node_t *tmp;
    int fd = open_db("db/messages.db", "Can't connect to Messa database\n\0");
    char message[1024] = "message\n\0";

    write(fd, &mes, sizeof(messages_t));
    write(sd, &mes, sizeof(messages_t));
    for (tmp = server->users; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->user.uuid, mes.uuid_receiver) == 0 &&
        tmp->user.status == 0)
            tmp = NULL;
        else if (strcmp(tmp->user.uuid, mes.uuid_receiver) == 0 &&
        tmp->user.status != 0)
            break;
    if (tmp != NULL) {
        sd = tmp->user.fd;
        write(sd, message, sizeof(char) * 1024);
        write(sd, &mes, sizeof(messages_t));
    }
    server_event_private_message_sended(mes.uuid_sender,
    mes.uuid_receiver, mes.message);
}

void my_send_message(server_t *server, int sd, messages_t message)
{
    node_t *tmp;
    user_t user;
    int fd = open_db("db/users.db", "Can't connect to Messa database\n\0");

    for (tmp = server->users; tmp != NULL; tmp = tmp->next)
        if (tmp->user.fd == sd) {
            strcpy(message.uuid_sender, tmp->user.uuid);
            break;
        }
    while (read(fd, &user, sizeof(user_t)) > 0)
        if (strcmp(user.uuid, message.uuid_receiver) == 0)
            return (write_message(server, sd, message));
    memset(message.uuid_receiver, '\0', 37);
    strcpy(message.uuid_receiver, "unknown\0");
    write(sd, &message, sizeof(messages_t));
}

void my_send(server_t *server, int sd)
{
    messages_t message;
    messages_t error;

    read(sd, &message, sizeof(messages_t));
    memset(error.uuid_receiver, '\0', 37);
    strcpy(error.uuid_receiver, "null\0");
    if (check_connect(server->users, &error, sizeof(messages_t), sd) == 1)
        return;
    my_send_message(server, sd, message);
}