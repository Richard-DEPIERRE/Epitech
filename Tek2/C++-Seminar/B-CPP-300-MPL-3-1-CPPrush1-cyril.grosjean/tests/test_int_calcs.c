/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_int_calcs
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../raise.h"
#include "../new.h"
#include "../object.h"
#include "../int.h"

Test(new, should_display_int_value)
{
    Object *integer = new(Int, 7);
    char *string = str(integer);

    cr_assert_not_null(integer);
    cr_assert_str_eq(string, "<Int (7)>");
    free(string);
    delete(integer);
}

Test(new, should_add_int_values)
{
    Object *integer1 = new(Int, 7);
    Object *integer2 = new(Int, 5);
    Object *integer_res = NULL;
    char *string = NULL;

    integer_res = addition(integer1, integer2);
    string = str(integer_res);
    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_not_null(integer_res);
    cr_assert_str_eq(string, "<Int (12)>");
    free(string);
    delete(integer1);
    delete(integer2);
    delete(integer_res);
}

Test(new, should_sub_int_values)
{
    Object *integer1 = new(Int, 3);
    Object *integer2 = new(Int, 2);
    Object *integer_res = NULL;
    char *string = NULL;

    integer_res = subtraction(integer1, integer2);
    string = str(integer_res);
    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_not_null(integer_res);
    cr_assert_str_eq(string, "<Int (1)>");
    free(string);
    delete(integer1);
    delete(integer2);
    delete(integer_res);
}

Test(new, should_mul_int_values)
{
    Object *integer1 = new(Int, 7);
    Object *integer2 = new(Int, 2);
    Object *integer_res = NULL;
    char *string = NULL;

    integer_res = multiplication(integer1, integer2);
    string = str(integer_res);
    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_not_null(integer_res);
    cr_assert_str_eq(string, "<Int (14)>");
    free(string);
    delete(integer1);
    delete(integer2);
    delete(integer_res);
}

Test(new, should_div_int_values)
{
    Object *integer1 = new(Int, 15);
    Object *integer2 = new(Int, 3);
    Object *integer_res = NULL;
    char *string = NULL;

    integer_res = division(integer1, integer2);
    string = str(integer_res);
    cr_assert_not_null(integer1);
    cr_assert_not_null(integer2);
    cr_assert_not_null(integer_res);
    cr_assert_str_eq(string, "<Int (5)>");
    free(string);
    delete(integer1);
    delete(integer2);
    delete(integer_res);
}