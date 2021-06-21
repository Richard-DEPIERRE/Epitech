/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(bool stability)
{
    _stability = stability;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (_coreReactor);
}