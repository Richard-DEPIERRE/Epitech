/*
** EPITECH PROJECT, 2021
** Clock component
** File description:
** file
*/

#include "IComponent.hpp"
#include "Clock.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

Clock::Clock(std::string name)
{
    _name.assign(name);
    _type.assign("clock");
    _prevState = nts::UNDEFINED;
    _firstTime = true;
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("defaultInput", nts::UNDEFINED));
}

Clock::~Clock()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

void Clock::simulate(std::size_t tick)
{
    bool enter = true;
    if (_firstTime == true) {
        _firstTime = false;
        return;
    }
    if (_tick == tick + 1)
        return;
    _tick = tick + 1;
    if (!_inputs.empty()) {
        for (std::map<std::size_t, nts::IComponent &>::iterator it = \
        _inputs.begin(); it != _inputs.end(); it++) {
            if (_prevState != it->second.compute(0)) {
                it->second.simulate(tick);
                _pins[0]->setState(it->second.compute(0), tick);
                _prevState = it->second.compute(0);
                enter = false;
            }
        }
    }
    if (enter) {
        switch (_pins[0]->getState()) {
            case nts::TRUE:
                _pins[0]->setState(nts::FALSE, tick);
                break;
            case nts::FALSE:
                _pins[0]->setState(nts::TRUE, tick);
                break;
            default:
                break;
        }
    }
}

nts::Tristate Clock::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void Clock::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
{
    if (getPins()[pin]->getType().compare("output") == 0) {
        _outputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
        _outputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
    }
    else {
        _inputs.insert(std::pair<size_t, nts::IComponent &>(pin, other));
        _inputPins.insert(std::pair<size_t, size_t>(pin, otherPin));
    }
    (void)otherPin;
}

void Clock::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++) {
        if (getPins()[i]->getType() != "defaultInput")
            std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}