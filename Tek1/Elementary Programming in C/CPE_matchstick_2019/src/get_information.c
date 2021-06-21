/*
** EPITECH PROJECT, 2020
** get_information
** File description:
** get information
*/

#include "matchsticks.h"

void get_height_length(char **map, information_t *player)
{
    for (; map[player->height]; player->height += 1);
    for (; map[0][player->length]; player->length += 1);
    player->height -= 2;
    player->length -= 3;
}

int check_line(int line, int nb_matches, char **map)
{
    int count = 0;

    for (int i = 0; map[line][i]; i += 1)
        if (map[line][i] == '|')
            count += 1;
    if (count >= nb_matches)
        return (0);
    else
        return (1);
}

void matchsticks_nb(char *str, information_t *player, char **map, int max)
{
    write(1, "Matches: ", 9);
    if ((player->a = getline(&str, &player->nb, stdin) < 0))
        player->done = 5;
    else {
        player->nb_matches = get_int(str);
        get_matches_2(player, map, max);
    }
}

void get_info2(char *str, information_t *m)
{
    while ((m->line = get_int(str)) <= 0 || m->line > m->height) {
        if (m->line > m->height || m->line == 0)
            write(1, "Error: this line is out of range\nLine: ", 39);
        else if (m->line > -2147483646 && m->line < 0) {
            write(1, "Error: invalid input (positive number expected)", 47);
            write(1, "\nLine: ", 7);
        }
        if (m->line == -2147483646) {
            write(1, "Error: invalid input (positive number expected)", 47);
            write(1, "\nLine: ", 7);
        }
        if ((m->a = getline(&str, &m->nb, stdin)) < 0) {
            m->done = 5;
            break;
        }
    }
}

information_t get_info_player1(char **map, int max_matches)
{
    char *str = malloc(sizeof(char) * 11);
    information_t m = {0, 0, 0, 10, 1, 0, 0, 0};

    get_height_length(map, &m);
    str[10] = '\0';
    write(1, "Line: ", 6);
    while (m.tmp == 1) {
        if ((m.a = getline(&str, &m.nb, stdin)) < 0) {
            m.done = 5;
            break;
        }
        get_info2(str, &m);
        if (m.done == 5)
            break;
        matchsticks_nb(str, &m, map, max_matches);
        if (m.done == 5)
            break;
    }
    return (m);
}