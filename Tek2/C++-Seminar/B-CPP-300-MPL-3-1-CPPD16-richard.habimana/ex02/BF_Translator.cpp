/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
    _mapping['>'] = "++ptr;\n";
    _mapping['<'] = "--ptr;\n";
    _mapping['+'] = "++*ptr;\n";
    _mapping['-'] = "--*ptr;\n";
    _mapping['.'] = "putchar(*ptr);\n";
    _mapping[','] = "*ptr=getchar();\n";
    _mapping['['] = "while (*ptr) {\n";
    _mapping[']'] = "}\n";
}

BF_Translator::~BF_Translator()
{

}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::ifstream inFile (in);
    std::ofstream outFile (out, std::ofstream::out);

    outFile << "#include <stdio.h>\n#include <stdlib.h>\nint main(){\nchar *ptr = calloc(60000, 1);\n";
    char c = inFile.get();
    while (inFile.good()) {
        if (_mapping[c] == "" && !isspace(c))
            return 1;
        outFile << _mapping[c];
        c = inFile.get();
    }
    outFile << "}";
    outFile.close();
    return 0;
}