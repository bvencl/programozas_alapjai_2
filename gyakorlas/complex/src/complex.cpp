#include "complex.h"
#include <cmath>
#include <ostream>
#include <iostream>

void Complex::setRe(double Re)
{
    this->Re = Re;
}

void Complex::setIm(double Im)
{
    this->Im = Im;
}

double Complex::getRe() const
{
    return Re;
}

double Complex::getIm() const
{
    return Im;
}

double Complex::getLen() const
{
    return std::sqrt(Re*Re + Im*Im);
}

double Complex::getArg() const
{
    return std::tan(Im/Re);
}

void Complex::conjugate()
{
    Im = -Im;
}

Complex Complex::operator+(const Complex &rhs) const
{
    Complex res(Re + rhs.Re, Im + rhs.Im);
    return res;
}

std::ostream & operator<<(std::ostream & os, const Complex & C)
{
    os << C.Re << " + " << C.Im << "i";
    return os;
}

std::istream & operator>>(std::istream & is, Complex& C)
{
    double re, im;
    is >> re;
    char c;
    is >> c; // +
    if(c!= '+')
        is.clear(std::ios::failbit);
    is >> im;
    is >> c;
    if(c!= 'i')
        is.clear(std::ios::failbit);

    if(is.good())
        {
            C = Complex(re, im);
        }
    return is;
}

Complex Complex::operator=(const Complex& rhs)
{
    Re = rhs.Re;
    Im = rhs.Im;
}