/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../Character.hpp"


Test(test_character , one)
{
    Character c("poney", 42);
    cr_assert_eq(c.CloseAttack(), 15);
    cr_assert_eq(c.RangeAttack(), 10);
    c.TakeDamage(70);
    cr_assert_eq(c.getHealth(), 30);
    c.Heal();
    cr_assert_eq(c.getHealth(), 80);
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    cr_assert_eq(c.getEnergy(), 10);
    cr_assert_eq(c.CloseAttack(), 15);
    cr_assert_eq(c.CloseAttack(), 0);
    c.RangeAttack();
    c.RestorePower();
    cr_assert_eq(c.getEnergy(), 50);
}

Test(test_character , errors)
{
    Character c("poney", 209, "Character", "Human", 5, 5, 5, 5, 5, 1);
    cr_assert_eq(c.CloseAttack(), 0);
    c.TakeDamage(200);
    cr_assert_eq(c.getHealth(), 0);
}