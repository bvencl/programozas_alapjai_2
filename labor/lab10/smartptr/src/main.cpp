#include "smartptr.h"
#include <iostream>

// A main-t gép írta a teszteléshez, remélem nem probléma
int main()
{
    double *fasz = new double(3123);
    SharedPtr a = fasz;
    SharedPtr b = fasz;
    SharedPtr p = SharedPtr(new double(42.42));
    SharedPtr q = SharedPtr(new double(123.123));

    SharedPtr x(p);
    SharedPtr y = q;

    x = q;
    SharedPtr z;
    z = p;

    std::cout << "Érték p által mutatott: " << *p << std::endl;
    std::cout << "Érték q által mutatott: " << *q << std::endl;
    std::cout << "Érték x (q után): " << *x << std::endl;
    std::cout << "Érték y (q): " << *y << std::endl;
    std::cout << "Érték z (p): " << *z << std::endl;

    SharedPtr nullPtr;
    std::cout << "NullPtr érték: " << *nullPtr << std::endl;

    if (x == q)
    {
        std::cout << "x == q helyesen működik" << std::endl;
    }

    return 0;
}