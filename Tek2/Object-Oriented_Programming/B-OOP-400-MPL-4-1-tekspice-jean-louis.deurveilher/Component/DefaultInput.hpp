/*
** EPITECH PROJECT, 2021
** DefaultInput Component class
** File description:
** Header file
*/

#ifndef DEFAULTINPUT_COMPONENT_H_
#define DEFAULTINPUT_COMPONENT_H_

#include "Component.hpp"

class DefaultInput : public Component {
    public:
        DefaultInput(std::string name);
        ~DefaultInput();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* !DEFAULTINPUT_COMPONENT_H_ */