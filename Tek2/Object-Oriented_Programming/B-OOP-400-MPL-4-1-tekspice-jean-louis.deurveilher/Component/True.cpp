/*
** EPITECH PROJECT, 2021
** True component
** File description:
** file
*/

#include "IComponent.hpp"
#include "True.hpp"
#include "Pin.hpp"

True::True(std::string name)
{
    _name.assign(name);
    _type.assign("true");
    _pins.push_back(new Pin("output", nts::TRUE));
}

True::~True()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

void True::simulate(std::size_t tick)
{
    if (_pins[0]->getState() != nts::TRUE)
        _pins[0]->setState(nts::TRUE, tick);
}

nts::Tristate True::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void True::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    _outputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
    _outputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
}

void True::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}