/*
** EPITECH PROJECT, 2020
** functions
** File description:
** main functions
*/

#include "matchsticks.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnbr(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
    }
    nb = nb % 10;
    my_putchar(nb + 48);
    return (0);
}

int get_int(char *str)
{
    int minus_count = 0;
    int i = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i += 1) {
        if (str[i] == '-')
            minus_count += 1;
    }
    for (; str[i] != '\0'; i += 1) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
            return (-2147483646);
        if (str[i] == '\n')
            break;
        nb = nb * 10 + (str[i] - 48);
    }
    if (minus_count % 2 == 1)
        nb = nb * (-1);
    return (nb);
}

void get_matches_2(information_t *player, char **map, int max)
{
    if (player->nb_matches <= 0) {
        if (player->nb_matches > -2147483646 && player->nb_matches <= 0) {
            write(1, "Error: you have to remove at least one match", 44);
            write(1, "\nLine: ", 7);
        }
        if (player->nb_matches == -2147483646) {
            write(1, "Error: invalid input (positive number expected)", 47);
            write(1, "\nLine: ", 7);
        }
    } else if (player->nb_matches > max) {
        write(1, "Error: you cannot remove more than ", 35);
        my_putnbr(max);
        write(1, " matches per turn\nLine:", 23);
    } else
        if (check_line(player->line, player->nb_matches, map) == 1) {
            write(1, "Error: not enough matches on this line\nLine: ", 45);
        } else
            player->tmp = 0;
}