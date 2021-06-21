/*
** EPITECH PROJECT, 2019
** errors
** File description:
** error file
*/

#include "my_hunter.h"

void h_txt(int ac, char **av, int *error)
{
    int fd = 0;
    const char c = '\n';
    int size = 900;
    char *buffer;

    if (av[1][0] == '-' && av[1][1] == 'h') {
        fd = open("images/h_file.txt", O_RDONLY);
        buffer = malloc(sizeof(char) * (size + 3));
        read(fd, buffer, size);
        write(1, buffer, size - 1);
        write(1, &c, 1);
        *error = 0;
    } else
        errors(ac, error);
}

void errors(int ac, int *error)
{
    if (ac != 1) {
        write(1, "Invalid input\n\'./my hunter -h\' for more information\0"\
        , 52);
        *error = 84;
    }
}