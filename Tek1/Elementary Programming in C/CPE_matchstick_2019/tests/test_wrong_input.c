/*
** EPITECH PROJECT, 2020
** test_matches
** File description:
** test file for matches
*/

#include "matchsticks.h"

Test(test_matches, test_input)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    int ac = 3;
    char *av[4] = {"hello", "4", "5", "\0"};
    cr_redirect_stdout();
    fprintf(f_stdin, "3\n-2\n3\n18\n1\n5\n3\nrich\n");
    fclose(f_stdin);
    cr_assert(matchsticks(ac, av) == 0);
}