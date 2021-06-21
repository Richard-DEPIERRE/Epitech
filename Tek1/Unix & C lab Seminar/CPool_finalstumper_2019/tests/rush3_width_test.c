/*
** EPITECH PROJECT, 2019
** rush3_width_test
** File description:
** unit test for width
*/

#include <criterion/criterion.h>

int calculate_width(char *str);

Test(calculate_width, should_return_10)
{
    cr_assert_eq(calculate_width("o--------o\n"), 10);
}

Test(calculate_width, should_return_1)
{
    cr_assert_eq(calculate_width("o\n"), 1);
}

Test(calculate_width, should_return_0)
{
    cr_assert_eq(calculate_width("\n"), 0);
}
