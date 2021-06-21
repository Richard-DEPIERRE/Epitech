/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** main file for palindrome
*/

#include "palindrome.h"

int palindrome2(char one, char two, int letters, int add)
{
    if (one >= letters && one <= letters + 25)
        if (one != two && one + add != two) {
            write(1, "not a palindrome.\n", 18);
            return (1);
        }
    return (0);
}

int palindrome(int ac, char **av)
{
    int size = 0;
    int j = 0;

    if (ac != 2) {
        write(2, "Error: missing arguments.\n", 26);
        return (84);
    }
    for (; av[1][size]; size += 1);
    j = size - 1;
    for (int i = 0; i < j; i += 1) {
        if (palindrome2(av[1][i], av[1][j], 65, 32) == 1)
            return (0);
        else if (palindrome2(av[1][i], av[1][j], 97, -32) == 1)
            return (0);
        j -= 1;
    }
    write(1, "palindrome!\n", 12);
    return (0);
}
