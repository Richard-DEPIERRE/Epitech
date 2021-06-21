/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_size , hello_world)
{
    string_t s;
    string_init (&s, "Hello World");
    cr_assert_eq(11, s.size(&s));
    string_destroy(&s);
}

Test(test_size , null)
{
    string_t s;
    string_init (&s, NULL);
    cr_assert_eq(-1, s.size(&s));
    string_destroy(&s);
}