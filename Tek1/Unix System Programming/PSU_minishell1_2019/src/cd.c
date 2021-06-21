/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd file
*/

#include "minishell.h"

void change_environment(minishell_t *mini, char *oldpwd)
{
    node_t *tmp = mini->head;
    node_t *tmp2 = mini->head;
    char *str = NULL;

    if (oldpwd) {
        while (my_strcmp("OLDPWD", tmp->name) != 0 && tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->str = my_strcpy(oldpwd, tmp->str);
    }
    while (my_strcmp("PWD", tmp2->name) != 0 && tmp2->next != NULL) {
        tmp2 = tmp2->next;
    }
    for (int i = 1; str == NULL; i += 1) {
        str = malloc(sizeof(char) * i);
        str = getcwd(str, i);
    }
    tmp2->str = my_strcpy(tmp2->str, str);
}

char *base_for_cd(char *oldpwd, minishell_t *mini)
{
    char *str = NULL;

    for (int i = 1; str == NULL; i += 1) {
        str = malloc(sizeof(char) * i);
        str = getcwd(str, i);
    }
    oldpwd = my_strcpy(str, oldpwd);
    if (chdir(mini->table[1]) == -1)
        write(1, my_strcat(mini->table[1], ": Not a directory.\n"),
        my_strlength(mini->table[1]) + 19);
    return (oldpwd);
}

char *cd_minus(char *oldpwd)
{
    char *str = NULL;

    if (!oldpwd)
        write(1, ": No such file or directory.\n", 29);
    else {
        for (int i = 1; str == NULL; i += 1) {
            str = malloc(sizeof(char) * i);
            str = getcwd(str, i);
        }
        if (chdir(oldpwd) == -1)
            write(1, my_strcat(oldpwd, ": Not a directory.\n"),
            my_strlength(oldpwd) + 19);
        oldpwd = my_strcpy(str, oldpwd);
    }
    return (oldpwd);
}

char *cd_with_no_arguments(char *oldpwd, char *home)
{
    char *str = NULL;

    if (home) {
        for (int i = 1; str == NULL; i += 1) {
            str = malloc(sizeof(char) * i);
            str = getcwd(str, i);
        }
        oldpwd = my_strcpy(str, oldpwd);
        if (chdir(home) == -1)
            write(1, my_strcat(home, ": Not a directory.\n"),
            my_strlength(home) + 19);
    } else
        write(1, "cd: No home directory.\n", 23);
    return (oldpwd);
}

void cd_function(minishell_t *mini)
{
    static char *oldpwd = NULL;
    static char *home = NULL;
    node_t *tmp = mini->head;

    mini->tmp = 1;
    if (!home) {
        while (my_strcmp("HOME", tmp->name) != 0 && tmp->next != NULL) {
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
            home = my_strcpy(tmp->str, home);
    }
    if (!mini->table[1])
        oldpwd = cd_with_no_arguments(oldpwd, home);
    else if (mini->table[1][0] == '-')
        oldpwd = cd_minus(oldpwd);
    else
        oldpwd = base_for_cd(oldpwd, mini);
    change_environment(mini, oldpwd);
}