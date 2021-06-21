/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string const &name): Object(name), Toy(name)
{
    _type = "LittlePony";
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
}