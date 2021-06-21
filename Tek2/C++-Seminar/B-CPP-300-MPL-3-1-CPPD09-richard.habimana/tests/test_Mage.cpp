/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../Mage.hpp"


Test(test_mage , one)
{
    Mage c("poney", 42, "hammer");
    cr_assert_eq(c.CloseAttack(), 0);
    cr_assert_eq(c.RangeAttack(), 31);
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
    c.Range = (Character::AttackRange)0;
    cr_assert_eq(c.CloseAttack(), 0);
    c.RangeAttack();
    c.RestorePower();
}

Test(test_mage , errors)
{
    Mage c("poney", 209, "Character", "Human", 12, 5, 5, 5, 5, 0);
    c.CloseAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    cr_assert_eq(c.CloseAttack(), 0);
    c.RangeAttack();
}