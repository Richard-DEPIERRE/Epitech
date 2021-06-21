/*
** EPITECH PROJECT, 2021
** 4030 component
** File description:
** header file
*/

#ifndef COMPONENT4030_H_
#define COMPONENT4030_H_

#include "Component.hpp"

class c4030 : public Component {
    public:
        c4030(std::string name);
        ~c4030();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4030_H_ */