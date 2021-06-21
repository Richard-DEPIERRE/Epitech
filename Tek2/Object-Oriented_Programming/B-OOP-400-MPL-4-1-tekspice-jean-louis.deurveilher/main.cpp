/*
** EPITECH PROJECT, 2021
** main
** File description:
** test file
*/

#include <iostream>
#include "Errors/Error.hpp"
#include "Parsing/Parsing.hpp"
#include "Circuit/Circuit.hpp"
#include "Component/Input.hpp"
#include "Component/Output.hpp"
#include "Component/Clock.hpp"
#include "Component/True.hpp"
#include "Component/False.hpp"

int mainLoop(Circuit &circuit)
{
    std::string line;
    bool continueProgram = true;

    try {
        circuit.simulate();
        while (continueProgram) {
            std::cout << "> ";
            if (!std::getline(std::cin, line))
                break;
            if (line.compare("simulate") == 0)
                circuit.simulate();
            else if (line.compare("display") == 0)
                circuit.display();
            else if (line.compare("exit") == 0)
                circuit.exitCircuit();
            else if (line.compare("loop") == 0)
                circuit.loop();
            else if (line.compare("dump") == 0)
                circuit.dump();
            else if (line.find("=") != std::string::npos) {
                std::string name = line.substr(0, line.find_last_of("="));
                std::string num = line.substr(line.find_last_of("=") + 1);
                circuit.input(name, num);
            } else {
                std::cout << "Please input a correct command." << std::endl;
            }
        }
    } catch (Error &e) {
        throw Error(std::cerr, e.what());
    }
    return 0;
}

int main(int ac, char **av)
{
    Parsing parse;
    Circuit circuit;
    bool hasComponents = false;

    if (ac != 2) {
        std::cerr << "Usage: ./nanotekspice 'filepath'" << std::endl;
        return (84);
    }
    try {
        parse.startParsing(av[1], circuit, hasComponents);
        if (!hasComponents)
            return (0);
        mainLoop(circuit);
    } catch (Error &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (84);
    }
    return 0;
}