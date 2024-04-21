#pragma once
#include <iostream>
class Centipede
{
    static unsigned legCount;

public:
    Centipede(){};
    ~Centipede(){};
    static void setLegCount(unsigned);
    void print() const { printf("%d\n", legCount); };
};
