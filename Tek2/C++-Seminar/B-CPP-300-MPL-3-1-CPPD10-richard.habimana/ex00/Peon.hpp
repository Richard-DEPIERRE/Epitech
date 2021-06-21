/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Peon
*/

#ifndef PEON_HPP_
    #define PEON_HPP_

    #include "Victim.hpp"

    class Peon: public Victim{
        public:
            Peon(std::string name);
            ~Peon();
            void getPolymorph() const;
        protected:
        private:
    };

#endif /* !PEON_HPP_ */

