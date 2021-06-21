/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_insert , hello_world)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, "Hello World");
    s.insert_c(&s, 8, NULL);
    cr_assert_str_eq("Hello World", s.str);
    s.insert_s(&s, 8, &t);
    cr_assert_str_eq("Hello WoBalekrld", s.str);
    string_destroy(&s);
    string_destroy(&t);
}

Test(test_insert , null)
{
    string_t s;
    string_init (&s, NULL);
    s.insert_c(&s, 8, "Hello World");
    cr_assert_str_eq("Hello World", s.str);
    string_destroy(&s);
}

Test(test_insert , pos)
{
    string_t s;
    string_init (&s, "Hello World");
    s.insert_c(&s, 80, "Balek");
    cr_assert_str_eq("Hello WorldBalek", s.str);
    string_destroy(&s);
}