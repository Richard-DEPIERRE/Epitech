/*
** EPITECH PROJECT, 2021
** c4017 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4017.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4017::c4017(std::string name)
{
    _name.assign(name);
    _type.assign("4017");
    _str.assign("0000000000");
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 1  Q5 0000000010
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 2  Q1 0010000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 3  Q0 0000000001 || 0000000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 4  Q2 0100000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 5  Q6 1000000000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 6  Q7 0000100000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 7  Q3 0001000000
    _pins.push_back(new Pin("ignored", nts::UNDEFINED));    // 8
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 9  Q8 0000010000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 10 Q4 0000001000
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 11 Q9 0000000100
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 12 Q~5-9
    _pins.push_back(new Pin("clock", nts::UNDEFINED));      // 13 CP~1
    _pins.push_back(new Pin("clock", nts::UNDEFINED));      // 14 CP0
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 15 MR
}

c4017::~c4017()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

std::string getJOHNSONstate(std::map<size_t, nts::IComponent &> outputs, std::vector<Pin *> pins)
{
    std::string code;

    for (std::map<std::size_t, nts::IComponent &>::iterator it = outputs.begin(); it != outputs.end(); it++) {
        if (it->first != 11)
            code.push_back((pins[it->first]->getState() == nts::TRUE) ? '1' : '0');
    }
    return code;
}

void c4017::simulate(std::size_t tick)
{
    nts::Tristate cp1_prevState = _pins[12]->getState();
    nts::Tristate cp0_prevState = _pins[13]->getState();

    if (_tick == tick + 1)
        return;
    _tick = tick + 1;
    if (!_inputs.empty()) {
        for (std::map<std::size_t, nts::IComponent &>::iterator it = \
        _inputs.begin(); it != _inputs.end(); it++) {
            it->second.simulate(tick);
            _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
        }
        if ((cp0_prevState == nts::FALSE && _pins[13]->getState() == nts::TRUE && _pins[12]->getState() == nts::FALSE) ||
        (cp1_prevState == nts::TRUE && _pins[12]->getState() == nts::FALSE && _pins[13]->getState() == nts::TRUE)) {
            _str = (_pins[14]->getState() == nts::TRUE) ? "reset" : getJOHNSONstate(getOutputs(), _pins);
        }
        _pins[0]->setState((_str == "0000000010") ? nts::TRUE : nts::FALSE, tick);
        _pins[1]->setState((_str == "0010000000") ? nts::TRUE : nts::FALSE, tick);
        _pins[2]->setState((_str == "0000000001" || _str == "0000000000") ? nts::TRUE : nts::FALSE, tick);
        _pins[3]->setState((_str == "0100000000") ? nts::TRUE : nts::FALSE, tick);
        _pins[4]->setState((_str == "1000000000") ? nts::TRUE : nts::FALSE, tick);
        _pins[5]->setState((_str == "0000100000") ? nts::TRUE : nts::FALSE, tick);
        _pins[6]->setState((_str == "0001000000") ? nts::TRUE : nts::FALSE, tick);
        _pins[8]->setState((_str == "0000010000") ? nts::TRUE : nts::FALSE, tick);
        _pins[9]->setState((_str == "0000001000") ? nts::TRUE : nts::FALSE, tick);
        _pins[10]->setState((_str == "0000000100") ? nts::TRUE : nts::FALSE, tick);
        _pins[11]->setState((_str == "0000000010" || _str == "1000000000" || _str == "0000100000" || _str == "0000010000" || _str == "0000000100" || _str == "reset") ? nts::FALSE : nts::TRUE, tick);
        for (int i = 0; i < 12; i++)
            _pins[i]->setState((_str == "reset") ? nts::FALSE : _pins[i]->getState(), tick);
    }

}

nts::Tristate c4017::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4017::setLink(std::size_t pin, nts::IComponent &other,
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

void c4017::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}