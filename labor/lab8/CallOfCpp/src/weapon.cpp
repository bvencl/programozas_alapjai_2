#include "weapon.h"
#include <iostream>

Weapon::Weapon(unsigned damage = 10) : damage(damage){};

unsigned Weapon::use()
{
    damage--;
    return damage;
}

std::string Weapon::toString() const
{
    return std::string("Weapon; damage can be caused=") + std::to_string(damage);
}

unsigned Weapon::getDamage() const
{
    return damage;
}

void Weapon::setDamage(unsigned dmg)
{
    damage = dmg;
}