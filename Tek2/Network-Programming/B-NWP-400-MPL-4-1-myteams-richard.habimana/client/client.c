/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** client
*/

#include "client.h"

static sending_enum_t sendingEnum[] = {
    {"/help", HELP},
    {"/login", LOGIN},
    {"/logout", LOGOUT},
    {"/users", USERS},
    {"/user", USER},
    {"/send", SEND},
    {"/messages", MESSAGES},
    {"/use", USE},
    {"/create", CREATE},
    {"/list", LIST},
    {"/subscribe", SUBSCRIBE},
    {"/subscribed", SUBSCRIBED},
    {"/unsubscribe", UNSUBSCRIBE},
    {"/info", INFO}
};

static functClient_t functClient[] = {
    {HELP, my_help},
    {LOGIN, my_login},
    {LOGOUT, my_logout},
    {USERS, my_users},
    {USER, my_user},
    {SEND, my_send},
    {MESSAGES, my_messages},
    {USE, my_use},
    {CREATE, my_create},
    {LIST, my_list},
    {SUBSCRIBE, my_subscribe},
    {SUBSCRIBED, my_subscribed},
    {UNSUBSCRIBE, my_unsubscribe},
    {INFO, my_info}
};

static functReceived_t functReceived[] = {
    {"/quit\n\0", r_quit},
    {"message\n\0", r_message},
    {"connect\n\0", r_connect},
    {"disconnect\n\0", r_disconnect},
    {"team\n\0", r_team},
    {"channel\n\0", r_channel},
    {"thread\n\0", r_thread},
    {"reply\n\0", r_reply},
};

client_t init_client(client_t client, int ac, char **av)
{
    if (ac != 3)
        exit(84);
    if ((client.socketId = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        exit(-1);
    client.server.sin_addr.s_addr = inet_addr(av[1]);
    client.server.sin_family = AF_INET;
    client.server.sin_port = htons(atoi(av[2]));
    client.max_sd = 0;
    client.use = GLOBAL;
    memset(client.teamuuid, '\0', 37);
    memset(client.channeluuid, '\0', 37);
    memset(client.teamuuid, '\0', 37);
    if (connect(client.socketId, (struct sockaddr *)&client.server,
    sizeof(client.server)) < 0)
        exit(-1);
    return (client);
}

client_t read_input(client_t client)
{
    size_t size = 1024;
    char *buffer = malloc(sizeof(char) * 1024);

    memset(buffer, '\0', 1024);
    client.ret = getline(&buffer, &size, stdin);
    if (client.ret <= 0) {
        client.type = LOGOUT;
        write(client.sd, &client.type, sizeof(enum command));
        my_logout(client.sd, buffer, &client);
        exit(0);
    }
    for (int i = 0; i < 14; i++)
        if (mystrcmp(sendingEnum[i].command, buffer) == 0) {
            client.type = sendingEnum[i].sending;
            write(client.sd, &client.type, sizeof(enum command));
            functClient[i].ptr(client.sd, buffer, &client);
        }
    return (client);
}

void sent_by_server(client_t *client)
{
    memset(client->recvBuf, '\0', 1024);
    if (read(client->socketId, client->recvBuf, 1024) <= 0)
        exit(0);
    for (int i = 0; i < 8; i++)
        if (strcmp(client->recvBuf, functReceived[i].message) == 0)
            functReceived[i].ptr(client->socketId);
}

void reinit_client(client_t *client)
{
    FD_ZERO(&client->readfds);
    FD_SET(client->socketId, &client->readfds);
    FD_SET(0, &client->readfds);
    memset(client->recvBuf, '\0', 1024);
    client->max_sd = (client->max_sd > client->socketId) ? client->max_sd :
    client->socketId;
    client->max_sd = (client->max_sd > 0) ? client->max_sd : 0;
    client->ret = select(client->max_sd + 1, &client->readfds,
    NULL, NULL, NULL);
    if (client->ret < 0)
        exit(84);
    client->sd = client->socketId;
}

int main(int ac, char **av)
{
    client_t client;

    client = init_client(client, ac, av);
    while (1) {
        reinit_client(&client);
        if (FD_ISSET(client.socketId, &client.readfds))
            sent_by_server(&client);
        if (FD_ISSET(0, &client.readfds))
            client = read_input(client);
    }
    return (client.ret);
}