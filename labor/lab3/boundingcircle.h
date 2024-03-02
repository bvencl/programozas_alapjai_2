#ifndef BOUNDINGCIRCLE_H
#define BOUNDINGCIRCLE_H
#include "rectangle.h"
#include "circle.h"

class BoundingCircle
{
    Rectangle r;
    Circle c;

public:
    BoundingCircle(double a = 0.0);
    double area() const;
};

#endif