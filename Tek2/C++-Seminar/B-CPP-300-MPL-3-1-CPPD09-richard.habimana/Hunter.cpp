/*
** EPITECH PROJECT, 2021
** Priest
** File description:
** Priest
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level, const std::string &weapon, const std::string &character, const std::string &race, int strength, int stamina, int intelligence, int spirit, int agility, int range): Character(name, level, character, race, strength, stamina, intelligence, spirit, agility, range), Warrior(name, level, weapon)
{
    std::cout << getName() << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

Hunter::Hunter()
{
}

void Hunter::TakeDamage(const int damage)
{
    Warrior::TakeDamage(damage);
}

int Hunter::CloseAttack()
{
    if (Range == RANGE || _weapon != (std::string)"sword")
        return (0);
    if (getEnergy() < 30) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 30);
    std::cout << getName() << " strikes with his " << getWeapon() << std::endl;
    return (getStrength() + 20);
}

int Hunter::RangeAttack()
{
    if (getEnergy() < 25) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 25);
    std::cout << getName() << " uses his bow" << std::endl;
    return (20 + getAgility());
}

void Hunter::RestorePower()
{
    Warrior::RestorePower();
}

void Hunter::setRange(int range)
{
    Range = (Character::AttackRange)range;
}