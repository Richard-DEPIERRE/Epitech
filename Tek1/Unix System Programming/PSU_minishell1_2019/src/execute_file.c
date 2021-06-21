/*
** EPITECH PROJECT, 2020
** execute_file
** File description:
** execute file
*/

#include "minishell.h"

void check_execution(minishell_t *mini, char **env, int i)
{
    if (execve(my_strcat(my_strcat(mini->envi[i], "/"),
    mini->table[0]), mini->table, env) == -1 && errno != ENOEXEC)
        write(1, my_strcat(mini->table[0], ": Permission denied.\n"),
        my_strlength(mini->table[0]) + 21);
    if (errno == ENOEXEC)
        write(1, my_strcat(mini->table[0],
        ": Exec format error. Wrong Architecture.\n"),
        my_strlength(mini->table[0]) + 41);
}

void execute_binaries(minishell_t *mini, char **env)
{
    if (access(mini->table[0], X_OK) == 0) {
        if (execve(mini->table[0], mini->table, env) == - 1 && errno != ENOEXEC)
            write(1, my_strcat(mini->table[0], ": Permission denied.\n"),
            my_strlength(mini->table[0]) + 21);
        if (errno == ENOEXEC)
            write(1, my_strcat(mini->table[0],
            ": Exec format error. Wrong Architecture.\n"),
            my_strlength(mini->table[0]) + 41);
    } else
        write(1, my_strcat(mini->table[0], ": Command not found.\n"),
        my_strlength(mini->table[0]) + 21);
}

void execute_command(minishell_t *mini, char **env)
{
    for (int i = 0; mini->envi[i]; i += 1)
        if (access(my_strcat(my_strcat(mini->envi[i], "/"),
        mini->table[0]), X_OK) == 0) {
            check_execution(mini, env, i);
        }
    execute_binaries(mini, env);
}

int check_errors2(int error)
{
    if (error != 0) {
        if (error == 11)
            write(1, "Segmentation fault\n", 19);
        if (error == 136 || error == 8)
            write(1, "Floating exception\n", 19);
    }
    return (0);
}

void execute_file(minishell_t *mini, char **env)
{
    if (mini->tmp == 0) {
        if (fork() == 0)
            execute_command(mini, env);
        else
            wait(&mini->execute_error);
    }
    check_errors2(mini->execute_error);
}