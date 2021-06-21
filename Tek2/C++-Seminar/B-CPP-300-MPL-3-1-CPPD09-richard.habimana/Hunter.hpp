/*
** EPITECH PROJECT, 2021
** warrior
** File description:
** Hunter
*/

#ifndef HUNTER
    #define HUNTER

    #include "Warrior.hpp"

    class Hunter : protected Warrior {
        public:
            Hunter();
            Hunter(const std::string &name, int level, const std::string &weapon = "sword", const std::string &character = "Hunter", const std::string &race = "Elf", int strength = 9, int stamina = 9, int intelligence = 5, int spirit = 6, int agility = 25, int range = 0);
            ~Hunter();
            int CloseAttack();
            int RangeAttack();
            void Heal();
            void RestorePower();
            void TakeDamage(const int damage);
            void setRange(int range);
            int getLvl() const{return _level;};
            int getPv() const{return _health;};
            int getPower() const{return _energy;};
            std::string &getName() {return _name;};
        protected:
        private:
    };

#endif /* !HUNTER */
