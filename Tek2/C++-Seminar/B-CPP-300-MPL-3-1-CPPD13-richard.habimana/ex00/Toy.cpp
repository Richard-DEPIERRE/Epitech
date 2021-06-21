/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &filename): _type(type), _name(name)
{
    _pic = Picture(filename);
}

Toy::~Toy()
{
}

Toy::Toy(Toy const &toy): _type(toy.getType()), _name(toy.getName()), _pic(toy.getAscii())
{
}