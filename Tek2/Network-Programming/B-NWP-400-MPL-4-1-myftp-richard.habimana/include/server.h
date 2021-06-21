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

#define MAX_SIZE 100

typedef struct connected_s {
    int fd;
    char *username;
    char *password;
    char *message;
    char *cwd;
    char *pwd;
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
} funct_t;

typedef struct server_s {
    int server_fd;
    int valread;
    struct sockaddr_in address;
    int opt;
    int addrlen;
    char *buffer;
    fd_set read_fd_set;
    connected_t sockerFdNew[MAX_SIZE];
    int maxFd;
    int activity;
    int sd;
    int i;
    char *buff;
    char *tmp;
    int finish;
} server_t;

connected_t user(char *line, connected_t command);
connected_t password(char *line, connected_t command);
connected_t cwd(char *line, connected_t command);
connected_t cdup(char *line, connected_t command);
connected_t quit(char *line, connected_t command);
connected_t port(char *line, connected_t command);
connected_t pasv(char *line, connected_t command);
connected_t stor(char *line, connected_t command);
connected_t retr(char *line, connected_t command);
connected_t list(char *line, connected_t command);
connected_t delete_file(char *line, connected_t command);
connected_t pwd(char *line, connected_t command);
connected_t help(char *line, connected_t command);
connected_t noop(char *line, connected_t command);
connected_t fill_message(char *message, connected_t command);
connected_t fill_username(char *user, connected_t command);
connected_t fill_password(char *password, connected_t command);
connected_t fill_cwd(char *cwd, connected_t command);
command_t get_commands(char *l);
connected_t modify_command(char *line, connected_t com);
server_t init_server_struct(server_t server, char **av);
void check_errors(int ac);
server_t init_server(server_t server, char **av);
server_t read_file(server_t server);
server_t close_fd(server_t server, int pos);
server_t set_socket_struct(server_t server, char *res, int i);

#endif /* !SERVER_H_ */