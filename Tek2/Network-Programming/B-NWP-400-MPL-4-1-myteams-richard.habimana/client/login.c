/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** login
*/

#include "client.h"

void my_login(int sd, char *buff, client_t *client UNUSED)
{
    int i = 0;
    int size = 0;
    char *user;
    user_t userType;
    for (i = 0; buff[i] && buff[i] != 34; i++);
    if (!buff[i])
        return;
    i++;
    for (size = 0; buff[i + size] != 34 && buff[i + size]; size++);
    if (!buff[i + size])
        return;
    user = malloc(sizeof(char) * (size + 1));
    for (size = 0; buff[i + size] != 34 && buff[i + size]; size++) {
        user[size] = buff[i + size];
    }
    user[size] = '\0';
    write(sd, user, size);
    read(sd, &userType, sizeof(user_t));
    if (strcmp(userType.uuid, "null\0") != 0)
        client_event_logged_in(userType.uuid, userType.username);
    free(user);
}

void my_logout(int sd, char *buff UNUSED, client_t *client UNUSED)
{
    user_t userType;

    read(sd, &userType, sizeof(user_t));
    if (strcmp(userType.uuid, "null\0") != 0)
        client_event_logged_out(userType.uuid, userType.username);
    else
        client_error_unauthorized();
    exit(0);
}
