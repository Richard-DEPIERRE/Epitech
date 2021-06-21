/*
** EPITECH PROJECT, 2020
** test_matches
** File description:
** test file for matches
*/

#include "matchsticks.h"

Test(test_matches, test)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    int ac = 3;
    char *av[4] = {"hello", "4", "5", "\0"};
    cr_redirect_stdout();
    fprintf(f_stdin, "");
    fclose(f_stdin);
    cr_assert(matchsticks(ac, av) == 0);
}

Test(test_matches, test_2)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    int ac = 3;
    char *av[4] = {"hello", "4", "5", "\0"};
    cr_redirect_stdout();
    fprintf(f_stdin, "10\n4\n2\n");
    fclose(f_stdin);
    cr_assert(matchsticks(ac, av) == 0);
}

Test(test_matches, test_3)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    int ac = 3;
    char *av[4] = {"hello", "2", "3", "\0"};
    cr_redirect_stdout();
    fprintf(f_stdin, "1\n1\n2\n1\n");
    fclose(f_stdin);
    cr_assert(matchsticks(ac, av) == 2);
}

Test(test_matches, test_4)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    int ac = 3;
    char *av[4] = {"hello", "2", "3", "\0"};
    cr_redirect_stdout();
    fprintf(f_stdin, "2\n3\n");
    fclose(f_stdin);
    cr_assert(matchsticks(ac, av) == 1);
}

Test(test_matches, test_5)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    int ac = 3;
    char *av[4] = {"hello", "4", "5", "\0"};
    cr_redirect_stdout();
    fprintf(f_stdin, "-2\n-3\n");
    fclose(f_stdin);
    cr_assert(matchsticks(ac, av) == 0);
}