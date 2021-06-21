/*
** EPITECH PROJECT, 2021
** 4514 component
** File description:
** header file
*/

#ifndef COMPONENT4514_H_
#define COMPONENT4514_H_

#include "Component.hpp"

class c4514 : public Component {
    public:
        c4514(std::string name);
        ~c4514();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4514_H_ */