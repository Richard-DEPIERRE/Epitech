/*
** EPITECH PROJECT, 2021
** DefaultInput component
** File description:
** file
*/

#include "IComponent.hpp"
#include "DefaultInput.hpp"
#include "Pin.hpp"

DefaultInput::DefaultInput(std::string name)
{
    _name.assign(name);
    _type.assign("defaultInput");
    _pins.push_back(new Pin("output", nts::UNDEFINED));
}

DefaultInput::~DefaultInput()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

void DefaultInput::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate DefaultInput::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void DefaultInput::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    _outputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
    _outputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
}

void DefaultInput::dump() const
{
}