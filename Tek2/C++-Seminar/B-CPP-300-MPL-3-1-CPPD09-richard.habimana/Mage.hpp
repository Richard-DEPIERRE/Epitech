/*
** EPITECH PROJECT, 2021
** warrior
** File description:
** Mage
*/

#ifndef MAGE
    #define MAGE

    #include "Character.hpp"

    class Mage : virtual public Character {
        public:
            Mage();
            Mage(const std::string &name, int level, const std::string &character = "Mage", const std::string &race = "Gnome", int strength = 6, int stamina = 6, int intelligence = 12, int spirit = 11, int agility = 7, int range = 0);
            ~Mage();
            //get
            int CloseAttack();
            int RangeAttack();
            void RestorePower();
        protected:
        private:
    };

#endif /* !MAGE */
