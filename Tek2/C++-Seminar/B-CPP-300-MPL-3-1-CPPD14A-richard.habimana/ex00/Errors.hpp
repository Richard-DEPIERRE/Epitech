
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <exception>

class NasaError: public std::exception
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown") noexcept;

        const char *what() const noexcept override {return _message.data();};
        std::string const &getComponent() const {return _component;};
    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError: public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown") noexcept;
};

class LifeCriticalError: public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown") noexcept;
};

class UserError: public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown") noexcept;
};

class CommunicationError: public NasaError
{
    public:
        CommunicationError(std::string const &message) noexcept;
};

#endif
