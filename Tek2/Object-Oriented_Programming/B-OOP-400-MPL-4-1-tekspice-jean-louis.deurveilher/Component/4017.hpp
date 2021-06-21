/*
** EPITECH PROJECT, 2021
** 4017 component
** File description:
** header file
*/

#ifndef COMPONENT4017_H_
#define COMPONENT4017_H_

#include "Component.hpp"

class c4017 : public Component {
    public:
        c4017(std::string name);
        ~c4017();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
        std::string _str;
};

#endif /* COMPONENT4017_H_ */