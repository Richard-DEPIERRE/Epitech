/*
** EPITECH PROJECT, 2019
** error
** File description:
** error for sokoban
*/

#include "sokoban.h"

void h_text(void)
{
    write(1, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t", 37);
    write(1, "map file representing the warehouse map", 39);
    write(1, ", containing ‘#’ for walls, \n\t\t'P’ for the player", 48);
    write(1, ", ‘X’ for boxes and ‘O’ for storage locations.\n\0", 56);
}

void check_chars(main_t *w)
{
    for (int i = 0; w->map.str[i]; i += 1) {
        if (w->map.str[i] != 'O' &&
        w->map.str[i] != 'X' &&
        w->map.str[i] != ' ' &&
        w->map.str[i] != 'P' &&
        w->map.str[i] != '#' &&
        w->map.str[i] != '\n')
            w->return_nb = 84;
    }
}

void check_nb_O_X(main_t *w)
{
    int nb_O = 0;

    for (int i = 0; w->map.str[i]; i += 1) {
        if (w->map.str[i] == 'O')
            nb_O += 1;
        if (w->map.str[i] == 'X')
            nb_O -= 1;
    }
    if (nb_O > 0)
        w->return_nb = 84;
}

void check_errors(int ac, char **av, int *errors, main_t *screen)
{
    int fd = 0;
    struct stat fileStat;
    int a = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        h_text();
        *errors = 2;
    } else {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            *errors = 84;
        if (stat(av[1], &fileStat) < 0)
            *errors = 84;
        screen->map.str = malloc(sizeof(char) * (fileStat.st_size + 1));
        screen->map.size = fileStat.st_size;
        a = read(fd, screen->map.str, fileStat.st_size);
        screen->map.str[fileStat.st_size] = '\0';
        if (a == 84)
            *errors = 84;
        check_chars(screen);
        check_nb_O_X(screen);
    }
}