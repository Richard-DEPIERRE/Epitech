/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include <iostream>
#include <csignal>
#include <memory>
#include <chrono>
#include <thread>
#include <boost/thread/thread.hpp>
#include "../Component/Component.hpp"
#include "../Component/IComponent.hpp"
#include "ComponentFactory.hpp"
#include "../Errors/ErrorCircuit.hpp"
#include "../Component/DefaultInput.hpp"
#include "../Component/Input.hpp"
#include "../Component/Clock.hpp"

class Circuit {
    public:
        Circuit();
        ~Circuit();
        void addComponent(std::string type, std::string name);
        void addLink(std::string comp1, std::size_t pin1, std::string comp2, std::size_t pin2);
        void exitCircuit();
        void display();
        void input(std::string name, std::string num);
        void simulate();
        void loop();
        void dump();
        void checkCircuit();

    protected:
    private:
        ComponentFactory _comp;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::map<std::string, std::string> _componentId;
        std::size_t _tick;
        bool _firstDone;
};

#endif /* !CIRCUIT_HPP_ */
