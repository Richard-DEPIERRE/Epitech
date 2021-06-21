/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-richard.habimana
** File description:
** Ratatouille
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_

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

class Ratatouille {
    public:
        Ratatouille();
        Ratatouille(Ratatouille const &other); ~Ratatouille();
        Ratatouille &operator=(const Ratatouille &rhs);
        Ratatouille &addVegetable(unsigned char); Ratatouille &addCondiment(unsigned int);
        Ratatouille &addSpice(double);
        Ratatouille &addSauce(const std::string &);
        std::string kooc();

    protected:
    private:
        std::stringstream _ingredients;
};

#endif /* !RATATOUILLE_HPP_ */
