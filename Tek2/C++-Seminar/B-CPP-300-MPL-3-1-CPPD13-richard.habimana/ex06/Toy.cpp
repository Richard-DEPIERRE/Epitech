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
    _pic.data = toy._pic.data;
    _type = toy._type;
    return (*this);
}

bool Toy::speak(const std::string &statement) const
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(const std::string &statement)
{
    _error.type = Toy::Error::SPEAK;
    (void)statement;
    return (false);
}

bool Toy::setAscii(const std::string &filename)
{
    if (_pic.getPictureFromFile(filename) == false)
        _error.type = Toy::Error::PICTURE;
    return _pic.getPictureFromFile(filename);
};

Toy &Toy::operator<<(const std::string &str)
{
    _pic.data = str;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    return(os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

std::string const Toy::Error::what() const
{
    if (type == UNKNOWN)
        return ("");
    else if (type == PICTURE)
        return ("bad new illustration");
    return ("wrong mode");
}

std::string const Toy::Error::where() const
{
    if (type == UNKNOWN)
        return ("");
    else if (type == PICTURE)
        return ("setAscii");
    return ("speak_es");
}