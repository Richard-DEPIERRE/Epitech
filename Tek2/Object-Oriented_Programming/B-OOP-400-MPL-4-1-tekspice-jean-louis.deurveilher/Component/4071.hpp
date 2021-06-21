/*
** EPITECH PROJECT, 2021
** 4071 component
** File description:
** header file
*/

#ifndef COMPONENT4071_H_
#define COMPONENT4071_H_

#include "Component.hpp"

class c4071 : public Component {
    public:
        c4071(std::string name);
        ~c4071();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4071_H_ */