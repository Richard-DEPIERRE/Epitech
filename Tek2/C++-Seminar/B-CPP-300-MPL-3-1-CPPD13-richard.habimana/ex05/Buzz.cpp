/*
** EPITECH PROJECT, 2021
** Piscine_Cpp
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &ascii): Toy(BUZZ, name, ascii) 
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(const std::string &statement) const
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " senorita \"" << statement << "\" senorita" << std::endl;
    return (true);
}