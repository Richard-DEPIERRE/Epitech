/*
** EPITECH PROJECT, 2021
** Cyril, Richard, Alexis, Jean-Louis
** File description:
** test_int_comparisons
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../raise.h"
#include "../new.h"
#include "../object.h"
#include "../int.h"

Test(new, should_be_equals)
{
    Object *integer1 = new(Int, 12);
    Object *integer2 = new(Int, 12);
    bool result = eq(integer1, integer2);

    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_eq(result, true);
    delete(integer1);
    delete(integer2);
}

Test(new, should_not_be_equals)
{
    Object *integer1 = new(Int, 15);
    Object *integer2 = new(Int, 9);
    bool result = eq(integer1, integer2);

    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_eq(result, false);
    delete(integer1);
    delete(integer2);
}

Test(new, should_be_smaller_than)
{
    Object *integer1 = new(Int, 4);
    Object *integer2 = new(Int, 8);
    bool result1 = gt(integer1, integer2);
    bool result2 = lt(integer1, integer2);

    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_eq(result1, false);
    cr_assert_eq(result2, true);
    delete(integer1);
    delete(integer2);
}

Test(new, should_be_greater_than)
{
    Object *integer1 = new(Int, 8);
    Object *integer2 = new(Int, 3);
    bool result1 = gt(integer1, integer2);
    bool result2 = lt(integer1, integer2);

    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_eq(result1, true);
    cr_assert_eq(result2, false);
    delete(integer1);
    delete(integer2);
}