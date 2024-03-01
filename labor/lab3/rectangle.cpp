#include "rectangle.h"
#include <cstdio>

Rectangle::Rectangle() {}

Rectangle::Rectangle(double a, double b)
{
    this->a = a;
    this->b = b;
}

void Rectangle::setA(double a)
{
    this->a = a;
}

void Rectangle::setB(double b)
{
    this->b = b;
}

double Rectangle::getA() const
{
    return a;
}

double Rectangle::getB() const
{
    return b;
}

double Rectangle::area() const
{
    return a * b;
}

double Rectangle::perimeter() const
{
    return 2.0 * (a + b);
}

void Rectangle::print() const{
    printf("Rectangle: a=%lf, b = %lf", a, b);
}