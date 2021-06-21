/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** Circuit description:
** ErrorCircuit
*/

#ifndef ERRORCIRCUIT_HPP_
#define ERRORCIRCUIT_HPP_

#include "Error.hpp"

class ErrorCircuit: public Error {
    public:
        ErrorCircuit(std::ostream &stream, const std::string &message) throw();
        virtual ~ErrorCircuit(void) throw();

    protected:
    private:
};

#endif /* !ERRORCIRCUIT_HPP_ */
