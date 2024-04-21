#include "modules.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    Car c1(107);
    Car c2(999);
    Car c3(2000);
    c1.entersTrack();
    c3.entersTrack(); // a 2000-s azonosítójú autó másodikként lép pályára
    c2.entersTrack();
    std::cout << c3; //(*) Kiirjuk c3 adatait: "Car #2000 entered the track as the 2. car"

    if (c3 < c2) //(**) Ha c3 előbb került pályára, mint c2
    {
        std::cout << c3.getNumber() << " entered the track earlier.";
    }
    Car *cars[3];

    cars[0] = &c1;
    cars[1] = &c2;
    cars[2] = &c3;

    c1.orderCars(cars, 3);

    return 0;
}
