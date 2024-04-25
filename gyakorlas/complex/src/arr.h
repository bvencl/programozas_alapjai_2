#pragma once

#include "complex.h"

class ComplexArray
{
private:
    Complex *arr;
    int size;

public:
    ComplexArray() : arr(nullptr), size(0){};
    ~ComplexArray()
    {
        delete[] arr;
    }

    void insert(Complex z);
    
    Complex operator[](int);
    ComplexArray operator&(ComplexArray &);

};