/*
** EPITECH PROJECT, 2021
** 4008 component
** File description:
** header file
*/

#ifndef COMPONENT4008_H_
#define COMPONENT4008_H_

#include "Component.hpp"

nts::Tristate getORState(nts::Tristate state1, nts::Tristate state2);
nts::Tristate getXORState(nts::Tristate state1, nts::Tristate state2);
nts::Tristate getANDState(nts::Tristate state1, nts::Tristate state2);

class c4008 : public Component {
    public:
        c4008(std::string name);
        ~c4008();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4008_H_ */