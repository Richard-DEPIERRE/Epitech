/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** main for my matchsticks
*/

#include "matchsticks.h"

int check_win_condition(char **map)
{
    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1)
            if (map[i][j] == '|')
                return (1);
    return (0);
}

void player1_play(information_t *player1, char **map, int max_matchs)
{
    write(1, "\nYour turn:\n", 12);
    *player1 = get_info_player1(map, max_matchs);
    if (player1->done == 0) {
        modify_map(player1->line, player1->nb_matches, map);
        write(1, "Player removed ", 15);
        my_putnbr(player1->nb_matches);
        write(1, " match(es) from line ", 21);
        my_putnbr(player1->line);
        write(1, "\n", 1);
        print_map(map);
    }
}

void player2_play(information_t *player2, char **map, int max_matches)
{
    write(1, "\nAI's turn...\n", 14);
    *player2 = get_info_player2(map, max_matches);
    modify_map(player2->line, player2->nb_matches, map);
    write(1, "AI removed ", 11);
    my_putnbr(player2->nb_matches);
    write(1, " match(es) from line ", 21);
    my_putnbr(player2->line);
    write(1, "\n", 1);
    print_map(map);
}

int matchsticks2(information_t *player1, information_t *player2,
char **map, char **av)
{
    while (1) {
        player1_play(player1, map, get_int(av[2]));
        if (player1->done == 84)
            return (84);
        if (player1->done == 5)
            return (0);
        if (check_win_condition(map) == 0) {
            write(1, "You lost, too bad...\n", 21);
            return (2);
            break;
        }
        player2_play(player2, map, get_int(av[2]));
        if (check_win_condition(map) == 0) {
            write(1, "I lost... snif... but I'll get you next time!!\n", 47);
            return (1);
            break;
        }
    }
    return (0);
}

int matchsticks(int ac, char **av)
{
    information_t player1 = {0, 0, 0, 0, 0, 0, 0, 0};
    information_t player2 = {0, 0, 0, 0, 0, 0, 0, 0};
    char **map;

    if (ac != 3)
        return (84);
    if (get_int(av[1]) < 1 || get_int(av[1]) > 100)
        return (84);
    if (get_int(av[2]) <= 0)
        return (84);
    map = main_map(ac, av);
    if (!map)
        return (84);
    print_map(map);
    return (matchsticks2(&player1, &player2, map, av));
}