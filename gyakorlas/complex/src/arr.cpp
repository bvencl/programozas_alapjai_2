#include "arr.h"

void ComplexArray::insert(Complex z)
{
    Complex *tmp = new Complex[size + 1];

    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }
    tmp[size] = z;
    delete[] arr;
    arr = tmp;
    size++;
}

Complex ComplexArray::operator[](int i)
{
    if (i < size)
        return arr[i];
    else
    {
        Complex z(0, 0);
        return z;
    }
}

ComplexArray ComplexArray::operator&(ComplexArray &theOther)
{

    for (int i = 0; i < theOther.size; i++)
    {
        insert(theOther[i]);
    }
    theOther.~ComplexArray();

    return *this;
}

