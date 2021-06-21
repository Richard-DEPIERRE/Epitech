/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../Paladin.hpp"


Test(test_paladin , one)
{
    Paladin c("poney", 42, "hammer");
    cr_assert_eq(c.CloseAttack(), 29);
    cr_assert_eq(c.RangeAttack(), 30);
    cr_assert_eq(c.Intercept(), 0);
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    cr_assert_eq(c.RangeAttack(), 0);
    c.RangeAttack();
    c.Range = (Character::AttackRange)0;
    cr_assert_eq(c.Range, 0);
    c.CloseAttack();
    c.Heal();
    c.RestorePower();
    c.Heal();
}

Test(test_paladin , errors)
{
    Paladin c("poney", 209, "Character", "Human", 12, 5, 5, 5, 5, 0);
    c.CloseAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    cr_assert_eq(c.CloseAttack(), 0);
    c.RangeAttack();
}