/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ErrorFile
*/

#ifndef ERRORFILE_HPP_
#define ERRORFILE_HPP_

#include "Error.hpp"

class ErrorFile: public Error {
    public:
        ErrorFile(std::ostream &stream, const std::string &message) throw();
        virtual ~ErrorFile(void) throw();

    protected:
    private:
};

#endif /* !ERRORFILE_HPP_ */
