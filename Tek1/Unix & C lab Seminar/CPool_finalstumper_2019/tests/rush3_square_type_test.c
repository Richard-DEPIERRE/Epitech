/*
** EPITECH PROJECT, 2019
** rush3_square_type_test
** File description:
** unit test for square type
*/

#include <criterion/criterion.h>

char *square_type(char *str, int w, int h);

Test(square_type, should_return_rush1_1)
{
    cr_assert_str_eq(square_type("o---o\n", 5, 1), "[rush1-1] 5 1");
}

Test(square_type, should_return_rush1_2)
{
    cr_assert_str_eq(square_type("***\n", 3, 1), "[rush1-2] 3 1");
}

Test(square_type, should_return_rush1_3_4_5)
{
    char *result = "[rush1-3] 3 1 || [rush1-4] 3 1 || [rush1-5] 3 1";

    cr_assert_str_eq(square_type("BBB\n", 3, 1), result);
}

Test(square_type, should_return_rush1_4)
{
    cr_assert_str_eq(square_type("ABBBC\nB   B\nABBBC\n", 5, 3), "[rush1-4] 5 3");
}

Test(square_type, should_return_rush1_5)
{
    cr_assert_str_eq(square_type("ABBBC\nB   B\nCBBBA\n", 5, 3), "[rush1-5] 5 3");
}
