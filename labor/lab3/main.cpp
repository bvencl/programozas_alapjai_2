#include "rectangle.h"
#include "circle.h"


int main()
{
    Rectangle r1;
    Rectangle r2(2, 7);
    Rectangle r3(5);

    r1.setA(5.3);
    r1.setB(7.8);

    r2.setA(r1.getB() * 3.0);

    double A1 = r1.area();
    double K1 = r1.perimeter();

    r1.print();
    r2.print();

    Circle c1;
    Circle c2(11);

    c1.setR(12);

    c2.print();

    double c1R = c1.getR();

    

    return 0;
}