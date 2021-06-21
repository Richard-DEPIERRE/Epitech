/*
** EPITECH PROJECT, 2021
** Cyril, Richard, Alexis, Jean-Louis
** File description:
** test point
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../raise.h"
#include "../new.h"
#include "../object.h"
#include "../player.h"
#include "../point.h"

Test(point, should_set_point_class)
{
    Object *point = new(Point, 42, -42);
    char *str = str(point);

    cr_assert_not_null(point);
    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Point (42, -42)>");
    delete(point);
    free(str);
}

Test(point, should_add_point_class)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);
    char *strp1 = str(p1);
    char *strp2 = str(p2);
    Object *add = addition(p1, p2);
    char *stradd = str(add);

    cr_assert_not_null(p1);
    cr_assert_not_null(p2);
    cr_assert_not_null(strp1);
    cr_assert_not_null(strp2);
    cr_assert_not_null(add);
    cr_assert_not_null(stradd);
    cr_assert_str_eq(stradd, "<Point (14, 15)>");
    free(strp1);
    free(strp2);
    free(stradd);
    delete(p1);
    delete(p2);
    delete(add);
}

Test(point, should_sub_point_class)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);
    char *strp1 = str(p1);
    char *strp2 = str(p2);
    Object *sub = subtraction(p1, p2);
    char *strsub = str(sub);

    cr_assert_not_null(p1);
    cr_assert_not_null(p2);
    cr_assert_not_null(strp1);
    cr_assert_not_null(strp2);
    cr_assert_not_null(sub);
    cr_assert_not_null(strsub);
    cr_assert_str_eq(strsub, "<Point (10, 11)>");
    free(strp1);
    free(strp2);
    free(strsub);
    delete(p1);
    delete(p2);
    delete(sub);
}

Test(point, should_mul_point_class)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);
    char *strp1 = str(p1);
    char *strp2 = str(p2);
    Object *mul = multiplication(p1, p2);
    char *strmul = str(mul);

    cr_assert_not_null(p1);
    cr_assert_not_null(p2);
    cr_assert_not_null(strp1);
    cr_assert_not_null(strp2);
    cr_assert_not_null(mul);
    cr_assert_not_null(strmul);
    cr_assert_str_eq(strmul, "<Point (24, 26)>");
    free(strp1);
    free(strp2);
    free(strmul);
    delete(p1);
    delete(p2);
    delete(mul);
}

Test(point, should_div_point_class)
{
    Object *p1 = new(Point, 2, 2);
    Object *p2 = new(Point, 12, 14);
    char *strp1 = str(p1);
    char *strp2 = str(p2);
    Object *div = division(p2, p1);
    char *strdiv = str(div);

    cr_assert_not_null(p1);
    cr_assert_not_null(p2);
    cr_assert_not_null(strp1);
    cr_assert_not_null(strp2);
    cr_assert_not_null(div);
    cr_assert_not_null(strdiv);
    cr_assert_str_eq(strdiv, "<Point (6, 7)>");
    free(strp1);
    free(strp2);
    free(strdiv);
    delete(p1);
    delete(p2);
    delete(div);
}