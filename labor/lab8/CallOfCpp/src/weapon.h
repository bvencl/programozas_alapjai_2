#pragma once
#include <string>
class Weapon
{
private:
    unsigned damage;
public:
    Weapon(unsigned);
    unsigned use();
    unsigned getDamage() const;
    std::string toString() const;
};