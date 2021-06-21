/*
** EPITECH PROJECT, 2021
** warrior
** File description:
** Priest
*/

#ifndef PRIEST
    #define PRIEST

    #include "Mage.hpp"

    class Priest : virtual public Mage {
        public:
            Priest();
            Priest(const std::string &name, int level, const std::string &character = "Priest", const std::string &race = "Orc", int strength = 4, int stamina = 4, int intelligence = 42, int spirit = 21, int agility = 2, int range = 0);
            ~Priest();
            //get
            int CloseAttack();
            void Heal();
        protected:
        private:
    };

#endif /* !PRIEST */
