/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-richard.habimana
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
    #define AENEMY_HPP_
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class AEnemy {
        public:
            AEnemy(int hp, const std::string &type);
            virtual ~AEnemy();

            virtual void takeDamage(int damage);

            std::string const &getType() const{return (_type);};
            int getHP() const{return (_hp);};
            void setHP(int const hp){_hp = hp;};
        protected:
            int _hp;
            std::string _type;
        private:
    };

#endif /* !AENEMY_HPP_ */
