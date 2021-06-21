/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include "AEnemy.hpp"
    #include "AWeapon.hpp"

    class Character {
        public:
            Character(const std::string &name);
            ~Character();
            AWeapon *getWeapon() const;
            int getAP() const{return (_ap);};
            void recoverAP();
            void equip(AWeapon *weapon);
            void attack(AEnemy *enemy);
            std::string const &getName() const{return (_name);};
        protected:
            std::string _name;
            int _ap;
            AWeapon *_weapon;
        private:
    };
    std::ostream &operator<<(std::ostream &os, const Character &character);
#endif /* !CHARACTER_HPP_ */
