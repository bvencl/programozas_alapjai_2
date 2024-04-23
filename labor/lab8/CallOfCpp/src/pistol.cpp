#include "pistol.h"
#include <iostream>

void Pistol::reload()
{
    // nincs tobb tolteny a taron kivul
    if (totalBullets == 0)
    {
        std::cout << "No more bullets left outside of the clip" << std::endl;
        return;
    }

    // kifogyott a tar es nincs eleg tolteny a teljes ujratolteshes
    if (totalBullets < clipSize && bulletsInClip == 0)
    {
        bulletsInClip = totalBullets;
        totalBullets = 0;
        return;
    }

    // kifogyott a tar es van eleg tolteny az ujratolteshez / tobb is van
    if (totalBullets > clipSize && bulletsInClip == 0)
    {
        bulletsInClip = clipSize;
        totalBullets -= clipSize;
        return;
    }

    // van meg a tarban, de nincsen eleg tolteny a teljes ujratolteshez
    if (totalBullets < clipSize && bulletsInClip != 0 && totalBullets + bulletsInClip < clipSize)
    {
        bulletsInClip += totalBullets;
        totalBullets = 0;
        return;
    }

    // van meg a tarban es van is eleg tolteny a teljes ujratolteshez
    if (bulletsInClip != 0 && totalBullets > (clipSize - bulletsInClip))
    {
        totalBullets -= (clipSize - bulletsInClip);
        bulletsInClip = clipSize;
        return;
    }

    std::cout << "valamit kihagytal ocsipok" << std::endl;
}

unsigned Pistol::use()
{
    if (bulletsInClip > 0)
    {
        bulletsInClip--;
        return getDamage();
    }

    return 0;
}

unsigned Pistol::getDamage() const
{
    return Weapon::getDamage();
}

void Pistol::setDamage(unsigned dmg)
{
    Weapon::setDamage(dmg);
}


//Weapon<|Pistol; damage of a bullet=60; clipSize=12; bulletsInClip=12; totalBullets=35 

std::string Pistol::toString() const
{
    return std::string("Weapon<|Pistol; damage of a bullet=") + std::to_string(getDamage()) + "; clipSize=" + std::to_string(clipSize) + "; bulletsInClip=" + std::to_string(bulletsInClip) + "; totalBullets=" + std::to_string(totalBullets);
}

