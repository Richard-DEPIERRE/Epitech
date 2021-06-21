/*
** EPITECH PROJECT, 2021
** Sorcerer
** File description:
** Sorcerer
*/

#ifndef SORCERER_H
    #define SORCERER_H

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include "Victim.hpp"
    #include "Peon.hpp"

    class Sorcerer {
        public:
            Sorcerer(std::string name, std::string title);
            ~Sorcerer();
            void polymorph(Victim const &victim) const;
            //get
            std::string getName() const{return (_name);};
            std::string getTitle() const{return (_title);};
            //set
            void setName(std::string const name){_name = name;};
            void setTitle(std::string const title){_title = title;};
        protected:
            std::string _name;
            std::string _title;
        private:
    };
    std::ostream &operator<<(std::ostream &os, const Sorcerer &new_droid);

#endif /* !SORCERER_H */
