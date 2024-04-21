

#include "Egg.h"

bool Egg::operator==(const Egg &other) const
{
    return other.weight == weight;
}