/*
** EPITECH PROJECT, 2019
** test_hiden_p
** File description:
** testing my hiden_p
*/

#include "matchsticks.h"

Test(test_matchsticks, error_1)
{
    int ac = 4;
    char *av[4] = {"hello", "world", "loce", "\0"};
    cr_assert_eq(matchsticks(ac, av), 84);
}

Test(test_matchsticks, error_2)
{
    int ac = 3;
    char *av[4] = {"hello", "-10", "5", "\0"};
    cr_assert_eq(matchsticks(ac, av), 84);
}

Test(test_matchsticks, error_3)
{
    int ac = 3;
    char *av[4] = {"hello", "110", "5", "\0"};
    cr_assert_eq(matchsticks(ac, av), 84);
}

Test(test_matchsticks, error_4)
{
    int ac = 3;
    char *av[4] = {"hello", "5", "-2", "\0"};
    cr_assert_eq(matchsticks(ac, av), 84);
}

Test(test_matchsticks, error_5)
{
    int ac = 3;
    char *av[4] = {"hello", "world", "loce", "\0"};
    cr_assert_eq(matchsticks(ac, av), 84);
}
