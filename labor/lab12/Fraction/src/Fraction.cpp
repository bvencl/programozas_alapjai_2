#include "Fraction.h"
#include <sstream>
#include <ostream>

// Konstruktor

Fraction::Fraction(int whole, int num, int denom)
    : wholePart(whole + (num / (denom == 0 ? throw FractionException("division by zero") : denom))),
      numerator(num % denom),
      denominator(denom)
{
    simplify(); // legnagyobb  kozos oszto bla bla..
}

// Konverzios konstruktor
Fraction::Fraction(double d)
    : wholePart(d),
      numerator((d - wholePart) / EPSILON),
      denominator(1. / EPSILON)

{
    simplify();
}

// Konverzios operatorok: double es string
Fraction::operator double() const
{
    return wholePart + (double)numerator / denominator;
}
// Operator+ fuggveny
Fraction Fraction::operator+(Fraction const &rhs) const
{
    return Fraction(wholePart + rhs.wholePart, denominator * rhs.numerator, denominator * rhs.numerator);
}

Fraction::operator std::string() const
{
    return std::to_string(wholePart) + ' ' + std::to_string(numerator) + '/' + std::to_string(denominator);

    // std::stringstream ss;
    // ss << wholePart << ' ' << numerator << '/' << denominator;
    // return ss; ????
}
