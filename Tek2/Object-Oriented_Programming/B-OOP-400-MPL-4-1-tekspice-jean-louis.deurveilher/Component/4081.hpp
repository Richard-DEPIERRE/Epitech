/*
** EPITECH PROJECT, 2021
** 4081 component
** File description:
** header file
*/

#ifndef COMPONENT4081_H_
#define COMPONENT4081_H_

#include "Component.hpp"

class c4081 : public Component {
    public:
        c4081(std::string name);
        ~c4081();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4081_H_ */