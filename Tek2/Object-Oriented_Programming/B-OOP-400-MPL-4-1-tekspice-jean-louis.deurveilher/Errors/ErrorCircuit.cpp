/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** Circuit description:
** ErrorCircuit
*/

#include "ErrorCircuit.hpp"

ErrorCircuit::ErrorCircuit(std::ostream &stream, const std::string &message) throw(): Error(stream, message)
{
}

ErrorCircuit::~ErrorCircuit(void) throw()
{
}

