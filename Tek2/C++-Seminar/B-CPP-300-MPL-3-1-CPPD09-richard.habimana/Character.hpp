/*
** EPITECH PROJECT, 2021
** character
** File description:
** character
*/

#ifndef CHARACTER_H
    #define CHARACTER_H

    #include <fstream>
        #include <string>
        #include <iostream>
        #include <cstring>
        #include <sstream>
        #include <algorithm>
        #include <iomanip>


    class Character {
        public:
            Character();
            Character(const std::string &name, int level, const std::string &character = "Character", const std::string &race = "Human", int strength = 5, int stamina = 5, int intelligence = 5, int spirit = 5, int agility = 5, int range = 0);
            ~Character();
            // GET
            std::string &getName() {return _name;};
            int getLevel() const {return _level;};
            std::string &getCharacter() {return _character;};
            std::string &getRace() {return _race;};
            int getHealth() const {return _health;};
            int getEnergy() const {return _energy;};
            int getStrength() const {return _strength;};
            int getStamina() const {return _stamina;};
            int getIntelligence() const {return _intelligence;};
            int getSpirit() const {return _spirit;};
            int getAgility() const {return _agility;};
            int getLvl() const{return _level;};
            int getPv() const{return _health;};
            int getPower() const{return _energy;};
            // SET
            void setLevel(const int level){ _level = level ;};
            void setCharacter(const std::string character){_character = character;};
            void setRace(const std::string race){_race = race;};
            void setHealth(const int health){ _health = health;};
            void setEnergy(const int energy){ _energy = energy;};
            void setStrength(const int strength){ _strength = strength;};
            void setStamina(const int stamina){ _stamina = stamina;};
            void setIntelligence(const int intelligence){ _intelligence = intelligence;};
            void setSpirit(const int spirit){ _spirit = spirit;};
            void setAgility(const int agility){ _agility = agility;};
            enum AttackRange {
                CLOSE,
                RANGE
            };
            //Technique Positive
            int CloseAttack();
            void Heal();
            int RangeAttack();
            void RestorePower();
            //Technique Negative
            void TakeDamage(const int damage);
        protected:
            std::string _name;
            int _level;
            std::string _character;
            std::string _race;
            int _health;
            int _energy;
            int _strength;
            int _stamina;
            int _intelligence;
            int _spirit;
            int _agility;
        private:
        public:
            AttackRange Range;
    };

#endif /* !CHARACTER_H */
