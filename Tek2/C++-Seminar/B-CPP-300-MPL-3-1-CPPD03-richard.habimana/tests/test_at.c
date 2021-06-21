/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_at , hello_world)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, "Hello World");
    s.assign_s(&s, &t);
    s.assign_c(&s, "Ok");
    s.append_c(&s, " forever");
    string_destroy(&t);
    string_init(&t, " Balek\0");
    s.append_s(&s, &t);
    cr_assert_eq('k', s.at(&s, 1));
    cr_assert_eq(-1 ,s.at(&s, 70));
    string_destroy(&s);
    string_destroy(&t);
}