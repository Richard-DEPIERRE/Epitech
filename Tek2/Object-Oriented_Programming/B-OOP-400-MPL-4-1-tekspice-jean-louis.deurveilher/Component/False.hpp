/*
** EPITECH PROJECT, 2021
** False Component class
** File description:
** Header file
*/

#ifndef FALSE_COMPONENT_H_
#define FALSE_COMPONENT_H_

#include "Component.hpp"

class False : public Component {
    public:
        False(std::string name);
        ~False();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* !FALSE_COMPONENT_H_ */