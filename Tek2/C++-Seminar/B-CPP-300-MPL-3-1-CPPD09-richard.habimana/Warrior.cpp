/*
** EPITECH PROJECT, 2021
** Warrior
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, const std::string &weapon, const std::string &character, const std::string &race, int strength, int stamina, int intelligence, int spirit, int agility, int range): _weapon(weapon), Character(name, level, character, race, strength, stamina, intelligence, spirit, agility, range)
{
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::Warrior()
{
}

Warrior::~Warrior()
{
}

std::string &Warrior::getWeapon()
{
    return _weapon;
}

int Warrior::CloseAttack()
{
    if (Range == RANGE || _weapon != (std::string)"hammer")
        return (0);
    if (getEnergy() < 30) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 30);
    std::cout << getName() << " strikes with his " << getWeapon() << std::endl;
    return (getStrength() + 20);
}

int Warrior::RangeAttack()
{
    if (Range == CLOSE)
        return (0);
    if (getEnergy() < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    setEnergy(getEnergy() - 10);
    std::cout << getName() << " intercepts" << std::endl;
    Range = CLOSE;
    return (0);
}

void Warrior::RestorePower()
{
    std::cout << getName() << " eats" << std::endl;
    setEnergy(100);
}