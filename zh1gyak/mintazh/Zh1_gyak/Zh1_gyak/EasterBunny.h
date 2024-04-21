#pragma once
#include <iostream>
#include "Egg.h"

class EasterBunny
{

private:
    unsigned eggCount;
    Egg *eggs;

public:
    EasterBunny() : eggCount(0), eggs(nullptr){};
    ~EasterBunny();
    EasterBunny &operator=(const EasterBunny &);
    bool isElement(const Egg &) const;
    void insert(const Egg &);

    unsigned operator[](unsigned) const;
    EasterBunny &operator+(const EasterBunny &);
    bool operator==(const EasterBunny &) const;
    friend std::ostream &operator<<(std::ostream &os, const EasterBunny &);
};

std::ostream &operator<<(std::ostream &os, const EasterBunny &);