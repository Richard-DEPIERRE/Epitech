/*
** EPITECH PROJECT, 2021
** 4069 component
** File description:
** header file
*/

#ifndef COMPONENT4069_H_
#define COMPONENT4069_H_

#include "Component.hpp"

class c4069 : public Component {
    public:
        c4069(std::string name);
        ~c4069();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4069_H_ */