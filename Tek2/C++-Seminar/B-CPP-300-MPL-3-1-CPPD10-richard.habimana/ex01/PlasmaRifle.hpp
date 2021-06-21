/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** PlasmaRifle
*/

#ifndef PLASMARIFLE_HPP_
    #define PLASMARIFLE_HPP_
    
    #include "AWeapon.hpp"

    class PlasmaRifle: public AWeapon{
        public:
            PlasmaRifle();
            virtual ~PlasmaRifle();
            virtual void attack() const;

        protected:
        private:
    };

#endif /* !PLASMARIFLE_HPP_ */
