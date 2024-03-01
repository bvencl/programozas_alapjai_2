#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    double R;

public:
    Circle();
    Circle(double R);

    void setR(double);

    double getR() const;

    double area() const;
    double circumference() const;

    void print() const;
};

#endif