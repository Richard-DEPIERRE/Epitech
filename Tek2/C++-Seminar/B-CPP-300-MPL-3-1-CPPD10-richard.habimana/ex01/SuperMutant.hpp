/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** SuperMutant
*/

#ifndef SUPERMUTANT_HPP_
    #define SUPERMUTANT_HPP_

    #include "AEnemy.hpp"

    class SuperMutant: public AEnemy {
        public:
            SuperMutant();
            ~SuperMutant();
            void takeDamage(int);

        protected:
        private:
    };

#endif /* !SUPERMUTANT_HPP_ */