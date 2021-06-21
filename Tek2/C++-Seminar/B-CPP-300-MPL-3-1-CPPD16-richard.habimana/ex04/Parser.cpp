/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(): _result(0)
{
}

Parser::~Parser()
{
}

void do_operations(std::stack<char> &opt, std::stack<int> &res)
{
    int top = res.top();
    res.pop();
    int bottom = res.top();
    res.pop();
    char top_operator = opt.top();
    opt.pop();
    res.push((top_operator == '+') ? bottom + top : (top_operator == '-') ? bottom - top : (top_operator == '*') ? bottom * top :(top_operator == '/') ? bottom / top : (top_operator == '%') ? bottom % top : 0);
}

bool is_good(char compare, char new_char)
{
    if ((new_char == '+' || new_char == '-') && (compare == '*' || compare == '/' || compare == '+' || compare == '-' || compare == '%'))
        return true;
    if ((new_char == '*' || new_char == '/' || new_char == '%') && (compare == '*' || compare == '/' || compare == '%'))
        return true;
    return false;

}

void Parser::feed(const std::string &beginning)
{
    std::stack<char> opt;
    std::stack<int> res;
    std::string str;
    if (_result < 0)
        str = "(" + beginning + std::to_string(_result) + ")";
    else
        str = "(" + beginning + "+" + std::to_string(_result) + ")";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            opt.push(str[i]);
        else if (isdigit(str[i])) {
            int val = 0;
            for (; i < str.size() && isdigit(str[i]); i++)
                val = (val * 10) + (str[i] - '0');
            res.push(val);
            i--;
        }
        else if (str[i] == ')') {
            while (!opt.empty() && opt.top() != '(')
                do_operations(opt, res);
            if (!opt.empty())
                opt.pop();
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
            while (!opt.empty() && is_good(opt.top(), str[i]))
                do_operations(opt, res);
            opt.push(str[i]);
        }
    }
    while (!opt.empty())
        do_operations(opt, res);
    _result = res.top();
}

int Parser::result() const
{
    return _result;
}

void Parser::reset()
{
    _result = 0;
}