#include "test.h"

Test::Test(double startHeight, double acceleration)
{

    if (startHeight >= 0)
        this->startHeight = startHeight;
    else
        throw("nem jo te bolond");
    if (acceleration > 0)
        this->acceleration = acceleration;
    else
        throw("nem jo te bolond");
}

Test::Test(double startHeight) : acceleration(9.81)
{
    if (startHeight >= 0)
        this->startHeight = startHeight;
    else
        throw("nem jo te bolond");
}


double Test::calculate(double time)
{
    
}