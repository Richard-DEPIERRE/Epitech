/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string const &name): Object(name), Toy(name)
{
    _type = "Teddy";
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}