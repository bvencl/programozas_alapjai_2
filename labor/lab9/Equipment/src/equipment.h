#pragma once
#include <iostream>
#include <ostream>

class Equipment
{

    int serial_number;

public:
    Equipment(int sn = 666) : serial_number(sn){};
    virtual ~Equipment(){};
    virtual void print(std::ostream &os) const
    {
        os << "Equipment, serial number: " << serial_number;
    }
};

std::ostream & operator<<(std::ostream &, const Equipment &);