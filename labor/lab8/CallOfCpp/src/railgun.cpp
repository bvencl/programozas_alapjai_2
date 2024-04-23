#include "railgun.h"
#include "weapon.h"
#include <string>
unsigned Railgun::maxEnergy = 100;

unsigned Railgun::use()
{
    if (energy >= 10)
    {
        energy -= 10;
        return getDamage();
    }
    return 0;
}
void Railgun::recharge()
{

    // ugyis teletoltenenk, mert kevesebb, vagy pont nyolccal kevesebb energy van benne mint a max
    // telire is mukodik
    if (energy <= maxEnergy && energy + 8 >= maxEnergy)
    {
        energy = maxEnergy;
        return;
    }

    //
    if (energy < maxEnergy - 8)
    {
        energy += 8;
        return;
    }
}

unsigned Railgun::getDamage() const
{
    return Weapon::getDamage();
}

void Railgun::setDamage(unsigned dmg)
{
    Weapon::setDamage(dmg);
}

// Weapon<|Railgun; damage of shooting=90; energy=98
std::string Railgun::toString() const
{
    return std::string("Weapon<|Railgun; damage of shooting=") + std::to_string(getDamage()) + "; energy=" + std::to_string(energy);
}
