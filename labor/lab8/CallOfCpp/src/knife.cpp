#include "knife.h"

Knife::Knife(unsigned damage = 30, double sharpness = 0.8) : Weapon(damage), sharpness(sharpness){};

void Knife::sharpen()
{
    sharpness *= 1.1;
}

unsigned Knife::use()
{
    unsigned dmg = Weapon::use();
    sharpness *= 0.95;
    return dmg * sharpness;
}

std::string Knife::toString()
{
    return std::string("Weapon<|Knife; damage can be casued when stabbing= ") + std::to_string(getDamage()) + "; sharpness= " + std::to_string(sharpness);
}