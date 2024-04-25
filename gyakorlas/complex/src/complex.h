#pragma once
#include <ostream>
#include <iostream>
class Complex
{
private:
    double Re;
    double Im;

public:

    Complex(double Re = 0, double Im = 0) : Re(Re), Im(Im) {};

    void setRe(double);
    void setIm(double);

    double getRe() const;
    double getIm() const;
    double getLen() const;
    double getArg() const;

    void conjugate();

    Complex operator+(const Complex &) const;
    Complex operator=(const Complex &);

    friend std::ostream & operator<<(std::ostream&, const Complex &);
};

