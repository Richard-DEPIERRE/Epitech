/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(std::string name): _name(name)
{
    std::cout << "Some random victim called " << _name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Victim &victim)
{
    return(os << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}

void Victim::getPolymorph() const
{
    std::cout << getName() << " has been turned into a cute little sheep!" << std::endl;
}