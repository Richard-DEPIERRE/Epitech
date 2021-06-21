/*
** EPITECH PROJECT, 2021
** 4011 component
** File description:
** header file
*/

#ifndef COMPONENT4011_H_
#define COMPONENT4011_H_

#include "Component.hpp"

class c4011 : public Component {
    public:
        c4011(std::string name);
        ~c4011();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4011_H_ */