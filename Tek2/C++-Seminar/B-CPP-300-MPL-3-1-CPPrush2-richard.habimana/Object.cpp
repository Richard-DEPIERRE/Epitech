/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &title, const std::string &type): _title(title), _type(type)
{
}

Object::~Object()
{
}

std::string Object::getTitle() const
{
    return (_title);
}

std::string Object::getType() const
{
    return (_type);
}

std::ostream &operator<<(std::ostream &os, const Object &object)
{
    os << object.getTitle();
    return (os);
}

void Object::setType(const std::string type)
{
    _type = type;
}