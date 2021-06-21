/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#ifndef BORGQUEEN_H_
    #define BORGQUEEN_H_

    namespace Borg {
        class BorgQueen;
    }

    #include "Federation.hpp"
    #include "Borg.hpp"

    class Borg::BorgQueen {
        public:
            BorgQueen();
            ~BorgQueen();

            bool move(Borg::Ship*, Destination);
            void fire(Borg::Ship*, Federation::Starfleet::Ship*);
            void destroy(Borg::Ship*, Federation::Ship*);

            bool (Borg::Ship::*movePtr)(Destination);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
            void (Borg::Ship::*destroyPtr)(Federation::Ship *);
    };

#endif /* !BORG_H_ */