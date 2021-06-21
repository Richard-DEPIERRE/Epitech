/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_substr , hello_world)
{
    string_t *t2 = NULL;
    string_t s;

    string_init(&s, "Forever I am The best");
    t2 = s.substr(&s, 5, 10);
    cr_assert_str_eq("er I am Th", t2->str);
    string_destroy(&s);
    string_destroy(t2);
    free(t2);
}

Test(test_substr , negative)
{
    string_t *t2 = NULL;
    string_t s;

    string_init(&s, "Forever I am The best");
    t2 = s.substr(&s, -16, -5);
    cr_assert_str_eq("Forev", t2->str);
    string_destroy(&s);
    string_destroy(t2);
    free(t2);
}

Test(test_substr , null)
{
    string_t *t2 = NULL;
    string_t s;

    string_init(&s, "Forever I am The best");
    t2 = s.substr(&s, 40, 5);
    cr_assert_str_eq("", t2->str);
    string_destroy(&s);
    string_destroy(t2);
    free(t2);
}

Test(test_substr , check)
{
    string_t *t2 = NULL;
    string_t s;

    string_init(&s, "Forever I am The best");
    t2 = s.substr(&s, -40, 5);
    cr_assert_str_eq("Forev", t2->str);
    string_destroy(&s);
    string_destroy(t2);
    free(t2);
}

Test(test_substr , none)
{
    string_t *t2 = NULL;
    string_t s;

    string_init(&s, "Forever I am The best");
    t2 = s.substr(&s, 0, 0);
    cr_assert_str_eq("", t2->str);
    string_destroy(&s);
    string_destroy(t2);
    free(t2);
}