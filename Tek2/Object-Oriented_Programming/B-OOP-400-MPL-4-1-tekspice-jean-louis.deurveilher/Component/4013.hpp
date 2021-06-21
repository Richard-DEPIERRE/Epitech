/*
** EPITECH PROJECT, 2021
** 4013 component
** File description:
** header file
*/

#ifndef COMPONENT4013_H_
#define COMPONENT4013_H_

#include "Component.hpp"

class c4013 : public Component {
    public:
        c4013(std::string name);
        ~c4013();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* COMPONENT4013_H_ */