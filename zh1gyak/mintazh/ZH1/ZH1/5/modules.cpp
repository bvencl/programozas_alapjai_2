#include "modules.h"

#include <iostream>

void Car::entersTrack()
{
    this->order = ordercnt;
    ordercnt++;
}

std::ostream &operator<<(std::ostream &os, Car const &car)
{
    os << "Car #" << car.getNumber() << " enetered the track as the " << car.getOrder() << ". car" << std::endl;
    return os;
}

bool Car::operator<(const Car &rs) const
{
    return order < rs.order;
}

bool Car::operator>(const Car &rs) const
{
    return order > rs.order;
}

void swap(Car **c1, Car **c2)
{
    Car *tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void Car::orderCars(Car **cars, unsigned size)
{
    // buborek rendezes
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (*cars[j] > *cars[j + 1])
                swap(&cars[j], &cars[j + 1]);
}
int Car::ordercnt = 1;
