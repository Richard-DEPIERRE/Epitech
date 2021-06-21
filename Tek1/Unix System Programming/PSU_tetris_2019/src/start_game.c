/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tetris.h"

void while_loop_game(tetris_t *tetris, bin_t *play)
{
    while (play->minutes < 25) {
        game_print1();
        game_print2();
        game_print3(play);
        game_print4(play);
        game_print5(tetris, play);
        play->c = getch();
        if (!tetris->keys[5].name) {
            if (play->c == 'a')
                break;
        } else if (play->c == tetris->keys[4].str[0])
            break;
        get_getch(tetris, play);
        refresh();
        wclear(stdscr);
    }
}

void game_start(tetris_t *tetris, bin_t *play)
{
    play->tetriminos2 = NULL;
    for (node_R_t *tmp = play->tetriminos; tmp; tmp = tmp->next)
        tmp->number = -1;
    initialize(play);
    play->t = clock();
    game_init(tetris, play);
    game_create(tetris, play);
    game_colors();
    while_loop_game(tetris, play);
    wclear(stdscr);
    endwin();
    write(1, "You won with a score of:", 24);
    my_put_nbr(play->score);
    write(1, "\n", 1);
}