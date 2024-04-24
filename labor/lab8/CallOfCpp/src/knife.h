#pragma once
#include "weapon.h"

class Knife : private Weapon
{
    double sharpness;

public:

    Knife(unsigned damage = 30, double sharpness = 0.8 ) : Weapon(damage), sharpness(sharpness) {};

    void sharpen();
    double use();
    std::string toString() const;

    unsigned getDamage() const;
    void setDamage(unsigned);
};