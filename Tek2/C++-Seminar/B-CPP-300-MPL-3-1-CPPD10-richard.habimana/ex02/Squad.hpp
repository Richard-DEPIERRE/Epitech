/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Squad
*/

#ifndef SQUAD_HPP_
    #define SQUAD_HPP_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include <list>
    #include "ISquad.hpp"

    class Squad: public ISquad {
        public:
            Squad();
            Squad(const Squad &new_squad);
            virtual ~Squad();
            int getCount() const;
            ISpaceMarine* getUnit(int);
            int push(ISpaceMarine*);
        protected:
            std::list<ISpaceMarine*> _units;
        private:
    };

#endif /* !SQUAD_HPP_ */
