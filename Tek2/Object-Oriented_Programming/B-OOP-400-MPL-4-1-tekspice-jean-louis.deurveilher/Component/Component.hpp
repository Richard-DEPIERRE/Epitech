/*
** EPITECH PROJECT, 2021
** Component Class
** File description:
** Header file
*/

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include "IComponent.hpp"
#include "Pin.hpp"

class Component : public nts::IComponent {
    public:
        Component();
        virtual ~Component();
        virtual void simulate(std::size_t tick);
        virtual nts::Tristate compute(std::size_t pin);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        std::string getName() const {
            return _name;
        }
        void setName(std::string name) {
            _name = name;
        }
        std::string getType() const {
            return _type;
        }
        void setType(std::string type) {
            _type = type;
        }
        std::vector<Pin *> getPins() const {
            return _pins;
        }
        std::map<size_t, nts::IComponent &> getInputs() const {
            return _inputs;
        }
        std::map<size_t, nts::IComponent &> getOutputs() const {
            return _outputs;
        }

    protected:
        std::string _name;
        std::string _type;
        std::size_t _tick;
        std::vector<Pin *> _pins;
        std::map<size_t, nts::IComponent &> _inputs;
        std::map<size_t, size_t> _inputPins;
        std::map<size_t, nts::IComponent &> _outputs;
        std::map<size_t, size_t> _outputPins;

    private:
};

#endif /* !COMPONENT_H_ */