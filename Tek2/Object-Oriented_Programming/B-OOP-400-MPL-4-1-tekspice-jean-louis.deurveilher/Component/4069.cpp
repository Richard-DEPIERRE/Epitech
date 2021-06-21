/*
** EPITECH PROJECT, 2021
** c4069 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4069.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4069::c4069(std::string name)
{
    _name.assign(name);
    _type.assign("4069");
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("ignored", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
}

c4069::~c4069()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

nts::Tristate getINVERTERState(nts::Tristate state1)
{
    if (state1 == nts::TRUE)
        return nts::FALSE;
    if (state1 == nts::FALSE)
        return nts::TRUE;
    return nts::UNDEFINED;
}

void c4069::simulate(std::size_t tick)
{
    if (_tick == tick + 1)
        return;
    _tick = tick + 1;
    if (!_inputs.empty()) {
        for (std::map<std::size_t, nts::IComponent &>::iterator it = \
        _inputs.begin(); it != _inputs.end(); it++) {
            it->second.simulate(tick);
            _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
        }
        _pins[1]->setState(getINVERTERState(_pins[0]->getState()), tick);
        _pins[3]->setState(getINVERTERState(_pins[2]->getState()), tick);
        _pins[5]->setState(getINVERTERState(_pins[4]->getState()), tick);
        _pins[7]->setState(getINVERTERState(_pins[8]->getState()), tick);
        _pins[9]->setState(getINVERTERState(_pins[10]->getState()), tick);
        _pins[11]->setState(getINVERTERState(_pins[12]->getState()), tick);
    }
}

nts::Tristate c4069::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4069::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    if (getPins()[pin]->getType().compare("output") == 0) {
        _outputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
        _outputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
    } else {
        _inputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
        _inputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
    }
}

void c4069::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}