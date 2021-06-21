/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include <string>
#include <fstream>
#include <regex>
#include <sstream>
#include "../Circuit/Circuit.hpp"
#include "../Errors/ErrorFile.hpp"

class Parsing {
    public:
        Parsing();
        ~Parsing();
        void startParsing(std::string file, Circuit &circuit, bool &hasComponents);
        void openFile(std::string filename, Circuit &circuit, bool &hasComponents);
        void addComponent(std::string component, Circuit &circuit);
        void addLinks(std::string component, Circuit &circuit);
    protected:
    private:
};

#endif /* !PARSING_HPP_ */
