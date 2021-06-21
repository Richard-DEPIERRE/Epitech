/*
** EPITECH PROJECT, 2021
** Input Component class
** File description:
** Header file
*/

#ifndef INPUT_COMPONENT_H_
#define INPUT_COMPONENT_H_

#include "Component.hpp"

class Input : public Component {
    public:
        Input(std::string name);
        ~Input();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
        nts::Tristate _prevState;
};

#endif /* !INPUT_COMPONENT_H_ */