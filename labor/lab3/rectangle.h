#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double a;
    double b;

public:
    Rectangle();
    Rectangle(double a, double b = 0.0); // egy adatos konstruktor :: Rectangle r3(5); így valid


    void setA(double);
    void setB(double);


    double getA() const;
    double getB() const;


    double area() const;
    double perimeter() const;

    void print() const;

};

#endif