/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(): _tick(0), _firstDone(false)
{
    ComponentFactory *comp_fact = new ComponentFactory;

    _comp = *comp_fact;
    delete comp_fact;
}

Circuit::~Circuit()
{
}

void Circuit::addComponent(std::string type, std::string name)
{
    std::string value;
    if (name.find_last_of("(") != std::string::npos) {
        value = name.substr(name.find("(") + 1, name.find(")") - (name.find("(") + 1));
        name = name.substr(0, name.find("("));
    }
    if (type == "input" || type == "clock") {
        std::string namedef = "defaultInput" + name;
        _components.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(namedef, _comp.createComponent("defaultInput", namedef)));
        _componentId.insert(std::pair<std::string, std::string>(namedef, "defaultInput"));
        _components.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(name, _comp.createComponent(type, name)));
        _componentId.insert(std::pair<std::string, std::string>(name, type));
        addLink(namedef, 0, name, 1);
    } else {
        _components.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(name, _comp.createComponent(type, name)));
        _componentId.insert(std::pair<std::string, std::string>(name, type));
    }
    if (value != "")
        input(name, value);
}

void Circuit::addLink(std::string comp1, std::size_t pin1, std::string comp2, std::size_t pin2)
{
    if (_components.find(comp1) == _components.end())
        throw ErrorCircuit(std::cerr, "Component \"" + comp1 + "\" cannot be linked to \"" + comp2 + "\" because \"" + comp1 +"\" wasn't declared before.");
    if (_components.find(comp2) == _components.end())
        throw ErrorCircuit(std::cerr, "Component \"" + comp2 + "\" cannot be linked to \"" + comp1 + "\" because \"" + comp2 + "\" wasn't declared before.");
    _components[comp1]->setLink(pin1, (*_components[comp2]), pin2);
    _components[comp2]->setLink(pin2, (*_components[comp1]), pin1);
}

void Circuit::exitCircuit()
{
    exit (0);
}

void Circuit::display()
{
    std::cout << "tick: " << std::to_string(_tick) << std::endl;
    std::cout << "input(s):" << std::endl;
    for(const auto& n : _componentId) {
        if (n.second == "input" || n.second == "clock") {
            std::cout << "  " << n.first << ": " << ((_components[n.first]->compute(0) == nts::TRUE) ? "1" : (_components[n.first]->compute(0) == nts::FALSE) ? "0" : "U") << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for(const auto& n : _componentId) {
        if (n.second == "output") {
            std::cout << "  " << n.first << ": " << ((_components[n.first]->compute(0) == nts::TRUE) ? "1" : (_components[n.first]->compute(0) == nts::FALSE) ? "0" : "U") << std::endl;
        }
    }
}

void Circuit::input(std::string name, std::string num)
{
    // std::cout << "num : >" << num << "<" << std::endl;
    if (num != "0" && num != "1" && num != "U")
        throw ErrorCircuit(std::cerr, "'" + num + "' : is not a correct value, please input '0', '1' or 'U'");
    for (const auto& n : _componentId)
        if (n.first == name && n.second != "input" && n.second != "clock") {
            throw ErrorCircuit(std::cerr, "'" + name + "' : is not an 'input' component but a '" + + "'");
            return;
        } else if (n.first == name && (n.second == "input" || n.second == "clock")) {
            DefaultInput *defaultInput = dynamic_cast<DefaultInput *>(_components["defaultInput" + name].get());
            defaultInput->getPins()[0]->setState((num == "0") ? nts::FALSE : (num == "1") ? nts::TRUE : nts::UNDEFINED, 0);
            return;
        }
    throw ErrorCircuit(std::cerr, "'" + name + "' : is not a component in this circuit");
}

void Circuit::simulate()
{
    if (!_firstDone) {
        for (const auto& n : _componentId)
            if (n.second == "input" || n.second == "clock" || n.second == "true" || n.second == "false")
                _components[n.first]->simulate(_tick);
        _firstDone = true;
    } else
        _tick++;
    for (const auto& n : _componentId)
        if (n.second == "output")
            _components[n.first]->simulate(_tick);
}

void Circuit::loop()
{
    while (1) {
        simulate();
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void Circuit::dump()
{
    std::cout << "------------------------------" << std::endl;
    for (const auto& n : _componentId) {
        _components[n.first]->dump();
    }
}

void Circuit::checkCircuit()
{
    if (_components.empty() == true)
        throw ErrorCircuit(std::cerr, "No components are present in Circuit");
}
