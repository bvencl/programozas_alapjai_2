
#include "modules.h"

int main(int argc, char const *argv[])
{

    Centipede c;
    c.print();
    Centipede c2;
    Centipede::setLegCount(11212);
    Centipede c3;
    c.print();
    c3.print();

    return 0;
}
