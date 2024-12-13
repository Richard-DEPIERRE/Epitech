/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-richard.habimana
** File description:
** MixerBase
*/

#ifndef MIXERBASE_HPP_
#define MIXERBASE_HPP_

#include "FruitBox.hpp"

class MixerBase {
    public:
        MixerBase();
        int mix(FruitBox &fruits) const;

    protected:
        bool _plugged;
        int (*_mixfunc)(FruitBox &fruits);
    private:
};

#endif /* !MIXERBASE_HPP_ */
