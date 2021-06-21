/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

void check_letters(char **table, char **table2, order_t *order)
{
    for (char c = order->one; c <= order->two; c += 1)
        temporary_one(table, table2, c, order);
}

char **sort_table(char **table, char **table2)
{
    order_t order;
    order.a = 0;
    order.tmp = 0;
    order.pos = 0;

    order.one = '0';
    order.two = '9';
    check_letters(table, table2, &order);
    order.one = 'A';
    order.two = 'Z';
    check_letters(table, table2, &order);
    order.one = 'a';
    order.two = 'z';
    check_letters(table, table2, &order);
    return (table2);
}

char **open_dir(char **table, char **table2)
{
    DIR *dir;
    struct dirent *sd;
    int i = 0;

    dir = opendir("tetriminos");
    while ((sd = readdir(dir)) != 0)
        if (sd->d_name[0] != '.' &&
        sd->d_name[my_strlength(sd->d_name) - 1] == 'o' &&
        sd->d_name[my_strlength(sd->d_name) - 2] == 'n' &&
        sd->d_name[my_strlength(sd->d_name) - 3] == 'i' &&
        sd->d_name[my_strlength(sd->d_name) - 4] == 'm' &&
        sd->d_name[my_strlength(sd->d_name) - 5] == 'i' &&
        sd->d_name[my_strlength(sd->d_name) - 6] == 'r' &&
        sd->d_name[my_strlength(sd->d_name) - 7] == 't') {
            table[i] = malloc(sizeof(char) * (my_strlength(sd->d_name) + 1));
            table[i][my_strlength(sd->d_name)] = '\0';
            table[i] = my_strcpy(sd->d_name, table[i]);
            i += 1;
        }
    return (sort_table(table, table2));
}

int print_tetriminos2(int tmp, tetris_t *tetris, bin_t *play)
{
    char **str;
    char **str2;

    tetris->tetriminos = malloc(sizeof(tetriminos_t) * (tmp + 1));
    tetris->tetriminos[tmp].tetri = NULL;
    if (tetris->keys[10].name) {
        write(1, "Tetriminos : ", 13);
        my_put_nbr(tmp);
        write(1, "\n", 1);
    }
    str = malloc(sizeof(char *) * (tmp + 1));
    for (int i = 0; i <= tmp; i += 1)
        str[i] = NULL;
    str2 = malloc(sizeof(char *) * (tmp + 1));
    for (int i = 0; i <= tmp; i += 1)
        str2[i] = NULL;
    str2 = open_dir(str, str2);
    for (int i = 0; str2[i]; i += 1)
        if (get_map(my_strcat("tetriminos/", str2[i]), str2[i], tetris, play) == 84)
            return (84);
    return (0);
}

int print_tetriminos(int tmp, tetris_t *tetris, bin_t *play)
{
    DIR *dir;
    struct dirent *sd;
    static int a = 0;

    a += 1;
    if (!(dir = opendir("tetriminos")))
        exit(84);
    while ((sd = readdir(dir)) != 0)
        if (sd->d_name[0] != '.' && sd->d_name[my_strlength(sd->d_name) - 1]
        == 'o' && sd->d_name[my_strlength(sd->d_name) - 2] == 'n' && sd->d_name
        [my_strlength(sd->d_name) - 3] == 'i' && sd->d_name[my_strlength
        (sd->d_name) - 4] == 'm' && sd->d_name[my_strlength(sd->d_name) - 5]
        == 'i' && sd->d_name[my_strlength(sd->d_name) - 6] == 'r' &&
        sd->d_name[my_strlength(sd->d_name) - 7] == 't')
            tmp += 1;
    if (tmp == 0)
        exit(84);
    if (a == 1)
        return (0);
    return (print_tetriminos2(tmp, tetris, play));
}