/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ErrorFile
*/

#include "ErrorFile.hpp"

ErrorFile::ErrorFile(std::ostream &stream, const std::string &message) throw(): Error(stream, message)
{
}

ErrorFile::~ErrorFile(void) throw()
{
}

