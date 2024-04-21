#pragma once
#include <ostream>
#include "easterbunny.h"

class Egg{
private:
    unsigned mass;

public:
    Egg::Egg(unsigned mass = 0): mass(mass) {};
    bool operator==(const Egg &theOther) const
    {
        return mass == theOther.mass;
    }

    friend std::ostream& operator<<(std::ostream&, const EasterBunny&);
};