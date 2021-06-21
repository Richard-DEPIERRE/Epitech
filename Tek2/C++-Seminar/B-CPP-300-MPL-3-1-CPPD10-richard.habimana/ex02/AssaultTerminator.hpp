/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** AssaultTerminator
*/

#ifndef ASSAULTTERMINATOR_HPP_
    #define ASSAULTTERMINATOR_HPP_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include <list>
    #include "ISpaceMarine.hpp"

    class AssaultTerminator: public ISpaceMarine {
        public:
            AssaultTerminator();
            AssaultTerminator(AssaultTerminator const &term);
            virtual ~AssaultTerminator();
            virtual ISpaceMarine* clone() const;
            virtual void battleCry() const;
            virtual void rangedAttack() const;
            virtual void meleeAttack() const;
        protected:
        private:
    };

#endif /* !ASSAULTTERMINATOR_HPP_ */
