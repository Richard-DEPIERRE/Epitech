/*
** EPITECH PROJECT, 2021
** True Component class
** File description:
** Header file
*/

#ifndef TRUE_COMPONENT_H_
#define TRUE_COMPONENT_H_

#include "Component.hpp"

class True : public Component {
    public:
        True(std::string name);
        ~True();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* !TRUE_COMPONENT_H_ */