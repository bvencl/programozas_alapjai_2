#include "weapon.h"
#include <iostream>

Weapon::Weapon(unsigned damage = 10) : damage(damage) {};

unsigned Weapon::use()
{
    return damage--;
}

std::string Weapon::toString() const
{
    return std::string("Fegyver vagyok, sebzesem: ") + std::to_string(damage) + ".";
}

unsigned Weapon::getDamage() const
{
    return damage;
}