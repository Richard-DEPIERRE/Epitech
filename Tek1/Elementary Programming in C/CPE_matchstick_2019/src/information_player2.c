/*
** EPITECH PROJECT, 2020
** information_player2
** File description:
** ai for player2
*/

#include "matchsticks.h"

int check_line2(int line, int nb_matches, char **map)
{
    int count = 0;

    for (int i = 0; map[line][i]; i += 1)
        if (map[line][i] == '|')
            count += 1;
    if (count >= nb_matches)
        return (count - nb_matches);
    else
        return (-1);
}

information_t get_info_player2(char **map, int max_matches)
{
    information_t player = {1, 1, 0, 10, 1, 0, 0, 0};
    int count = check_line2(player.line, player.nb_matches, map);

    while (count == -1) {
        player.line += 1;
        count = check_line2(player.line, player.nb_matches, map);
    }
    while (count != - 1 && player.nb_matches <= max_matches) {
        player.nb_matches += 1;
        count = check_line2(player.line, player.nb_matches, map);
    }
    player.nb_matches -= 1;
    if (player.nb_matches % 2 == 1) {
        player.nb_matches += 1;
    }
    player.nb_matches /= 2;
    return (player);
}