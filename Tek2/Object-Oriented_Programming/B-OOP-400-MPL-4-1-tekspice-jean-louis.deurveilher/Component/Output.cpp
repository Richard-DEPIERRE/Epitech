/*
** EPITECH PROJECT, 2021
** Output component
** File description:
** file
*/

#include "Output.hpp"

Output::Output(std::string name)
{
    _name.assign(name);
    _type.assign("output");
    _pins.push_back(new Pin("input", nts::UNDEFINED));
}

Output::~Output()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

void Output::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1)
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                it->second.simulate(tick);
                _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
            }
    }
}

nts::Tristate Output::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void Output::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    _inputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
    _inputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
}

void Output::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}