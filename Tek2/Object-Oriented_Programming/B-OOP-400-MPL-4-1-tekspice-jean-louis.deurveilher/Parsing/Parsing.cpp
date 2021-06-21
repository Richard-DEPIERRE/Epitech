/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Parsing
*/

#include "Parsing.hpp"

Parsing::Parsing()
{
}

Parsing::~Parsing()
{
}

void Parsing::startParsing(std::string file, Circuit &circuit, bool &hasComponents)
{
    std::ifstream fileName;
    if (file.empty()) {
        throw ErrorFile(std::cerr, "'" + file + "' : file is null.");
        return;
    }
    if (file.find(".") == std::string::npos) {
        throw ErrorFile(std::cerr, "'" + file + "' : file does not end in '.nts'.");
        return;
    }
    if (file.substr(file.find_last_of(".")) != ".nts") {
        throw ErrorFile(std::cerr, "'" + file + "' : file does not end in '.nts'.");
        return;
    }
    openFile(file, circuit, hasComponents);
}

std::string remove_extra_whitespaces(std::string input)
{
    std::string output;
    int outputIndex = 0;
    int inputIndex = 0;
    for (; input[inputIndex] != '\0' && (input[inputIndex] == ' ' || input[inputIndex] == '\t'); inputIndex++);
    for(; input[inputIndex] != '\0';  inputIndex++) {
        char c = input[inputIndex];
        if((input[inputIndex] == ' ' || input[inputIndex] == '\t') && (input[inputIndex + 1] == ' ' || input[inputIndex + 1] == '\t' || input[inputIndex + 1] == '\0'))
            for(; (input[inputIndex + 1] == ' ' || input[inputIndex + 1] == '\t') && input[inputIndex + 1] != '\0'; inputIndex++);
        output.push_back((c == '\t') ? ' ' : c);
        if (input[inputIndex + 1] == '\0')
            break;
        outputIndex++;
    }
    return output;
}

void Parsing::openFile(std::string filename, Circuit &circuit, bool &has_components)
{
    std::string content;
    std::ifstream file;
    bool is_chipsets = false;
    bool is_links = false;

    file.open(filename);
    try{
        if (!file)
            throw ErrorFile(std::cerr, "File is not open");
        if (file.peek() == std::ifstream::traits_type::eof())
            throw ErrorFile(std::cerr, "File is empty");
        for (int lineNbr = 1; std::getline(file, content); lineNbr++) {
            content = remove_extra_whitespaces(content);
            if (content.find("#") != std::string::npos)
                content = content.substr(0, content.find_first_of("#"));
            if (content.find(".chipsets") != std::string::npos && !is_chipsets && !is_links)
                is_chipsets = true;
            else if (is_chipsets && !is_links && content != "" && content.find(".links") == std::string::npos) {
                addComponent(content, circuit);
                has_components = true;
            } else if (content.find(".links") != std::string::npos && is_chipsets && !is_links) {
                is_chipsets = false;
                is_links = true;
            } else if (is_links && !is_chipsets && content != "")
                addLinks(content, circuit);
            else if (content[0] != '#' && content != "" && !(std::all_of(content.begin(),content.end(),isspace)))
                throw ErrorFile(std::cerr, "Line '" + content + "' at line [" + std::to_string(lineNbr) + "] is incorrect");
        }
        circuit.checkCircuit();
    } catch (Error &e) {
        throw ErrorFile(std::cerr, e.what());
    }
}

void Parsing::addComponent(std::string component, Circuit &circuit)
{
    std::regex word_regex("^[\t ]*(\\w+) [\t ]*(\\w+)\\((\\d+)\\)$");
    std::regex word_regex1("^[\t ]*(\\w+) [\t ]*(\\w+)\\((\\d+)\\)[\t ]*$");
    std::regex word_regex2("^[\t ]*(\\w+) [\t ]*(\\w+)$");
    std::regex word_regex3("^[\t ]*(\\w+) [\t ]*(\\w+)[\t ]*$");
    std::smatch pieces_match;
    std::vector<std::string> tokens;
    if (std::regex_match(component, pieces_match, word_regex) || std::regex_match(component, pieces_match, word_regex1) || std::regex_match(component, pieces_match, word_regex2) || std::regex_match(component, pieces_match, word_regex3)) {
        for (size_t i = 0; i < pieces_match.size(); ++i)
            tokens.push_back(pieces_match[i].str());
        circuit.addComponent(tokens[1], tokens[2]);
    } else {
        throw ErrorFile(std::cerr, "Line '" + component + "' at line is incorrect component");
    }
}

void Parsing::addLinks(std::string component, Circuit &circuit)
{
    std::regex word_regex("^[\t ]*(\\w+)[\t ]*:[\t ]*(\\d+)[\t ]*(\\w+)[\t ]*:[\t ]*(\\d+)$");
    std::regex word_regex2("^[\t ]*(\\w+)[\t ]*:[\t ]*(\\d+)[\t ]*(\\w+)[\t ]*:[\t ]*(\\d+)[\t ]*$");
    std::smatch pieces_match;
    std::vector<std::string> tokens;
    if (std::regex_match(component, pieces_match, word_regex) || std::regex_match(component, pieces_match, word_regex2)) {
        for (size_t i = 0; i < pieces_match.size(); ++i)
            tokens.push_back(pieces_match[i].str());
        circuit.addLink(tokens[1], std::stoi(tokens[2]) - 1, tokens[3], std::stoi(tokens[4]) - 1);
    } else {
        throw ErrorFile(std::cerr, "Line '" + component + "' at line is incorrect link");
    }
}