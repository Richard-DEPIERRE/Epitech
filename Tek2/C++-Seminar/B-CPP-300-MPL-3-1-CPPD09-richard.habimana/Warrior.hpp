/*
** EPITECH PROJECT, 2021
** warrior
** File description:
** Warrior
*/

#ifndef WARRIOR
    #define WARRIOR

    #include "Character.hpp"

    class Warrior : virtual public Character {
        public:
            Warrior();
            Warrior(const std::string &name, int level, const std::string &weapon = "hammer", const std::string &character = "Warrior", const std::string &race = "Dwarf", int strength = 12, int stamina = 12, int intelligence = 6, int spirit = 5, int agility = 7, int range = 0);
            ~Warrior();
            //get
            std::string &getWeapon();
            int CloseAttack();
            int RangeAttack();
            void RestorePower();
        protected:
            std::string _weapon;
        private:
    };

#endif /* !WARRIOR */
