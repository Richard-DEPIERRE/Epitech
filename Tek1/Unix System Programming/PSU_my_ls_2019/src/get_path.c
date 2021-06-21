/*
** EPITECH PROJECT, 2020
** get_path
** File description:
** get path for folders
*/

#include "my_ls.h"

int check_op(char *str, begin_t *begin)
{
    for (int i = 1; str[i]; i += 1) {
        if (str[i] == 'l')
            begin->l_flag += 1;
        if (str[i] == 'R')
            begin->r_flag += 1;
        if (str[i] == 't')
            begin->t_flag += 1;
    }
    if (begin->l_flag > 1 || begin->t_flag > 1 || begin->r_flag > 1)
        return (1);
    else
        return (0);
}

int get_path(int ac, char **av, begin_t *begin)
{
    begin->l_flag = 0;
    begin->r_flag = 0;
    begin->t_flag = 0;

    for (int i = 1; i < ac; i += 1) {
        if (av[i][0] == '-' && check_op(av[i], begin) == 1)
            return (84);
        else if (av[i][0] != '-')
            begin->folders = my_strcpy_mod(begin->folders, av[i]);
    }
    return (0);
}

long long get_month2(char *str)
{
    if (str[4] == 'J' && str[6] == 'l')
        return (7);
    if (str[4] == 'A' && str[5] == 'u')
        return (8);
    if (str[4] == 'S')
        return (9);
    if (str[4] == 'O')
        return (10);
    if (str[4] == 'N')
        return (11);
    if (str[4] == 'D')
        return (12);
    return (0);
}