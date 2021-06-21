/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** send
*/

#include "client.h"

char *get_uuid(char *buff, int *i, int *s)
{
    char *uuid;

    for ((*i) = 0; buff[(*i)] && buff[(*i)] != 34; (*i)++);
    if (!buff[(*i)])
        return (NULL);
    (*i)++;
    for ((*s) = 0; buff[(*i) + (*s)] != 34 && buff[(*i) + (*s)]; (*s)++);
    if (!buff[(*i) + (*s)])
        return (NULL);
    uuid = malloc(sizeof(char) * ((*s) + 1));
    for ((*s) = 0; buff[(*i) + (*s)] != 34 && buff[(*i) + (*s)]; (*s)++) {
        uuid[(*s)] = buff[(*i) + (*s)];
    }
    uuid[*s] = '\0';
    return (uuid);
}

char *get_message_from_buff(char *buff, int *i, int *s)
{
    char *message;

    (*i) += (*s) + 1;
    for (; buff[(*i)] && buff[(*i)] != 34; (*i)++);
    if (!buff[(*i)])
        return (NULL);
    (*i)++;
    for ((*s) = 0; buff[(*i) + (*s)] != 34 && buff[(*i) + (*s)]; (*s)++);
    if (!buff[(*i) + (*s)])
        return (NULL);
    message = malloc(sizeof(char) * ((*s) + 1));
    for ((*s) = 0; buff[(*i)+ (*s)] != 34 && buff[(*i) + (*s)]; (*s)++) {
        message[(*s)] = buff[(*i) + (*s)];
    }
    message[(*s)] = '\0';
    return (message);
}

messages_t *get_message(char *buff)
{
    int i = 0;
    int size = 0;
    time_t timestamp = time(NULL);
    messages_t *messageType = malloc(sizeof(messages_t));
    char *uuid = get_uuid(buff, &i, &size);
    char *message = get_message_from_buff(buff, &i, &size);

    if (uuid == NULL || message == NULL)
        return (NULL);
    localtime(&timestamp);
    strcpy(messageType->uuid_receiver, uuid);
    strcpy(messageType->message, message);
    strcpy(messageType->uuid_sender, "none\0");
    messageType->timestamp = timestamp;
    free(uuid);
    free(message);
    return (messageType);
}

void my_send(int sd, char *buff, client_t *client UNUSED)
{
    messages_t *messageType = get_message(buff);

    if (messageType == NULL) {
        free(messageType);
        return;
    }
    write(sd, messageType, sizeof(messages_t));
    read(sd, messageType, sizeof(messages_t));
    if (strcmp(messageType->uuid_receiver, "unknown\0") == 0)
        client_error_unknown_user(messageType->uuid_sender);
    else if (strcmp(messageType->uuid_receiver, "null\0") == 0)
        client_error_unauthorized();
    free(messageType);
}