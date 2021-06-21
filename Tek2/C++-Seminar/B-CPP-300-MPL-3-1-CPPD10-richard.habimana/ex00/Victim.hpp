/*
** EPITECH PROJECT, 2021
** Victim
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
    #define VICTIM_HPP_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class Victim {
        public:
            Victim(std::string name);
            virtual ~Victim();
            virtual void getPolymorph() const;
            //get
            virtual std::string getName() const{return (_name);};
            //set
            void setName(std::string const name){_name = name;};
        protected:
            std::string _name;
        private:
    };
    std::ostream &operator<<(std::ostream &os, const Victim &new_droid);

#endif /* !VICTIM_HPP_ */
