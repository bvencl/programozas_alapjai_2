#pragma once
#include <iostream>
#include <string>

const double EPSILON = 1e-6;

class FractionException : public std::exception
{
private:
    std::string message;

public:
    FractionException(const std::string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class Fraction
{
private:
    // Tagvaltozok
    int wholePart;
    int numerator;
    int denominator;

    void simplify() { /*bla bla...*/ }

public:
    // Konstruktor
    explicit Fraction(int whole, int num, int denom);
    // Konverzios konstruktor
    explicit Fraction(double d);
    // Getterek
    int getWholePart() const { return wholePart; }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Konverzios operatorok: double es string
    operator double() const;
    operator std::string() const;
    // Operator+ fuggveny
    Fraction operator+(Fraction const &) const;

    // reciprok
};
