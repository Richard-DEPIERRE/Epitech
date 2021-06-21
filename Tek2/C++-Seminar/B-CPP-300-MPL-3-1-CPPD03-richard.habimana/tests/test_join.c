/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include "../string.h"
#include <criterion/criterion.h>

Test(test_join , join_string)
{
    string_t s;
    string_init(&s, "Bonjour,Comment,,Tu,Vas");
    char **ret = s.split_c(&s, ',');
    s.join_c(&s, ' ', (const char *const *)ret);
    cr_assert_str_eq("Bonjour Comment  Tu Vas", s.str);
    for (int i = 0; ret[i]; i += 1)
        free(ret[i]);
    free(ret);
    string_destroy(&s);
    string_init(&s, "Bonjour,Comment,,Tu,Vas");
    string_t **ret_two = s.split_s(&s, ',');
    s.join_s(&s, ' ', (const string_t *const *)ret_two);
    cr_assert_str_eq("Bonjour Comment  Tu Vas", s.str);
    for (int i = 0; ret_two[i]; i ++) {
        free(ret_two[i]->str);
        free(ret_two[i]);
    }
    free(ret_two);
    string_destroy(&s);
}