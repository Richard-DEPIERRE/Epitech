/*
** EPITECH PROJECT, 2021
** Cyril, Richard, Alexis, Jean-Louis
** File description:
** test_char_calcs
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../raise.h"
#include "../new.h"
#include "../object.h"
#include "../char.h"

Test(new, should_display_char_value)
{
    Object *mychar = new(Char, 'c');
    char *string = str(mychar);

    cr_assert_not_null(mychar);
    cr_assert_not_null(string);
    cr_assert_str_eq(string, "<Char (c)>");
    free(string);
    delete(mychar);
}

Test(new, should_add_char_values)
{
    Object *mychar1 = new(Char, 'c');
    Object *mychar2 = new(Char, 2);
    Object *mychar_result = NULL;
    char *string = NULL;

    mychar_result = addition(mychar1, mychar2);
    string = str(mychar_result);
    cr_assert_not_null(mychar1);
    cr_assert_not_null(mychar2);
    cr_assert_not_null(mychar_result);
    cr_assert_not_null(string);
    cr_assert_str_eq(string, "<Char (e)>");
    free(string);
    delete(mychar1);
    delete(mychar2);
    delete(mychar_result);
}

Test(new, should_sub_char_values)
{
    Object *mychar1 = new(Char, 'f');
    Object *mychar2 = new(Char, 2);
    Object *mychar_result = NULL;
    char *string = NULL;

    mychar_result = subtraction(mychar1, mychar2);
    string = str(mychar_result);
    cr_assert_not_null(mychar1);
    cr_assert_not_null(mychar2);
    cr_assert_not_null(mychar_result);
    cr_assert_not_null(string);
    cr_assert_str_eq(string, "<Char (d)>");
    free(string);
    delete(mychar1);
    delete(mychar2);
    delete(mychar_result);
}

Test(new, should_mul_char_values)
{
    Object *mychar1 = new(Char, '=');
    Object *mychar2 = new(Char, 2);
    Object *mychar_result = NULL;
    char *string = NULL;

    mychar_result = multiplication(mychar1, mychar2);
    string = str(mychar_result);
    cr_assert_not_null(mychar1);
    cr_assert_not_null(mychar2);
    cr_assert_not_null(mychar_result);
    cr_assert_not_null(string);
    cr_assert_str_eq(string, "<Char (z)>");
    free(string);
    delete(mychar1);
    delete(mychar2);
    delete(mychar_result);
}

Test(new, should_div_char_values)
{
    Object *mychar1 = new(Char, 'z');
    Object *mychar2 = new(Char, 2);
    Object *mychar_result = NULL;
    char *string = NULL;

    mychar_result = division(mychar1, mychar2);
    string = str(mychar_result);
    cr_assert_not_null(mychar1);
    cr_assert_not_null(mychar2);
    cr_assert_not_null(mychar_result);
    cr_assert_not_null(string);
    cr_assert_str_eq(string, "<Char (=)>");
    free(string);
    delete(mychar1);
    delete(mychar2);
    delete(mychar_result);
}