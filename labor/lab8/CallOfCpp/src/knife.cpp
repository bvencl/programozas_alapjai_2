#include "knife.h"

// Knife::Knife(unsigned damage = 30, double sharpness = 0.8) : Weapon(damage), sharpness(sharpness){};

void Knife::sharpen()
{
    sharpness *= 1.1;
}

double Knife::use()
{
    double dmg = getDamage() * sharpness;
    sharpness *= 0.95;
    return dmg;
}

unsigned Knife::getDamage() const{
    return Weapon::getDamage();
}

void Knife::setDamage(unsigned dmg)
{
    Weapon::setDamage(dmg);
}

std::string Knife::toString() const
{
    return std::string("Weapon<|Knife; damage can be caused when stabbing=") + std::to_string(getDamage() * sharpness) + "; sharpness=" + std::to_string(sharpness);
}

