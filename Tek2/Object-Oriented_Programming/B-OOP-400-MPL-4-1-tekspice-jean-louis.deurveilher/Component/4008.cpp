/*
** EPITECH PROJECT, 2021
** c4008 component
** File description:
** file
*/

#include "IComponent.hpp"
#include "4008.hpp"
#include "Pin.hpp"
#include "DefaultInput.hpp"

c4008::c4008(std::string name)
{
    _name.assign(name);
    _type.assign("4008");
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //1
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //2
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //3
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //4
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //5
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //6
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //7
    _pins.push_back(new Pin("ignored", nts::UNDEFINED));    //8
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //9
    _pins.push_back(new Pin("output", nts::UNDEFINED));     //10
    _pins.push_back(new Pin("output", nts::UNDEFINED));     //11
    _pins.push_back(new Pin("output", nts::UNDEFINED));     //12
    _pins.push_back(new Pin("output", nts::UNDEFINED));     //13
    _pins.push_back(new Pin("output", nts::UNDEFINED));     //14
    _pins.push_back(new Pin("input", nts::UNDEFINED));      //15
}

c4008::~c4008()
{
    for (std::size_t i = 0; i < _pins.size(); i++)
        delete _pins[i];
}

nts::Tristate getADDERState(nts::Tristate state1, nts::Tristate state2, nts::Tristate &statec)
{
    nts::Tristate res = getXORState(statec, getXORState(state1, state2));
    statec = getORState(getANDState(statec, getXORState(state1, state2)), getANDState(state1, state2));
    return res;
}

void c4008::simulate(std::size_t tick)
{
    if (!_inputs.empty()) {
        if (_tick != tick + 1)
            for (std::map<std::size_t, nts::IComponent &>::iterator it = \
            _inputs.begin(); it != _inputs.end(); it++) {
                it->second.simulate(tick);
                _pins[it->first]->setState(it->second.compute(_inputPins[it->first]), tick);
            }
        nts::Tristate c = _pins[8]->getState();
        _pins[9]->setState(getADDERState(_pins[5]->getState(), _pins[6]->getState(), c), tick);
        _pins[10]->setState(getADDERState(_pins[3]->getState(), _pins[4]->getState(), c), tick);
        _pins[11]->setState(getADDERState(_pins[2]->getState(), _pins[1]->getState(), c), tick);
        _pins[12]->setState(getADDERState(_pins[0]->getState(), _pins[14]->getState(), c), tick);
        _pins[13]->setState(c, tick);
    }
}

nts::Tristate c4008::compute(std::size_t pin)
{
    return (_pins[pin]->getState());
}

void c4008::setLink(std::size_t pin, nts::IComponent &other,
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

void c4008::dump() const
{
    std::cout << getType() << ": " << getName() << std::endl;
    std::cout << "pins:" <<std::endl;
    for (std::size_t i = 0; i < getPins().size(); i++)
        std::cout << "   n°" << i + 1 << "  Type : " << getPins()[i]->getType() << "  State : " << getPins()[i]->getState() << std::endl;
    std::cout << "------------------------------" << std::endl;
}