/*
** EPITECH PROJECT, 2021
** Clock Component class
** File description:
** Header file
*/

#ifndef CLOCK_COMPONENT_H_
#define CLOCK_COMPONENT_H_

#include "Component.hpp"

class Clock : public Component {
    public:
        Clock(std::string name);
        ~Clock();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
        nts::Tristate _prevState;
        bool _firstTime;
};

#endif /* !CLOCK_COMPONENT_H_ */