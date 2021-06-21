/*
** EPITECH PROJECT, 2021
** c4514 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4514.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4514::c4514(std::string name)
{
    _name.assign(name);
    _type.assign("4514");
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 1 strobe
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 2 A
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 3 B
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 4
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 5
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 6
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 7
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 8
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 8
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 10
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 11
    _pins.push_back(new Pin("ignore", nts::UNDEFINED)); // 12
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 13
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 14
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 15
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 16
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 17
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 18
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 19
    _pins.push_back(new Pin("output", nts::UNDEFINED)); // 20
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 21 C
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 22 D
    _pins.push_back(new Pin("input", nts::UNDEFINED)); // 23 inhibit
}

c4514::~c4514()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

std::string getDECODERState(nts::Tristate stateA, nts::Tristate stateB, nts::Tristate stateC, nts::Tristate stateD)
{
    std::string code;

    code.push_back((stateD == nts::TRUE) ? '1' : '0');
    code.push_back((stateC == nts::TRUE) ? '1' : '0');
    code.push_back((stateB == nts::TRUE) ? '1' : '0');
    code.push_back((stateA == nts::TRUE) ? '1' : '0');
    return code;
}

void c4514::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1) {
            _tick = tick + 1;
            // nts::Tristate prevState = _pins[0]->getState();
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                it->second.simulate(tick);
                _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
            }
            if (_pins[22]->getState() == nts::TRUE) {
                for (std::map<std::size_t, nts::IComponent &>::iterator it = \
                _outputs.begin(); it != _outputs.end(); it++)
                    _pins[it->first]->setState(nts::FALSE, tick);
                return;
            }
            if ((_pins[1]->getState() == nts::UNDEFINED ||  _pins[2]->getState() == nts::UNDEFINED ||  _pins[20]->getState() == nts::UNDEFINED ||  _pins[21]->getState() == nts::UNDEFINED) && _pins[0]->getState() == nts::FALSE) {
                for (std::map<std::size_t, nts::IComponent &>::iterator it = \
                _outputs.begin(); it != _outputs.end(); it++)
                    _pins[it->first]->setState(nts::UNDEFINED, tick);
                return;
            }
            std::string str = getDECODERState(_pins[1]->getState(), _pins[2]->getState(), _pins[20]->getState(), _pins[21]->getState());
            if (_pins[0]->getState() == nts::FALSE) {
                _pins[3]->setState((str == "0111") ? nts::TRUE : nts::FALSE, tick);
                _pins[4]->setState((str == "0110") ? nts::TRUE : nts::FALSE, tick);
                _pins[5]->setState((str == "0101") ? nts::TRUE : nts::FALSE, tick);
                _pins[6]->setState((str == "0100") ? nts::TRUE : nts::FALSE, tick);
                _pins[7]->setState((str == "0011") ? nts::TRUE : nts::FALSE, tick);
                _pins[8]->setState((str == "0001") ? nts::TRUE : nts::FALSE, tick);
                _pins[9]->setState((str == "0010") ? nts::TRUE : nts::FALSE, tick);
                _pins[10]->setState((str == "0000") ? nts::TRUE : nts::FALSE, tick);
                _pins[12]->setState((str == "1101") ? nts::TRUE : nts::FALSE, tick);
                _pins[13]->setState((str == "1100") ? nts::TRUE : nts::FALSE, tick);
                _pins[14]->setState((str == "1111") ? nts::TRUE : nts::FALSE, tick);
                _pins[15]->setState((str == "1110") ? nts::TRUE : nts::FALSE, tick);
                _pins[16]->setState((str == "1001") ? nts::TRUE : nts::FALSE, tick);
                _pins[17]->setState((str == "1000") ? nts::TRUE : nts::FALSE, tick);
                _pins[18]->setState((str == "1011") ? nts::TRUE : nts::FALSE, tick);
                _pins[19]->setState((str == "1010") ? nts::TRUE : nts::FALSE, tick);
            }
        }
    }
}

nts::Tristate c4514::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4514::setLink(std::size_t pin, nts::IComponent &other,
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

void c4514::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}