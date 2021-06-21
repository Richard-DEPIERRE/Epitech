/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** use
*/

#include "client.h"

int *change_client(client_t *client, int *i, char *buff, int num[2])
{
    int j = 0;
    char tmp[37];

    (*i)++;
    memset(tmp, '\0', sizeof(char) * 37);
    for (j = 0; buff[(*i) + j] && buff[(*i) + j] != 34; j++)
        tmp[j] = buff[(*i) + j];
    if (num[0] == num[1])
        strcpy(client->teamuuid, tmp);
    if ((num[0] == 4 && num[1] == 6) || (num[0] == 2 && num[1] == 4))
        strcpy(client->channeluuid, tmp);
    if (num[0] == 2 && num[1] == 6)
        strcpy(client->threaduuid, tmp);
    (*i) += j;
    return (num);
}

void my_use(int sd, char *buff, client_t *client)
{
    int num[2] = {0, 0};

    read(sd, &(num[0]), sizeof(int));
    if (num[0] == -1) {
        client_error_unauthorized();
        return;
    }
    for (int i = 0; buff[i]; i++)
        if (buff[i] == 34)
            num[0]++;
    client->use = (enum useType)(num[0] / 2);
    memset(client->teamuuid, '\0', sizeof(char) * 37);
    memset(client->channeluuid, '\0', sizeof(char) * 37);
    memset(client->threaduuid, '\0', sizeof(char) * 37);
    num[1] = num[0];
    for (int i = 0; buff[i]; i++)
        if (buff[i] == 34) {
            change_client(client, &i, buff, num);
            num[0] -= 2;
        }
}