/*
** EPITECH PROJECT, 2021
** warrior
** File description:
** Paladin
*/

#ifndef PALADIN
    #define PALADIN

    #include "Priest.hpp"
    #include "Warrior.hpp"

    class Paladin : virtual public Warrior, virtual public Priest {
        public:
            Paladin();
            Paladin(const std::string &name, int level, const std::string &character = "Paladin", const std::string &race = "Human", int strength = 9, int stamina = 10, int intelligence = 10, int spirit = 10, int agility = 2, int range = 0);
            ~Paladin();
            //get
            int CloseAttack();
            int RangeAttack();
            void Heal();
            void RestorePower();
            int Intercept();
        protected:
        private:
    };

#endif /* !PALADIN */
