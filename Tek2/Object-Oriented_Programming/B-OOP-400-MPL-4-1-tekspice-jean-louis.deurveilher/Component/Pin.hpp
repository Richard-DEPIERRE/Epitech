/*
** EPITECH PROJECT, 2021
** Pin
** File description:
** Struct
*/

#ifndef PIN_H_
#define PIN_H_

#include "IComponent.hpp"

class Pin {
    public:
        Pin(std::string type, nts::Tristate state);
        ~Pin();
        Pin &operator=(const Pin &other);
        std::string getType() {
            return _type;
        }
        nts::Tristate getState() {
            return _state;
        }
        std::size_t getTick() {
            return _tick;
        }
        void setState(nts::Tristate state, std::size_t tick) {
            _state = state;
            setTick(tick + 1);
        }
        void setType(std::string type) {
            _type = type;
        }
        void setTick(std::size_t tick) {
            _tick = tick;
        }

    private:
        std::string _type;
        nts::Tristate _state;
        std::size_t _tick;
};

#endif /* !PIN_H_ */