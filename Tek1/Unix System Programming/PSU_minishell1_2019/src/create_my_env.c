/*
** EPITECH PROJECT, 2020
** create_my_env
** File description:
** creates an env if not created
*/

#include "minishell.h"

char **create_my_env(void)
{
    char **env = malloc(sizeof(char *) * 5);

    env[0] = "PATH=";
    env[1] = "PWD=";
    env[2] = "OLDPWD=";
    env[3] = "HOME=/";
    env[4] = NULL;
    return (env);
}