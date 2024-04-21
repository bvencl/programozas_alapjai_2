#pragma once
#include <ostream>

class Egg
{
private:
    unsigned mass;

public:
    Egg(unsigned mass);
    bool operator==(const Egg &theOther) const
    {
        return mass == theOther.mass;
    }

    friend std::ostream& operator<<(std::ostream&, const EasterBunny&);
};