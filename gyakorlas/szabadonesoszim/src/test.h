#pragma once

class Test
{
private:
    double acceleration;
    double startHeight;

public:
    Test(double startHeight, double acceleration);

    Test(double startHeight) : acceleration(9.81){};


    double calculate(double time);
    void getHeight() const;
    void setHeight(double height);
    void getSpeed() const;
    void getAcceleration() const;
    void setAcceleration(double acceleration);
};