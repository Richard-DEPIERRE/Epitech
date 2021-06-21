/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** message
*/

#include "client.h"

char *get_uuid_message(char *buff)
{
    char *uuid;
    int i = 0;
    int size = 0;

    for (i = 0; buff[i] && buff[i] != 34; i++);
    if (!buff[i])
        return (NULL);
    i++;
    for (size = 0; buff[i + size] != 34 && buff[i + size]; size++);
    if (!buff[i + size])
        return (NULL);
    uuid = malloc(sizeof(char) * (size + 1));
    for (size = 0; buff[i + size] != 34 && buff[i + size]; size++) {
        uuid[size] = buff[i + size];
    }
    uuid[size] = '\0';
    return (uuid);
}

void my_messages(int sd, char *buff, client_t *client UNUSED)
{
    int a = 0;
    messages_t message;
    char *uuid = get_uuid_message(buff);

    if (uuid == NULL) {
        free(uuid);
        return;
    }
    write(sd, uuid, 37);
    read(sd, &a, sizeof(int));
    if (a == -1)
        client_error_unauthorized();
    if (a == -2)
        client_error_unknown_user(uuid);
    for (int i = 0; i < a; i++) {
        read(sd, &message, sizeof(messages_t));
        client_private_message_print_messages(message.uuid_sender,
        message.timestamp, message.message);
    }
    free(uuid);
}