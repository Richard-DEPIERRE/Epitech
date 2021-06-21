/*
** EPITECH PROJECT, 2020
** minshell1.c
** File description:
** main for minishell1
*/

#include "minishell.h"

int my_strlength(char *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}

int count_arguments(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i += 1)
        if (str[i] == ' ')
            count += 1;
    return (count);
}

char **parse_string(char *str, minishell_t *mini)
{
    char **table;
    int count = 0;
    int j = 0;

    count = count_arguments(str);
    table = malloc(sizeof(char *) * (count + 2));
    table[count + 1] = NULL;
    mini->nb_arguments = count;
    count = 0;
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == ' ')
            i += 1;
        for (j = 0; str[j + i] != ' ' && str[j + i]; j += 1);
        table[count] = malloc(sizeof(char) * (j + 1));
        for (j = 0; str[j + i] != ' ' && str[j + i]; j += 1)
            table[count][j] = str[j + i];
        table[count++][j--] = '\0';
        i += j;
    }
    return (table);
}

void minishell_end(minishell_t *mini, char **env)
{
    pid_t p_process_id;
    pid_t process_id;
    int error = 0;

    p_process_id = getppid();
    write(1, int_to_char(p_process_id),
    my_strlength(int_to_char(p_process_id)));
    write(1, "\nChild PID: ", 13);
    process_id = getpid();
    write(1, int_to_char(process_id), my_strlength(int_to_char(process_id)));
    write(1, "\n", 1);
    if (fork() == 0)
        execve(mini->table[0], mini->table, env);
    else
        wait(&error);
    write(1, "Program terminated.\nStatus: ", 29);
    if (error >= 130 && error <= 140)
        write(1, "Segmentation Fault\n", 20);
    else
        write(1, "OK\n", 3);
}

int minishell1(int ac __attribute__((unused)), char **av, char **env)
{
    minishell_t mini;
    mini.table;
    mini.nb_arguments;

    mini.table = parse_string(av[1], &mini);
    write(1, "Program name: ", 15);
    write(1, mini.table[0], my_strlength(mini.table[0]));
    write(1, "\nNb args: ", 11);
    write(1, int_to_char(mini.nb_arguments),
    my_strlength(int_to_char(mini.nb_arguments)));
    write(1, "\nPID: ", 7);
    minishell_end(&mini, env);
    return (0);
}