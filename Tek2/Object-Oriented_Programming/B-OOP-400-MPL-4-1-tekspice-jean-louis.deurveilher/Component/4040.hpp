/*
** EPITECH PROJECT, 2021
** 4040 component
** File description:
** header file
*/

#ifndef COMPONENT4040_H_
#define COMPONENT4040_H_

#include "Component.hpp"

class c4040 : public Component {
    public:
        c4040(std::string name);
        ~c4040();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
        size_t _counter;
};

#endif /* COMPONENT4040_H_ */