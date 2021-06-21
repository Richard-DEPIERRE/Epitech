/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

char *check_char(char *str, int *tmp)
{
    if (!str[0]) {
        *tmp = 84;
        write(1, "Bad Parameter\n", 14);
    }
    if (my_strcmp(str, " ") == 0) {
        str = my_strcpy("(space)\0", str);
    }
    return (str);
}

void check_map_size(char *str, int *tmp)
{
    int i = 0;

    for (; str[i] != ',' && str[i]; i += 1)
        if (str[i] < '0' || str[i] > '9' || !str[i]) {
            *tmp = 84;
            write(1, "Bad Parameter\n", 14);
            return;
        }
    if (!str[i]) {
        *tmp = 84;
        write(1, "Bad Parameter\n", 14);
        return;
    }
    i += 1;
    for (; str[i]; i += 1)
        if (str[i] < '0' || str[i] > '9') {
            *tmp = 84;
            write(1, "Bad Parameter\n", 14);
        }
}

void check_keys(keys_t *keys, int *tmp)
{
    if (my_strcmp(keys->name, "key-left") == 0 ||
    my_strcmp(keys->name, "key-right") == 0 ||
    my_strcmp(keys->name, "key-turn") == 0 ||
    my_strcmp(keys->name, "key-drop") == 0 ||
    my_strcmp(keys->name, "key-quit") == 0 ||
    my_strcmp(keys->name, "key-pause") == 0) {
        keys->str = check_char(keys->str, tmp);
    }
    for (int i = 0; keys->str[i] && my_strcmp(keys->name,
    "level") == 0; i += 1)
        if ((keys->str[0] <= '0' || keys->str[0] > '9') && !keys->str[1]) {
            *tmp = 84;
            write(1, "Bad Parameter\n", 14);
        } else if (keys->str[i] < '0' || keys->str[i] > '9') {
            *tmp = 84;
            write(1, "Bad Parameter\n", 14);
        }
    if (my_strcmp(keys->name, "map-size") == 0)
        check_map_size(keys->str, tmp);
}

void check_errors(tetris_t *tetris, int *tmp)
{
    for (int i = 0; i < 12; i += 1)
        if (tetris->keys[i].name)
            check_keys(&tetris->keys[i], tmp);
}

int main(int ac, char **av)
{
    tetris_t tetris;
    bin_t *play = malloc(sizeof(bin_t));
    tetris.tmp = 0;
    play->tetriminos = NULL;
    int ch;

    tetris.keys = malloc(sizeof(keys_t) * 12);
    get_opt(ac, av, &tetris);
    check_errors(&tetris, &tetris.tmp);
    if (tetris.keys[7].name || tetris.tmp == 84) {
        print_help(av[0]);
        return (tetris.tmp);
    }
    print_tetriminos(0, &tetris, play);
    if (tetris.keys[10].name) {
        if (debug_tetris(&tetris, play) == 84)
            return (84);
        my_getch();
    } else
        if (print_tetriminos(0, &tetris, play) == 84)
            return (84);
    game_start(&tetris, play);
    return (0);
}