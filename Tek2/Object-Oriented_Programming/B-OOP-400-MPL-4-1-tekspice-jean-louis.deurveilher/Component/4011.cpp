/*
** EPITECH PROJECT, 2021
** c4011 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4011.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4011::c4011(std::string name)
{
    _name.assign(name);
    _type.assign("4011");
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("ignored", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
    _pins.push_back(new Pin("input", nts::UNDEFINED));
}

c4011::~c4011()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

nts::Tristate getNANDState(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == nts::FALSE || state2 == nts::FALSE)
        return nts::TRUE;
    if (state1 == nts::TRUE && state2 == nts::TRUE)
        return nts::FALSE;
    return nts::UNDEFINED;
}

void c4011::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1)
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                it->second.simulate(tick);
                _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
            }
        _pins[2]->setState(getNANDState(_pins[0]->getState(), _pins[1]->getState()), tick);
        _pins[3]->setState(getNANDState(_pins[4]->getState(), _pins[5]->getState()), tick);
        _pins[9]->setState(getNANDState(_pins[7]->getState(), _pins[8]->getState()), tick);
        _pins[10]->setState(getNANDState(_pins[11]->getState(), _pins[12]->getState()), tick);
    }
}

nts::Tristate c4011::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4011::setLink(std::size_t pin, nts::IComponent &other,
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

void c4011::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}