/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::ostream &stream, const std::string &message) throw() : _stream(stream), _message(message)
{
}

Error::~Error()
{
}

const char *Error::what(void) const throw()
{
    return _message.c_str();
}