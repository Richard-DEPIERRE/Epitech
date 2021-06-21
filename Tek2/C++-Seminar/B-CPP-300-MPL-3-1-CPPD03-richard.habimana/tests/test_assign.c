/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_assign , hello_world)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, "Hello World");
    cr_assert_str_eq("Hello World", s.str);
    s.assign_s(&s, &t);
    cr_assert_str_eq("Balek", s.str);
    s.assign_c(&s, "Ok");
    cr_assert_str_eq("Ok", s.str);
    string_destroy(&s);
    string_destroy(&t);
}

Test(test_assign , null)
{
    string_t s;
    string_t t;
    string_init(&t, "Balek");
    string_init (&s, NULL);
    s.assign_s(&s, &t);
    cr_assert_str_eq("Balek", s.str);
    s.assign_c(&s, "Ok");
    cr_assert_str_eq("Ok", s.str);
    string_destroy(&s);
    string_destroy(&t);
}