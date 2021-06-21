/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <memory>
#include <unordered_map>
#include <functional>
#include "../Errors/ErrorCircuit.hpp"
#include "../Component/IComponent.hpp"
#include "../Component/Component.hpp"
#include "../Component/Input.hpp"
#include "../Component/DefaultInput.hpp"
#include "../Component/Output.hpp"
#include "../Component/Clock.hpp"
#include "../Component/True.hpp"
#include "../Component/False.hpp"
#include "../Component/4081.hpp"
#include "../Component/4001.hpp"
#include "../Component/4008.hpp"
#include "../Component/4011.hpp"
#include "../Component/4013.hpp"
#include "../Component/4017.hpp"
#include "../Component/4030.hpp"
#include "../Component/4040.hpp"
#include "../Component/4069.hpp"
#include "../Component/4071.hpp"
#include "../Component/4514.hpp"
#include "../Component/4512.hpp"

class ComponentFactory {
    public:
        ComponentFactory();
        ~ComponentFactory();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
    protected:
        std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>> _map;
    private:
};

#endif /* !COMPONENTFACTORY_HPP_ */
