/*
** EPITECH PROJECT, 2021
** Priest
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level, const std::string &character, const std::string &race, int strength, int stamina, int intelligence, int spirit, int agility, int range): Character(name, level, character, race, strength, stamina, intelligence, spirit, agility, range), Mage(name, level)
{
    std::cout << getName() << " enters in the order" << std::endl;
}

Priest::Priest()
{
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (Range == RANGE)
        return (0);
    if (getEnergy() < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return (0);
    }
    Range = RANGE;
    setEnergy(getEnergy() - 10);
    std::cout << getName() << " uses a spirit explosion" << std::endl;
    return (getSpirit() + 10);
}

void Priest::Heal()
{
    if (getEnergy() < 10) {
        std::cout << getName() << " out of power" << std::endl;
        return;
    }
    setEnergy(getEnergy() - 10);
    std::cout << getName() << " casts a little heal spell" << std::endl;
    int given = (100 - getHealth() >= 70) ? 70 : (100 - getHealth());
    setHealth(getHealth() + given);
}