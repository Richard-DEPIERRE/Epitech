/*
** EPITECH PROJECT, 2021
** Component
** File description:
** file
*/

#include "Component.hpp"

Component::Component() : _tick(0)
{
}

Component::~Component()
{
}

void Component::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate Component::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void Component::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void Component::dump() const
{
}