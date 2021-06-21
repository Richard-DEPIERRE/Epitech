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

Toy &Toy::operator=(Toy const toy)
{
    _name = toy._name;
    _pic = toy._pic;
    _type = toy._type;
    return (*this);
}

bool Toy::speak(const std::string &statement) const
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
    return true;
}