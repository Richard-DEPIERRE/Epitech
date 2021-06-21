/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** subscribe
*/

#include "server.h"

int get_link_number(void)
{
    int fd = open_db("db/links.db", "Can’t open Links database\n\0");
    int size = 0;
    link_t link;

    for (; read(fd, &link, sizeof(link_t)) > 0; size++);
    close(fd);
    return (size);
}

void my_unsubscribe_three(link_t link, int sd, link_t *links, int num)
{
    int fdLinks = open("db/links.db", O_WRONLY | O_CREAT | O_TRUNC);
    if (fdLinks == -1) {
        write(2, "Can't open links database\n\0", 27);
        exit(84);
    }
    for (int i = 0; i < num; i++)
        write(fdLinks, &(links[i]), sizeof(link_t));
    write(sd, &link, sizeof(link_t));
    server_event_user_unsubscribed(link.team_uuid, link.user_uuid);
    close(fdLinks);
}

void my_unsubscribe_two(server_t *server, int sd,
link_t *links, char uuid[37])
{
    int num = get_link_number();
    char uuidUser[37];
    link_t link;

    for (node_t *tmp = server->users; tmp; tmp = tmp->next)
        if (tmp->user.fd == sd)
            strcpy(uuidUser, tmp->user.uuid);
    for (int i = 0; i < num; i++)
        if (strcmp(links[i].team_uuid, uuid) == 0 &&
        strcmp(links[i].user_uuid, uuidUser) == 0) {
            strcpy(link.team_uuid, links[i].team_uuid);
            strcpy(link.user_uuid, links[i].user_uuid);
            strcpy(links[i].team_uuid, "null\0");
            strcpy(links[i].user_uuid, "null\0");
        }
    my_unsubscribe_three(link, sd, links, num);
}

void my_unsubscribe(server_t *server, int sd)
{
    char uuid[37];
    link_t link;
    int num = get_link_number();
    link_t *links = malloc(sizeof(link_t) * num);
    int fdLinks = open_db("db/links.db", "Can’t open Link database\n\0");

    memset(uuid, '\0', 37);
    memset(link.user_uuid, '\0', 37);
    strcpy(link.user_uuid, "null\n\0");
    read(sd, uuid, sizeof(char) * 37);
    if (check_connect(server->users,  &link, sizeof(link_t), sd) == 1)
        return;
    for (int i = 0; read(fdLinks, &(links[i]), sizeof(team_t)) > 0; i++);
    close(fdLinks);
    my_unsubscribe_two(server, sd, links, uuid);
}