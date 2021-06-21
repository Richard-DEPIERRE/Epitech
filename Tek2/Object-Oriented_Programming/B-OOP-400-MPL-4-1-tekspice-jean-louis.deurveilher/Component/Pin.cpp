/*
** EPITECH PROJECT, 2021
** Pin
** File description:
** file
*/

#include "Pin.hpp"

Pin::Pin(std::string type, nts::Tristate state)
    : _type(type), _state(state), _tick(0)
{
}

Pin::~Pin()
{
}

Pin &Pin::operator=(const Pin &other)
{
    _type = other._type;
    _state = other._state;
    return *this;
}
