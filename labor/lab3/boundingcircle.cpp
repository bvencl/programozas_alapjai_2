#include "boundingcircle.h"

BoundingCircle::BoundingCircle(double a)
{
    r.setA(a);
    r.setB(a);
    c.setR(a/2);
}

double BoundingCircle::area() const
{
    return r.area() - c.area();
}