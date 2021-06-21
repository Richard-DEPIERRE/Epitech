/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include "common.h"
#include "logging_client.h"

typedef struct sending_enum_s {
    char *command;
    enum command sending;
} sending_enum_t;

typedef struct client_s {
    int max_sd;
    int socketId;
    int sd;
    fd_set readfds;
    int ret;
    char recvBuf[1024];
    struct sockaddr_in server;
    enum command type;
    enum useType use;
    char teamuuid[37];
    char channeluuid[37];
    char threaduuid[37];
} client_t;

typedef struct functClient_s {
    enum command received;
    void (*ptr)(int sd, char *buff, client_t *client);
} functClient_t;

typedef struct functCreate_s {
    enum useType use;
    void (*ptr)(int sd, char *buff, client_t *client);
} functCreate_t;

typedef struct functList_s {
    enum useType use;
    void (*ptr)(int sd, client_t *client);
} functList_t;

typedef struct functReceived_s {
    char message[1024];
    void (*ptr)(int sd);
} functReceived_t;

void my_list_reply_two(int sd, int size, client_t *client);
void my_info_reply_two(client_t *client, thread_t thread);

void my_help(int sd, char *buff, client_t *client);
void my_login(int sd, char *buff, client_t *client);
void my_logout(int sd, char *buff, client_t *client);
void my_users(int sd, char *buff, client_t *client);
void my_user(int sd, char *buff, client_t *client);
void my_send(int sd, char *buff, client_t *client);
void my_messages(int sd, char *buff, client_t *client);
void my_use(int sd, char *buff, client_t *client);
void my_create(int sd, char *buff, client_t *client);
void my_list(int sd, char *buff, client_t *client);
void my_subscribe(int sd, char *buff, client_t *client);
void my_subscribed(int sd, char *buff, client_t *client);
void my_unsubscribe(int sd, char *buff, client_t *client);
void my_info(int sd, char *buff, client_t *client);
int mystrcmp(char *command, char *buff);
void my_help(int sd, char *buff UNUSED, client_t *client UNUSED);

void my_create_team(int sd, char *buff, client_t *client);
void my_create_channel(int sd, char *buff, client_t *client);
void my_create_thread(int sd, char *buff, client_t *client);
void my_create_reply(int sd, char *buff, client_t *client);

void my_list_team(int sd, client_t *client);
void my_list_channel(int sd, client_t *client);
void my_list_thread(int sd, client_t *client);
void my_list_reply(int sd, client_t *client);

void my_info_team(int sd, client_t *client);
void my_info_channel(int sd, client_t *client);
void my_info_thread(int sd, client_t *client);
void my_info_reply(int sd, client_t *client);

void r_quit(int sd);
void r_message(int sd);
void r_connect(int sd);
void r_disconnect(int sd);
void r_team(int sd);
void r_channel(int sd);
void r_thread(int sd);
void r_reply(int sd);
#endif /* !CLIENT_H_ */
