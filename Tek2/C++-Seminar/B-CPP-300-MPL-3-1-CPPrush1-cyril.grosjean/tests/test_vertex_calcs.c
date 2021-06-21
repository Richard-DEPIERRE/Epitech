/*
** EPITECH PROJECT, 2021
** Cyril, Richard, Alexis, Jean-Louis
** File description:
** test vertex
*/

#include <criterion/criterion.h>
#include "../raise.h"
#include "../new.h"
#include "../object.h"
#include "../player.h"
#include "../vertex.h"

Test(vertex, should_set_vertex_class)
{
    Object *vertex = new(Vertex, 84, 42, 21);
    char *str = str(vertex);

    cr_assert_not_null(vertex);
    cr_assert_not_null(str);
    cr_assert_str_eq(str, "<Vertex (84, 42, 21)>");
    delete(vertex);
    free(str);
}

Test(vertex, should_add_vertex_class)
{
    Object *v1 = new(Vertex, 12, 13, 14);
    Object *v2 = new(Vertex, 2, 2, 2);
    char *strv1 = str(v1);
    char *strv2 = str(v2);
    Object *add = addition(v1, v2);
    char *stradd = str(add);

    cr_assert_not_null(v1);
    cr_assert_not_null(v2);
    cr_assert_not_null(strv1);
    cr_assert_not_null(strv2);
    cr_assert_not_null(add);
    cr_assert_not_null(stradd);
    cr_assert_str_eq(stradd, "<Vertex (14, 15, 16)>");
    free(strv1);
    free(strv2);
    free(stradd);
    delete(v1);
    delete(v2);
    delete(add);
}

Test(vertex, should_sub_vertex_class)
{
    Object *v1 = new(Vertex, 12, 13, 14);
    Object *v2 = new(Vertex, 2, 2, 2);
    char *strv1 = str(v1);
    char *strv2 = str(v2);
    Object *sub = subtraction(v1, v2);
    char *strsub = str(sub);

    cr_assert_not_null(v1);
    cr_assert_not_null(v2);
    cr_assert_not_null(strv1);
    cr_assert_not_null(strv2);
    cr_assert_not_null(sub);
    cr_assert_not_null(strsub);
    cr_assert_str_eq(strsub, "<Vertex (10, 11, 12)>");
    free(strv1);
    free(strv2);
    free(strsub);
    delete(v1);
    delete(v2);
    delete(sub);
}

Test(vertex, should_mul_vertex_class)
{
    Object *v1 = new(Vertex, 12, 13, 14);
    Object *v2 = new(Vertex, 2, 2, 2);
    char *strv1 = str(v1);
    char *strv2 = str(v2);
    Object *mul = multiplication(v1, v2);
    char *strmul = str(mul);

    cr_assert_not_null(v1);
    cr_assert_not_null(v2);
    cr_assert_not_null(strv1);
    cr_assert_not_null(strv2);
    cr_assert_not_null(mul);
    cr_assert_not_null(strmul);
    cr_assert_str_eq(strmul, "<Vertex (24, 26, 28)>");
    free(strv1);
    free(strv2);
    free(strmul);
    delete(v1);
    delete(v2);
    delete(mul);
}

Test(vertex, should_div_vertex_class)
{
    Object *v1 = new(Vertex, 12, 14, 16);
    Object *v2 = new(Vertex, 2, 2, 2);
    char *strv1 = str(v1);
    char *strv2 = str(v2);
    Object *div = division(v1, v2);
    char *strdiv = str(div);

    cr_assert_not_null(v1);
    cr_assert_not_null(v2);
    cr_assert_not_null(strv1);
    cr_assert_not_null(strv2);
    cr_assert_not_null(div);
    cr_assert_not_null(strdiv);
    cr_assert_str_eq(strdiv, "<Vertex (6, 7, 8)>");
    free(strv1);
    free(strv2);
    free(strdiv);
    delete(v1);
    delete(v2);
    delete(div);
}