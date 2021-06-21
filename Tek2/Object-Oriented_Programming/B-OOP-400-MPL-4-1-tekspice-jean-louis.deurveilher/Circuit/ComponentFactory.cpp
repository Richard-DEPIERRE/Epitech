/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

ComponentFactory::ComponentFactory()
{
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("input", [](std::string name) { return std::unique_ptr<nts::IComponent>(new Input(name)); }));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("defaultInput", [](std::string name) { return std::unique_ptr<nts::IComponent>(new DefaultInput(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("output", [](std::string name) { return std::unique_ptr<nts::IComponent>(new Output(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("true", [](std::string name) { return std::unique_ptr<nts::IComponent>(new True(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("false", [](std::string name) { return std::unique_ptr<nts::IComponent>(new False(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("clock", [](std::string name) { return std::unique_ptr<nts::IComponent>(new Clock(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4001", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4001(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4008", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4008(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4011", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4011(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4013", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4013(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4017", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4017(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4030", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4030(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4040", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4040(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4069", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4069(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4071", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4071(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4081", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4081(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4514", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4514(name));}));
    _map.insert(std::pair<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>>("4512", [](std::string name) { return std::unique_ptr<nts::IComponent>(new c4512(name));}));
}

ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string &type, const std::string &name)
{
    std::function<std::unique_ptr<nts::IComponent>(const std::string &value)> ptr;

    if (_map.find(type) == _map.end())
        throw ErrorCircuit(std::cerr, "'" + type + "': unknow chipset's type");
    return  _map[type](name);
}