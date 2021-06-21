/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tetris.h"

void game_print2(void)
{
    attron(COLOR_PAIR(2));
    mvprintw(0, 6, "* * * ");
    mvprintw(1, 6, "*     ");
    mvprintw(2, 6, "* * * ");
    mvprintw(3, 6, "*     ");
    mvprintw(4, 6, "* * * ");
    mvprintw(0, 18, "* * * ");
    mvprintw(1, 18, "*  *  ");
    mvprintw(2, 18, "* * * ");
    mvprintw(3, 18, "*   * ");
    mvprintw(4, 18, "*   * ");
    mvprintw(0, 26, "* * * ");
    mvprintw(1, 26, "*     ");
    mvprintw(2, 26, "* * * ");
    mvprintw(3, 26, "    * ");
    mvprintw(4, 26, "* * * ");
    attroff(COLOR_PAIR(2));
}

void game_print3(bin_t *play)
{
    mvprintw(0, 32, "+");
    mvprintw(0, 33 + play->lenght * 2, "+");
    for (int i = 0; i < play->lenght * 2; i += 1)
        mvprintw(0, 33 + i, "-");
    for (int i = 0; i < play->height; i += 1) {
        mvprintw(1 + i, 32, "|");
        mvprintw(1 + i, 33 + play->lenght * 2, "|");
    }
    mvprintw(play->height + 1, 32, "+");
    mvprintw(play->height + 1, 33 + play->lenght * 2, "+");
    for (int i = 0; i < play->lenght * 2; i += 1)
        mvprintw(play->height + 1, 33 + i, "-");
    mvprintw(0, 34 + play->lenght * 2, "/-next----\\");
    mvprintw(1, 34 + play->lenght * 2, "|         |");
    mvprintw(2, 34 + play->lenght * 2, "|         |");
    mvprintw(3, 34 + play->lenght * 2, "\\---------/");
    mvprintw(8, 0, "/");
    mvprintw(8, 27, "\\");
}

void game_print4(bin_t *play)
{
    for (int i = 0; i < 26; i += 1)
        mvprintw(8, 1 + i, "-");
    for (int i = 0; i < 9; i += 1) {
        mvprintw(9 + i, 0, "|");
        mvprintw(9 + i, 27, "|");
    }
    for (int i = 0; i < 26; i += 1)
        mvprintw(18, 1 + i, "-");
    mvprintw(18, 0, "\\");
    mvprintw(18, 27, "/");
    play->t2 = clock();
    play->seconds = (int){(double)(play->t2 - play->t)/1000};
    play->minutes = play->seconds / 60;
    play->seconds = play->seconds % 60;
    mvprintw(10, 2, "High Score          Null");
    mvprintw(11, 2, "Score                 %d", play->score);
    mvprintw(13, 2, "Lines                 %d", play->lines);
    mvprintw(14, 2, "Level                 %d", play->level);
    mvprintw(16, 2, "Time               %d:%d", play->minutes, play->seconds);
}

node_R_t *copy_node(node_R_t *node)
{
    node_R_t *tmp = malloc(sizeof(node_R_t));
    int size = 0;

    tmp->next = NULL;
    tmp->number = node->number;
    for (; node->str[size]; size += 1);
    tmp->str = malloc(sizeof(char *) * (size + 1));
    tmp->str[size] = NULL;
    for (int i = 0; node->str[i]; i++) {
        for (size = 0; node->str[i][size]; size += 1);
        tmp->str[i] = malloc(sizeof(char) * (size + 1));
        tmp->str[i][size] = '\0';
        for (int j = 0; node->str[i][j]; j += 1)
            tmp->str[i][j] = node->str[i][j];
    }
    tmp->x = node->x;
    tmp->y = node->y;
    return (tmp);
}

void game_print5(tetris_t *tetris, bin_t *play)
{
    node_R_t *tmp = play->tetriminos;
    node_R_t *tmp2 = play->tetriminos2;
    node_R_t *tmp_try = play->tetriminos2;

    if (play->tmp2 == 1) {
        play->nb = (rand() % play->lenght) * 2;
        play->tetrim = (rand() % 6) - 1;
        for (int i = 0; tmp->next && i != play->tetrim; i++)
            tmp = tmp->next;
        tmp->number = play->tetrim;
        tmp->x = play->tmp2;
        tmp->y = play->nb;
        if (!tmp2)
            play->tetriminos2 = copy_node(tmp);
        else {
            for (; tmp2->next; tmp2 = tmp2->next);
            tmp2->next = copy_node(tmp);
        }
    }
    tmp2 = play->tetriminos2;
    for (int i = 0; tmp2->next; i++)
        tmp2 = tmp2->next;
    tmp2->x = play->tmp2;
    tmp2->y = play->nb;
    tmp_try = play->tetriminos2;
    for (; tmp_try->next; tmp_try = tmp_try->next)
        for (int i = 0; tmp_try->str[i]; i += 1)
            mvprintw(tmp_try->x + i, tmp_try->y + 33, tmp_try->str[i]);
    for (int i = 0; tmp_try->str[i]; i += 1)
        mvprintw(tmp_try->x + i, tmp_try->y + 33, tmp_try->str[i]);
    if (play->tmp2 <= play->height - tetris->tetriminos[play->tetrim].y)
        play->tmp2 += 1;
    else {
        play->tmp2 = 1;
        play->score += 1;
    }
    if (play->score % 10 == 0 && play->score != 0) {
        play->level += 1;
        play->timeout_int -= 100;
    }
}

void get_getch(tetris_t *tetris, bin_t *play)
{
    play->timeout_int = 1000;
    if (!tetris->keys[4].name) {
        if (play->c == 's')
            play->timeout_int = 500;
    } else if (play->c == tetris->keys[4].str[0])
        play->timeout_int = 500;
    if (!tetris->keys[2].name) {
        if (play->c == 'd')
            (play->nb <= play->lenght * 2 - (tetris->tetriminos[play->tetrim].x * 2)) ? (play->nb += 1) : (play->nb = play->nb);
    } else if (play->c == tetris->keys[2].str[0])
       if (play->nb <= play->lenght * 2 - (tetris->tetriminos[play->tetrim].x * 2))
            play->nb += 1;
    if (!tetris->keys[1].name) {
        if (play->c == 'q')
            if (play->nb >= 2)
                play->nb -= 1;
    } else if (play->c == tetris->keys[1].str[0])
        if (play->nb >= 2)
            play->nb -= 1;
}