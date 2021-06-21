/*
** EPITECH PROJECT, 2020
** palindrom_tests
** File description:
** palindrome test 2nd file
*/

#include "palindrome.h"

Test(palindrome_p2, should_return_0)
{
    char *av[3] = {"./palindrome", "Noom", "\0"};
    cr_assert_eq(palindrome(2, av), 0);
}
