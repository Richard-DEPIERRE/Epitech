/*
** EPITECH PROJECT, 2021
** 4001 component
** File description:
** header file
*/

#ifndef COMPONENT4001_H_
#define COMPONENT4001_H_

#include "Component.hpp"

class c4001 : public Component {
    public:
        c4001(std::string name);
        ~c4001();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4001_H_ */