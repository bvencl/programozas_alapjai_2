#include "circle.h"
#include <cstdio>

Circle::Circle() {}

Circle::Circle(double R)
{
    this->R = R;
}

void Circle::setR(double R)
{
    this->R = R;
}

double Circle::getR() const
{
    return R;
}

double Circle::area() const
{
    return R * R * 3.14;
}

double Circle::circumference() const
{
    return 2.0 * R * 3.14;
}

void Circle::print() const{
    printf("Circle: R=%lf", R);
}