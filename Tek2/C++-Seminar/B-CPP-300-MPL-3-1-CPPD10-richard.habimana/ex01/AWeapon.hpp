/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
    #define AWEAPON_HPP_
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class AWeapon {
        public:
            AWeapon(const std::string &name, int apcost, int damage);
            virtual ~AWeapon();
            std::string const &getName() const{return (_name);};
            int getAPCost() const{return (_apcost);};
            int getDamage() const{return (_damage);};
            virtual void attack() const = 0;
        protected:
            std::string _name;
            int _apcost;
            int _damage;
        private:
    };

#endif /* !AWEAPON_HPP_ */
