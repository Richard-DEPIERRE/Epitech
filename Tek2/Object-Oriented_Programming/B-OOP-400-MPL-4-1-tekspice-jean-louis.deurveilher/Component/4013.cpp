/*
** EPITECH PROJECT, 2021
** c4013 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4013.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4013::c4013(std::string name)
{
    _name.assign(name);
    _type.assign("4013");
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 0 Q1
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 1 Q~1
    _pins.push_back(new Pin("clock", nts::UNDEFINED));      // 2 clock1
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 3 reset1
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 4 data1
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 5 set1
    _pins.push_back(new Pin("ignored", nts::UNDEFINED));    // 6
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 7 set2
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 8 data2
    _pins.push_back(new Pin("input", nts::UNDEFINED));      // 9 reset2
    _pins.push_back(new Pin("clock", nts::UNDEFINED));      // 10 clock2
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 11 Q~2
    _pins.push_back(new Pin("output", nts::UNDEFINED));     // 12 Q2
}

c4013::~c4013()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

std::string getFLIPFLOPStateCdrs(nts::Tristate stateCl, nts::Tristate stateD, nts::Tristate stateR, nts::Tristate stateS, nts::Tristate prev)
{
    std::string code;

    if (stateCl == nts::UNDEFINED || stateD == nts::UNDEFINED
    || stateR == nts::UNDEFINED || stateS == nts::UNDEFINED)
        return "UUUU";
    code.push_back((stateCl == nts::TRUE && prev == nts::FALSE) ? '1' : '0');
    code.push_back((stateD == nts::TRUE) ? '1' : '0');
    code.push_back((stateR == nts::TRUE) ? '1' : '0');
    code.push_back((stateS == nts::TRUE) ? '1' : '0');
    return code;
}

std::string getFLIPFLOPStateRs(nts::Tristate stateR, nts::Tristate stateS)
{
    std::string code;
    if (stateR == nts::UNDEFINED || stateS == nts::UNDEFINED)
        return "UUUU";
    code.push_back((stateR == nts::TRUE) ? '1' : '0');
    code.push_back((stateS == nts::TRUE) ? '1' : '0');
    return code;
}

void c4013::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1) {
            _tick = tick + 1;
            nts::Tristate prev1 = _pins[2]->getState();
            nts::Tristate prev2 = _pins[10]->getState();
            std::string CDRSstate1 = "UUUU";
            std::string CDRSstate2 = "UUUU";
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                it->second.simulate(tick);
                _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
            }
            CDRSstate1 = getFLIPFLOPStateCdrs(_pins[2]->getState(),_pins[4]->getState(),_pins[3]->getState(),_pins[5]->getState(), prev1);
            CDRSstate2 = getFLIPFLOPStateCdrs(_pins[10]->getState(),_pins[8]->getState(),_pins[9]->getState(),_pins[7]->getState(), prev2);
            std::string RSstate1 = getFLIPFLOPStateRs(_pins[3]->getState(),_pins[5]->getState());
            std::string RSstate2 = getFLIPFLOPStateRs(_pins[9]->getState(),_pins[7]->getState());
            _pins[0]->setState((CDRSstate1 == "1100" || RSstate1 == "01" || RSstate1 == "11") ? nts::TRUE : _pins[0]->getState(), tick);
            _pins[0]->setState((CDRSstate1 == "1000" || RSstate1 == "10") ? nts::FALSE : _pins[0]->getState(), tick);
            _pins[1]->setState((CDRSstate1 == "1000" || RSstate1 == "10" || RSstate1 == "11") ? nts::TRUE : _pins[1]->getState(), tick);
            _pins[1]->setState((CDRSstate1 == "1100" || RSstate1 == "01") ? nts::FALSE : _pins[1]->getState(), tick);
            _pins[12]->setState((CDRSstate2 == "1100" || RSstate2 == "01" || RSstate2 == "11") ? nts::TRUE : _pins[12]->getState(), tick);
            _pins[12]->setState((CDRSstate2 == "1000" || RSstate2 == "10") ? nts::FALSE : _pins[12]->getState(), tick);
            _pins[11]->setState((CDRSstate2 == "1000" || RSstate2 == "10" || RSstate2 == "11") ? nts::TRUE : _pins[11]->getState(), tick);
            _pins[11]->setState((CDRSstate2 == "1100" || RSstate2 == "01") ? nts::FALSE : _pins[11]->getState(), tick);
        }
    }
}

nts::Tristate c4013::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4013::setLink(std::size_t pin, nts::IComponent &other,
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

void c4013::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}