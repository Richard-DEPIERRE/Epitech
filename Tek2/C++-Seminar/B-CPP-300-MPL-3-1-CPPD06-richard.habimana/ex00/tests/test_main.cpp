/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>

int my_cat(int ac, char **av);

Test(test_my_cat , NULL)
{
    int ac = 1;
    char *av[2] = {"./my_cat", NULL};

    cr_assert_eq(84, my_cat(ac, av));
}

Test(test_my_cat , hello_world)
{
    int ac = 2;
    char *av[3] = {"./my_cat", "main.cpp", NULL};

    cr_assert_eq(0, my_cat(ac, av));
}

Test(test_my_cat , no_file)
{
    int ac = 2;
    char *av[3] = {"./my_cat", "zenfzmain.cpp", NULL};

    cr_assert_eq(0, my_cat(ac, av));
}