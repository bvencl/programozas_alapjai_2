#include <iostream>

class Dynamic
{
private:
    double omega;

public:
    Dynamic(double omega) : omega(omega){};
    double virtual getReactance() const = 0;
    double getOmega() const
    {
        return omega;
    }
};

class Coil : public Dynamic
{
private:
    double inductivity;

public:
    Coil(double omega, double inductivity) : Dynamic(omega), inductivity(inductivity){};
    double getReactance() const override
    {
        return getOmega() * inductivity;
    }
};

class Capacitor : public Dynamic
{
private:
    double capacity;

public:
    Capacitor(double omega, double capacity) : Dynamic(omega), capacity(capacity){};
    double getReactance() const override
    {
        return -1 / (getOmega() * capacity);
    }
};

int main()
{
    Dynamic *twoPoles[4];
    twoPoles[0] = new Capacitor(1, 2);
    twoPoles[1] = new Capacitor(2, 3);
    twoPoles[2] = new Coil(4, 5);
    twoPoles[3] = new Coil(6, 7);
    double sum = 0.0;
    for (int i = 0; i < 4; i++)
    {
        sum += twoPoles[i]->getReactance();
        delete twoPoles[i];
    }
    std::cout << sum << std::endl;
    return 0;
}