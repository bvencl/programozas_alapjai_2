#pragma once
#include "weapon.h"

class Knife : private Weapon
{
    double sharpness;

public:

    Knife(unsigned damage = 30, double sharpness = 0.8 ) : Weapon(damage), sharpness(sharpness) {};

    void sharpen();
    unsigned use();
    std::string toString();
};