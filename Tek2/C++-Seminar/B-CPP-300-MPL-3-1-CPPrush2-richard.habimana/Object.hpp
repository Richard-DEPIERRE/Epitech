/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** Object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>
    #include <list>
    #include <array>
    #include <fstream>
    #include <string>
    #include <iostream>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    #include <iomanip>

    class Object {
        public:
            Object(const std::string &title = "", const std::string &type = "");
            virtual ~Object();
            std::string getTitle() const;
            std::string getType() const;
            void setType(const std::string type);
        protected:
            const std::string _title;
            std::string _type;
        private:
    };
    std::ostream &operator<<(std::ostream &os, const Object &object);

#endif /* !OBJECT_HPP_ */
