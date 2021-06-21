/*
** EPITECH PROJECT, 2020
** time_order
** File description:
** put everything in time order
*/

#include "my_ls.h"

long long get_month(char *str)
{
    if (str[4] == 'J' && str[5] == 'a')
        return (1);
    if (str[4] == 'F')
        return (2);
    if (str[4] == 'M' && str[6] == 'r')
        return (3);
    if (str[4] == 'A' && str[5] == 'p')
        return (4);
    if (str[4] == 'M' && str[6] == 'y')
        return (5);
    if (str[4] == 'J' && str[6] == 'n')
        return (6);
    return (get_month2(str));
}

long long get_date2(char *str, long long nb)
{
    for (int i = 8; i <= 9; i += 1) {
        if (str[i] == ' ') {
            nb *= 10;
        } else {
            nb *= 10;
            nb += (str[i] - '0');
        }
    }
    for (int i = 11; i < 13; i += 1) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    for (int i = 14; i < 16; i += 1) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    for (int i = 17; i < 19; i += 1) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    return (nb);
}

long long get_date(char *str)
{
    long long nb = 0;

    for (int i = 20; i < 24; i += 1) {
        nb *= 10;
        nb += (str[i] - '0');
    }
    if (get_month(str) < 10) {
        nb *= 10;
        nb += get_month(str);
    } else {
        nb *= 100;
        nb += get_month(str);
    }
    return (nb);
}

long long *get_order(long long *order, char **fd, char *str2)
{
    struct stat sb;
    char *str;
    int count = 0;

    for (int i = 0; fd[i]; i += 1) {
        if (lstat(my_strcat_mod(my_strcat_mod(str2, "/"), fd[i]), &sb) == -1);
        str = ctime(&sb.st_mtime);
        order[count] = get_date(str);
        order[count] = get_date2(str, order[count]);
        count += 1;
    }
    return (order);
}

void put_everything_in_time_order(char **array, char *str)
{
    int counter = 0;
    long long *order;

    for (counter = 0; array[counter]; counter += 1);
    order = malloc(sizeof(long long) * (counter));
    order = get_order(order, array, str);
    array = sort_array(array, order);
}