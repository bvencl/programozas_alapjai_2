#pragma once
#include "weapon.h"
#include <string>

class Railgun : private Weapon
{
private:
    unsigned energy;
    static unsigned maxEnergy;

public:
    Railgun(unsigned damage = 90, unsigned energy = 100) : Weapon(damage), energy(energy){};

    unsigned use();

    void recharge();

    unsigned getDamage() const;
    void setDamage(unsigned);

    std::string toString() const;

};