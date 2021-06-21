/*
** EPITECH PROJECT, 2021
** 4512 component
** File description:
** header file
*/

#ifndef COMPONENT4512_H_
#define COMPONENT4512_H_

#include "Component.hpp"

class c4512 : public Component {
    public:
        c4512(std::string name);
        ~c4512();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4512_H_ */