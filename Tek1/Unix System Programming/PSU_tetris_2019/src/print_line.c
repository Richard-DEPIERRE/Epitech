/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

void print_help(char *str)
{
    write(1, "Usage: ", 7);
    write(1, str, my_strlength(str));
    write(1, " [options]\nOptions:\n --help               Display ", 50);
    write(1, "this help\n -L --level={num}     Start Tetris at level ", 54);
    write(1, "num (def: 1)\n -l --key-left={K}    Move the tetrimino", 53);
    write(1, " LEFT using the K key (def: left arrow)\n -r ", 44);
    write(1, "--key-right={K}   Move the tetrimino RIGHT ", 43);
    write(1, "using the K key (def: right arrow)\n ", 36);
    write(1, "-t --key-turn={K}    TURN the tetrimino", 39);
    write(1, " clockwise 90d using the K key (def: top arrow)\n", 48);
    write(1, " -d --key-drop={K}    DROP ", 27);
    write(1, "the tetrimino using the K key (def: down arrow)\n ", 49);
    write(1, "-q --key-quit={K}    QUIT ", 26);
    write(1, "the game using the K key (def: 'q' key)\n ", 41);
    write(1, "-p --key-pause={K}   PAUSE/RESTART the game using ", 50);
    write(1, "the K key (def: space bar)\n --map-size={row,col} Set ", 53);
    write(1, "the numbers of rows and columns ", 32);
    write(1, "of the map (def: 20,10)\n ", 25);
    write(1, "-w --without-next    Hide next tetrimino (def: false)\n ", 55);
    write(1, "-D --debug           Debug mode (def: false)\n", 45);
}

void clean_table(char **table, tetris_t *tetris, int pos, bin_t *play)
{
    int a = 0;
    int b = 0;
    node_R_t *tmp = play->tetriminos;

    for (int i = 0; table[i]; i += 1) {
        if (table[i][0] == ' ')
            a += 1;
        b += 1;
    }
    for (int i = 0; table[i] && a == b; i += 1)
        for (int j = 0; table[i][j]; j += 1)
            table[i][j] = table[i][j + 1];
    for (int i = 0; table[i]; i += 1) {
        while (table[i][my_strlength(table[i]) - 1] == ' ')
            table[i][my_strlength(table[i]) - 1] = '\0';
    }
    for (int i = 0; table[i]; i += 1) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->str[i] = my_strcpy(table[i], tmp->str[i]);
        tetris->tetriminos[pos].tetri[i] = my_strcpy(table[i],
        tetris->tetriminos[pos].tetri[i]);
        if (tetris->keys[10].name) {
            write(1, table[i], my_strlength(table[i]));
            write(1, "\n", 1);
        }
    }
}

void print_line(char *str, pieces_t *piece, tetris_t *tetris, bin_t *play)
{
    char **table = malloc(sizeof(char *) * (piece->height + 1));
    int i = 0;
    static int pos = -1;
    node_R_t *tmp = play->tetriminos;
    node_R_t *ln = malloc(sizeof(node_R_t));
    int b = 0;

    pos += 1;
    tetris->tetriminos[pos].tetri = malloc(sizeof(char *) * (piece->height + 1));
    table[piece->height] = NULL;
    ln->str = malloc(sizeof(char *) * (piece->height + 1));
    ln->x = 0;
    ln->y = 0;
    ln->height = 0;
    ln->length = 0;
    ln->next = NULL;
    table[piece->height] = NULL;
    if (!tmp)
        play->tetriminos = ln;
    else {
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = ln;
    }
    for (int j = 0; j < piece->height; j += 1) {
        table[j] = malloc(sizeof(char) * (piece->length + 1));
        table[j][piece->length] = '\0';
    }
    for (; str[i] != '\n'; i += 1);
    i += 1;
    for (int a = 0; str[i]; i += 1) {
        for (; str[i] != '\n' && str[i]; i += 1)
            table[a][b++] = str[i];
        if (!str[i])
            break;
        table[a][b++] = '\0';
        a += 1;
        b = 0;
    }
    clean_table(table, tetris, pos, play);
}