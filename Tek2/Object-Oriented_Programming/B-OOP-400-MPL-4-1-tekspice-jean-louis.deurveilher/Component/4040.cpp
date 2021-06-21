/*
** EPITECH PROJECT, 2021
** c4040 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4040.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4040::c4040(std::string name)
{
    _name.assign(name);
    _type.assign("4040");
    _counter = 0;
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 1  Q12 000000000001
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 2  Q6  001000000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 3  Q5  000010000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 4  Q7  010000000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 5  Q4  000001000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 6  Q3  000000100000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 7  Q2  000000010000
    _pins.push_back(new Pin("ignored", nts::UNDEFINED));    // 8
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 9  Q1  100000000000 || 000000000000
    _pins.push_back(new Pin("clock", nts::UNDEFINED));      // 10 Clock
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 11 Reset
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 12 Q9  000000000100
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 13 Q8  000100000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 14 Q10 000000001000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 15 Q11 000000000010
}

c4040::~c4040()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

std::string getCOUNTERstate(std::map<size_t, nts::IComponent &> outputs, std::vector<Pin *> pins)
{
    std::string code;

    for (std::map<std::size_t, nts::IComponent &>::iterator it = outputs.begin(); it != outputs.end(); it++)
            code.push_back((pins[it->first]->getState() == nts::TRUE) ? '1' : '0');
    return code;
}

void c4040::simulate(std::size_t tick)
{
    nts::Tristate clock_prevState = _pins[9]->getState();

    if (_tick == tick + 1)
        return;
    _tick = tick + 1;
    if (!_inputs.empty()) {
        for (std::map<std::size_t, nts::IComponent &>::iterator it = \
        _inputs.begin(); it != _inputs.end(); it++) {
            it->second.simulate(tick);
            _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
        }
        if (clock_prevState == nts::TRUE &&  _pins[9]->getState() == nts::FALSE)
            _counter++;
        std::string str = std::bitset<12>(_counter).to_string();
        std::reverse(str.begin(), str.end());
        _pins[0]->setState((str[11] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[1]->setState((str[5] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[2]->setState((str[4] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[3]->setState((str[6] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[4]->setState((str[3] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[5]->setState((str[2] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[6]->setState((str[1] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[8]->setState((str[0] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[11]->setState((str[8] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[12]->setState((str[7] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[13]->setState((str[9] == '1') ? nts::TRUE : nts::FALSE, tick);
        _pins[14]->setState((str[10] == '1') ? nts::TRUE : nts::FALSE, tick);
        for (int i = 0; i < 14; i++)
            if (_pins[i]->getType() == "output")
                _pins[i]->setState((str == "reset") ? nts::FALSE : _pins[i]->getState(), tick);
    }
}

nts::Tristate c4040::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4040::setLink(std::size_t pin, nts::IComponent &other,
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

void c4040::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}