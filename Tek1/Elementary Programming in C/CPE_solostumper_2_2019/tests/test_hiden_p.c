/*
** EPITECH PROJECT, 2019
** test_hiden_p
** File description:
** testing my hiden_p
*/

#include "palindrome.h"

Test(palindrome_p, check_errors_should_return_84)
{
    char *av[2] = {"./palindrome", "\0"};
    cr_assert_eq(palindrome(1, av), 84);
}

Test(palindrome_p, should_return_0)
{
    char *av[3] = {"./palindrome", "Noon", "\0"};
    cr_assert_eq(palindrome(2, av), 0);
}

Test(palindrom_p, should_return_0_2)
{
    char *av[3] = {"./palindrome", "NooN", "\0"};
    cr_assert_eq(palindrome(2, av), 0);
}

Test(palindrome_p, should_return_0_3)
{
    char *av[3] = {"./palindrome", "nooN", "\0"};
    cr_assert_eq(palindrome(2, av), 0);
}

Test(palindrome_p, should_return_0_4)
{
    char *av[3] = {"./palindrome", "noon", "\0"};
    cr_assert_eq(palindrome(2, av), 0);
}
