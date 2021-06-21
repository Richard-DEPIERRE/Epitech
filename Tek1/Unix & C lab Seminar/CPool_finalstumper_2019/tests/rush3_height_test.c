/*
** EPITECH PROJECT, 2019
** rush3_height_test
** File description:
** unit test for height
*/

#include <criterion/criterion.h>

int calculate_height(char *str);

Test(calculate_height, should_return_10)
{
    cr_assert_eq(calculate_height("o\n-\n-\n-\n-\n-\n-\n-\n-\n-\n"), 10);
}

Test(calculate_height, should_return_1)
{
    cr_assert_eq(calculate_height("o\n"), 1);
}

Test(calculate_height, should_return_0)
{
    cr_assert_eq(calculate_height("\0"), 0);
}
