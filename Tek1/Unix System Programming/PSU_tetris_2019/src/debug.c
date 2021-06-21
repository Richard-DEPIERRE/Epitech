/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

void print_debug2(tetris_t *tetris, int nb)
{
    for (int i = 0; tetris->keys[nb].str[i]; i += 1) {
        if (tetris->keys[nb].str[i] == ',')
            write(1, "*", 1);
        else
            write(1, &tetris->keys[nb].str[i], 1);
    }

}

void print_debug(tetris_t *tetris, char *str1, int nb, char *str2)
{
    write(1, str1, my_strlength(str1));
    if (my_strcmp("Size", str1) == 0 && tetris->keys[nb].name) {
        print_debug2(tetris, nb);
        write(1, "\n", 1);
        return;
    }
    if (tetris->keys[nb].name)
        write(1, tetris->keys[nb].str, my_strlength(tetris->keys[nb].str));
    else
        write(1, str2, my_strlength(str2));
    write(1, "\n", 1);
}

int debug_tetris(tetris_t *tetris, bin_t *play)
{
    write(1, "*** DEBUG MODE ***\n", 19);
    print_debug(tetris, "Key Left : ", 1, "^EOD");
    print_debug(tetris, "Key Right : ", 2, "^EOC");
    print_debug(tetris, "Key Turn : ", 3, "^EOA");
    print_debug(tetris, "Key Drop : ", 4, "^EOB");
    print_debug(tetris, "Key Quit : ", 5, "q");
    print_debug(tetris, "Key Pause : ", 9, "(space)");
    write(1, "Next : ", 7);
    if (tetris->keys[8].name)
        write(1, "No\n", 3);
    else
        write(1, "Yes\n", 4);
    print_debug(tetris, "Level : ", 0, "1");
    print_debug(tetris, "Size : ", 6, "20*10");
    if (print_tetriminos(0, tetris, play) == 84)
        return (84);
    write(1, "Press any key to start Tetris\n", 30);
    return (0);
}