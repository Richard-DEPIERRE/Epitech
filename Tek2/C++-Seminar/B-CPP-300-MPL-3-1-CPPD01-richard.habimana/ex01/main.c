/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** menger
*/

#include "menger.h"

int my_getnbr(char const *str)
{
    int minus_count = 0;
    int i = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i += 1) {
        if (str[i] == '-')
            minus_count += 1;
    }
    for (; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            break;
        nb = nb * 10 + (str[i] - 48);
    }
    if (minus_count % 2 == 1)
        nb = nb * (-1);
    return (nb);
}

int check_errors(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) < 0 || my_getnbr(av[1]) % 3 != 0)
        return (84);
    if (my_getnbr(av[2]) < 0 || my_getnbr(av[2]) > my_getnbr(av[1]) / 3)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (check_errors(ac, av) == 84)
        return (84);
    meng(my_getnbr(av[1]) / 3, my_getnbr(av[2]), 0, 0);
    return (0);
}