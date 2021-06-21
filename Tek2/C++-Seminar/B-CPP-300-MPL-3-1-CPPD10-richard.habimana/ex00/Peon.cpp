/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Peon
*/

#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorph() const
{
    std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}