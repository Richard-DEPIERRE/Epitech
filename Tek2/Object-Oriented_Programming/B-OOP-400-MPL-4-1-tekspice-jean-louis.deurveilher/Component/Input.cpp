/*
** EPITECH PROJECT, 2021
** Input component
** File description:
** file
*/

#include "IComponent.hpp"
#include "Input.hpp"
#include "DefaultInput.hpp"
#include "Pin.hpp"

Input::Input(std::string name)
{
    _name.assign(name);
    _type.assign("input");
    _prevState = nts::UNDEFINED;
    _pins.push_back(new Pin("output", nts::UNDEFINED));
    _pins.push_back(new Pin("defaultInput", nts::UNDEFINED));
}

Input::~Input()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

void Input::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1)
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                if (_prevState != it->second.compute(0)) {
                    it->second.simulate(tick);
                    _pins[0]->setState(it->second.compute(0), tick);
                    _prevState = it->second.compute(0);
                }
            }
    }
}

nts::Tristate Input::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void Input::setLink(std::size_t pin, nts::IComponent &other,
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

void Input::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++) {
        if (getPins()[i]->getType() != "defaultInput")
            std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}