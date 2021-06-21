/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** TacticalMarine
*/

#ifndef TACTICALMARINE_HPP_
    #define TACTICALMARINE_HPP_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include <list>
    #include "ISpaceMarine.hpp"

    class TacticalMarine: public ISpaceMarine {
        public:
            TacticalMarine();
            TacticalMarine(TacticalMarine const &tact);
            virtual ~TacticalMarine();
            virtual ISpaceMarine* clone() const;
            virtual void battleCry() const;
            virtual void rangedAttack() const;
            virtual void meleeAttack() const;
        protected:
        private:
    };

#endif /* !TACTICALMARINE_HPP_ */
