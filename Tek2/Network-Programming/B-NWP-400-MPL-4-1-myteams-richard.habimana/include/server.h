/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include "common.h"
#include "logging_server.h"
#include <uuid/uuid.h>

#define MAX_SIZE 100

typedef struct connected_s {
    int fd;
    char *username;
    bool connected;
    bool passif;
    int server_fd;
    struct sockaddr_in address;
    int passif_fd;
    fd_set read_fd_set;
    int opt;
} connected_t;

typedef struct command_s {
    char *command;
    char *body;
}command_t;

typedef struct funct_s {
    char *command;
    connected_t (*ptr)(char *line, connected_t command);
}funct_t;

typedef struct node_s {
    user_t user;
    struct node_s *next;
}node_t;

typedef struct server_s {
    int server_fd;
    int valread;
    struct sockaddr_in address;
    int opt;
    int addrlen;
    char *buffer;
    fd_set read_fd_set;
    connected_t sockerFdNew[MAX_SIZE];
    node_t *users;
    int nb_users;
    int maxFd;
    int activity;
    int sd;
    int i;
    char *buff;
    char *tmp;
    int finish;
    int fdUsers;
    int fdMessages;
} server_t;

typedef struct functCreate_s {
    enum useType use;
    void (*ptr)(server_t *server, int sd);
} functCreate_t;

typedef struct functList_s {
    enum useType use;
    void (*ptr)(server_t *server, int sd);
} functList_t;

connected_t fill_username(char *user, connected_t command);
command_t get_commands(char *l);
connected_t modify_command(char *line, connected_t com);
void init_server_struct(server_t *server);
void check_errors(int ac);
void init_server(server_t *server, char **av);
server_t read_file(server_t server);
void close_fd(server_t *server, int pos);
void set_socket_struct(server_t *server, int i);
int update_user_db(char *name, int status);
user_t set_user(int fd, int status, char *username, char *uuid);
int check_connect(node_t *head, void *send, size_t size, int sd);
void destruct_server();
void init_fd(server_t *server);
void accept_new_connection(server_t *server);
void core_server(server_t *server, int sd, int pos);
void loop(server_t *server, char recvBuf[1024]);
int open_db(char *path, char *writing);
void send_end_to_everyone(server_t *s, int sd, node_t *res);
void write_user(char uuid[37], int sd);
int check_sub(char userUuid[37], char teamUuid[37]);
int check_list_replys(int size, int sd, reply_t reply);
int info_check_channel(info_t info, int sd, void *send, size_t size);
void my_info_reply_two(int sd, info_t info);
int info_check_team(info_t info, int sd, void *send, size_t size);

void my_help(server_t *server, int sd);
void my_login(server_t *server, int sd);
void my_logout(server_t *server, int sd);
void my_users(server_t *server, int sd);
void my_user(server_t *server, int sd);
void my_use(server_t *server, int sd);
void my_send(server_t *server, int sd);
void my_messages(server_t *server, int sd);
void my_create(server_t *server, int sd);
void my_list(server_t *server, int sd);
void my_subscribe(server_t *server, int sd);
void my_subscribed(server_t *server, int sd);
void my_unsubscribe(server_t *server, int sd);
void my_info(server_t *server, int sd);

void my_create_team(server_t *server, int sd);
void my_create_channel(server_t *server, int sd);
void my_create_thread(server_t *server, int sd);
void my_create_reply(server_t *server, int sd);

void my_list_team(server_t *server, int sd);
void my_list_channel(server_t *server, int sd);
void my_list_thread(server_t *server, int sd);
void my_list_reply(server_t *server, int sd);

void my_info_team(server_t *server, int sd);
void my_info_channel(server_t *server, int sd);
void my_info_thread(server_t *server, int sd);
void my_info_reply(server_t *server, int sd);

int check_team_list(char uuid[37]);
int check_channel_list(char uuid[37]);
int check_thread_list(char uuid[37]);

typedef struct functServer_s {
    enum command received;
    void (*ptr)(server_t *server, int sd);
} functServer_t;

#endif /* !SERVER_H_ */