/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &ascii): Toy(WOODY, name, ascii) 
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std::string &statement) const
{
    std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Woody::speak_es(const std::string &statement)
{
    (void)statement;
    _error.type = Toy::Error::SPEAK;
    return (false);
}
