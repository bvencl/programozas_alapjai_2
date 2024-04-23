#pragma once
#include "weapon.h"
class Pistol : private Weapon
{
private:
    unsigned clipSize;
    unsigned bulletsInClip;
    unsigned totalBullets;

public:
    Pistol(unsigned damage = 60, unsigned clipSize = 12, unsigned bulletsInClip = 12, unsigned totalBullets = 36) : Weapon(damage), clipSize(clipSize), bulletsInClip(bulletsInClip), totalBullets(totalBullets){};

    void reload();

    unsigned use();

    std::string toString() const;
};