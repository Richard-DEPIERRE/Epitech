/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

class Parser {
    public:
        Parser();
        ~Parser();
        void feed(const std::string &);
        int result() const;
        void reset();

    protected:
    private:
        int _result;
};

#endif /* !PARSER_HPP_ */
