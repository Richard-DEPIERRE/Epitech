/*
** EPITECH PROJECT, 2021
** c4512 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4512.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4512::c4512(std::string name)
{
    _name.assign(name);
    _type.assign("4512");
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 1 in_0
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 2 in_1
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 3 in_2
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 4 in_3
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 5 in_4
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 6 in_5
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 7 in_6
    _pins.push_back(new Pin("ignored", nts::UNDEFINED)); // 8
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 9 in_7
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 10 inhibit
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 11 in_c
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 12 in_b
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 13 in_a
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 14 out_data
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 15 enable
}

c4512::~c4512()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

std::string getSELECTORState(nts::Tristate stateC, nts::Tristate stateB, nts::Tristate stateA)
{
    std::string code;

    code.push_back((stateC == nts::TRUE) ? '1' : '0');
    code.push_back((stateB == nts::TRUE) ? '1' : '0');
    code.push_back((stateA == nts::TRUE) ? '1' : '0');
    return code;
}

void c4512::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1)
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                it->second.simulate(tick);
                _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
            }
        std::string str = getSELECTORState(_pins[10]->getState(), _pins[11]->getState(), _pins[12]->getState());
        nts::Tristate state = nts::UNDEFINED;
        state = (str == "000") ? _pins[0]->getState() : state;
        state = (str == "001") ? _pins[1]->getState() : state;
        state = (str == "010") ? _pins[2]->getState() : state;
        state = (str == "011") ? _pins[3]->getState() : state;
        state = (str == "100") ? _pins[4]->getState() : state;
        state = (str == "101") ? _pins[5]->getState() : state;
        state = (str == "110") ? _pins[6]->getState() : state;
        state = (str == "111") ? _pins[8]->getState() : state;
        if (_pins[9]->getState() == nts::TRUE && _pins[14]->getState() == nts::FALSE)
            state = nts::FALSE;
        if (_pins[14]->getState() == nts::TRUE)
            state = nts::UNDEFINED;
        _pins[13]->setState(state, tick);
    }
}

nts::Tristate c4512::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4512::setLink(std::size_t pin, nts::IComponent &other,
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

void c4512::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}