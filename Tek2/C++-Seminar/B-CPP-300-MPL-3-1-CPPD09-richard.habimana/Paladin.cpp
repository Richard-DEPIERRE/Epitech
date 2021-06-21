/*
** EPITECH PROJECT, 2021
** Priest
** File description:
** Priest
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level, const std::string &character, const std::string &race, int strength, int stamina, int intelligence, int spirit, int agility, int range): Character(name, level, character, race, strength, stamina, intelligence, spirit, agility, range), Warrior(name, level), Mage(name, level), Priest(name, level)
{
    std::cout << "the light falls on " << getName() << std::endl;
}

Paladin::Paladin()
{
}

Paladin::~Paladin()
{
}

int Paladin::CloseAttack()
{
    return (Warrior::CloseAttack());
}

int Paladin::RangeAttack()
{
    return (Priest::RangeAttack());
}

void Paladin::Heal()
{
    Priest::Heal();
}

void Paladin::RestorePower()
{
    Warrior::RestorePower();
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}