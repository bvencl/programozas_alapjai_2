#include "equipment.h"
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Equipment &E)
{
    E.print(os);
    return os;
}