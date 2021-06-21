/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14A-richard.habimana
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) noexcept: _message(message), _component(component)
{

}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) noexcept: NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) noexcept: NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) noexcept: NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) noexcept: NasaError(message, "CommunicationDevice")
{
}