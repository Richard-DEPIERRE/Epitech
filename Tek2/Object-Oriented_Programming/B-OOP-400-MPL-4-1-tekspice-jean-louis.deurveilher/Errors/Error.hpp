/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <string>

class Error: public std::exception {
    public:
        Error(std::ostream &stream, const std::string &message) throw();
        virtual ~Error(void) throw();

        const char *what(void) const throw();

    protected:
        std::ostream &_stream;
        std::string _message;
    private:
};

#endif /* !ERROR_HPP_ */
