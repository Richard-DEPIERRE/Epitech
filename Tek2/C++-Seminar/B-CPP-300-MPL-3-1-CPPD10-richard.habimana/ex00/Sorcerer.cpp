/*
** EPITECH PROJECT, 2021
** Sorcerer
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::polymorph(Victim const &victim) const
{
    victim.getPolymorph();
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &sorcerer)
{
    return(os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl);
}
