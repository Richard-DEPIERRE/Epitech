/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-richard.habimana
** File description:
** help
*/

#include "server.h"

server_t init_server_two(server_t server, char **av)
{
    server.address.sin_family = AF_INET;
    server.address.sin_addr.s_addr = INADDR_ANY;
    server.address.sin_port = htons(atoi(av[1]));
    if (bind(server.server_fd, (struct sockaddr *)&server.address,
    sizeof(server.address))<0) {
        perror("bind failed");
        exit(84);
    }
    printf("Server port: %s\nPath : %s\nUse ^C to QUIT.\n", av[1], av[2]);
    if (listen(server.server_fd, 42) < 0) {
        perror("listen");
        exit(84);
    }
    return server;
}

server_t init_server(server_t server, char **av)
{
    server.server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.server_fd == 0) {
        perror("socket failed");
        exit(84);
    }
    if ( setsockopt(server.server_fd, SOL_SOCKET, SO_REUSEADDR,
    (char *)&server.opt, sizeof(server.opt)) < 0 ){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    return init_server_two(server, av);
}