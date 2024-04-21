#pragma once

class Egg
{
private:
    unsigned weight;

public:
    Egg(unsigned weight = 0) : weight(weight) {}

    unsigned getWeight() const { return weight; };
    bool operator==(const Egg &) const;
};