/*
** EPITECH PROJECT, 2021
** False component
** File description:
** file
*/

#include "IComponent.hpp"
#include "False.hpp"
#include "Pin.hpp"

False::False(std::string name)
{
    _name.assign(name);
    _type.assign("false");
    _pins.push_back(new Pin("output", nts::FALSE));
}

False::~False()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

void False::simulate(std::size_t tick)
{
    if (_pins[0]->getState() != nts::FALSE)
        _pins[0]->setState(nts::FALSE, tick);
}

nts::Tristate False::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void False::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    _outputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
    _outputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
}

void False::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}