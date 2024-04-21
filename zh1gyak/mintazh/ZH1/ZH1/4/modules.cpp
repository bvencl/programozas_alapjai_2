#include "modules.h"
#include <iostream>
void Tractor::addSpray(Spray const &newspray)
{
    if (sprays == nullptr)
    {
        sprays = new Spray[numOfSprays++];
        sprays[0] = newspray;
        return;
    }
    Spray *tmp = new Spray[numOfSprays + 1];
    for (unsigned i = 0; i < numOfSprays; i++)
    {
        tmp[i] = sprays[i];
    }
    tmp[numOfSprays] = newspray;
    delete[] sprays;
    sprays = tmp;
    numOfSprays++;
    return;
}

Spray &Tractor::operator[](unsigned index) const { return sprays[index]; };

void Spray::vaporize()
{
    if (used == false)
        std::cout << "Permet:" << type << std::endl;
    else
        std::cout << "Mar felhasznaltak" << std::endl;

    used = true;
}
