/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/


#ifndef ADMIRAL_H_
    #define ADMIRAL_H_

    namespace Federation {
        namespace Starfleet {
            class Admiral;
        }
    }

    #include "Federation.hpp"
    #include "Borg.hpp"

    class Federation::Starfleet::Admiral {
        private:
            std::string _name;
        public:
            Admiral(std::string);
            ~Admiral();
            bool (Federation::Starfleet::Ship::*movePtr)(Destination dest);
            void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *ship);
            bool move(Federation::Starfleet::Ship *, Destination);
            void fire(Federation::Starfleet::Ship *, Borg::Ship *);
    };

#endif /* !BORG_H_ */