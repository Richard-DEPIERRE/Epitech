/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
}

Ratatouille::Ratatouille(Ratatouille const &other)
{
    _ingredients.str(other._ingredients.str());
}

Ratatouille::~Ratatouille()
{
}

Ratatouille &Ratatouille::operator=(const Ratatouille &rhs)
{
    _ingredients.str("");
    _ingredients.str(rhs._ingredients.str());
    return (*this);
}

Ratatouille &Ratatouille::addVegetable(unsigned char c)
{
    _ingredients << c;
    return (*this);
}

Ratatouille &Ratatouille::addCondiment(unsigned int nb)
{
    _ingredients << nb;
    return (*this);
}

Ratatouille &Ratatouille::addSpice(double db)
{
    _ingredients << db;
    return (*this);
}

Ratatouille &Ratatouille::addSauce(const std::string & str)
{
    _ingredients << str;
    return (*this);
}

std::string Ratatouille::kooc()
{
    return _ingredients.str();
}
