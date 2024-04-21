

#include "modules.h"

void Centipede::setLegCount(unsigned legc)
{
    if (legc % 2 == 0)
        legCount = legc;
}

unsigned Centipede::legCount = 10;