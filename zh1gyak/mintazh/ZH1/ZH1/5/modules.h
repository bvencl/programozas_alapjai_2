#pragma once
#include <iostream>

class Car
{
    unsigned const number;
    int order;
    static int ordercnt;

public:
    Car(const unsigned n) : number(n){};
    ~Car(){};

    unsigned getNumber() const { return number; };
    int getOrder() const { return order; };
    void entersTrack();
    bool operator<(Car const &) const;
    bool operator>(Car const &) const;

    void orderCars(Car **cars, unsigned size);
};
std::ostream &operator<<(std::ostream &, Car const &);