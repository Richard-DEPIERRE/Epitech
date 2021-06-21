/*
** EPITECH PROJECT, 2019
** test_hiden_p
** File description:
** testing my hiden_p
*/

#include "hidden_p.h"

Test(test_hidden_p, check_errors_should_return_84)
{
    char *av[2] = {"Hello", "world"};
    cr_assert_eq(hidden_p(2, av), 84);
}

Test(test_hidden_p, check_right_string)
{
    char *av[3] = {"./hidenp", "padinton", "paqefwtdjetyiytjneytjoeyjnejeyj"};
    cr_assert_eq(hidden_p(3, av), 0);
}

Test(test_hidden_p, check_wrong_string)
{
    char *av[3] = {"./hidenp", "ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd"};
    cr_assert_eq(hidden_p(3, av), 0);
}
