/*
** EPITECH PROJECT, 2021
** Output component class
** File description:
** header file
*/

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Component.hpp"

class Output : public Component {
    public:
        Output(std::string name);
        ~Output();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
};

#endif /* !OUTPUT_H_ */