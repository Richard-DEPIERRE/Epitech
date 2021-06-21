/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** BF_Translator
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_

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

class BF_Translator {
    public:
        BF_Translator();
        ~BF_Translator();
        int translate(const std::string &in, const std::string &out);

    protected:
    private:
        std::unordered_map<char, std::string> _mapping;
};

#endif /* !BF_TRANSLATOR_HPP_ */
