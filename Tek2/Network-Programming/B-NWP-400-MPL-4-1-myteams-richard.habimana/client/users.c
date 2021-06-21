/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-richard.habimana
** File description:
** users
*/

#include "client.h"

void my_users(int sd, char *buff, client_t *client UNUSED)
{
    int num = 0;
    user_t user;

    (void)buff;
    read(sd, &num, sizeof(int));
    if (num == -1) {
        client_error_unauthorized();
        return;
    }
    for (int i = 0; i < num; i++) {
        read(sd, &user, sizeof(user));
        client_print_users(user.uuid, user.username, user.status);
    }
}

char *get_user(char *buff)
{
    int i = 0;
    int size = 0;
    char *user;

    for (i = 0; buff[i] && buff[i] != 34; i++);
    if (!buff[i])
        return (NULL);
    i++;
    for (size = 0; buff[i + size] != 34 && buff[i + size]; size++);
    if (!buff[i + size])
        return (NULL);
    user = malloc(sizeof(char) * (size + 1));
    for (size = 0; buff[i + size] != 34 && buff[i + size]; size++) {
        user[size] = buff[i + size];
    }
    user[size] = '\0';
    return (user);
}

void my_user(int sd, char *buff, client_t *client UNUSED)
{
    user_t userBuff;
    char *user = get_user(buff);

    if (user == NULL) {
        free(user);
        return;
    }
    write(sd, user, 37);
    read(sd, &userBuff, sizeof(user_t));
    if (strcmp(userBuff.uuid, "null\0") == 0)
        client_error_unauthorized();
    else if (strcmp(userBuff.uuid, "unknown\0") == 0)
        client_error_unknown_user(get_user(buff));
    else
        client_print_user(userBuff.uuid, userBuff.username, userBuff.status);
    free(user);
}