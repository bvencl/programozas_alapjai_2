#pragma once
#include <ostream>
#include "egg.h"

class EasterBunny
{
private:
    Egg *inside;
    unsigned eggcnt;

public:
    EasterBunny() : inside(nullptr), eggcnt(0){};
    EasterBunny(const EasterBunny &other);
    ~EasterBunny();
    void insert(const Egg &);
    bool isElement(const Egg &) const;

    // operatorok
    friend std::ostream &operator<<(std::ostream &, const EasterBunny &);

    EasterBunny operator+(const EasterBunny &theOther);

    bool operator==(const EasterBunny &theOther);

    EasterBunny& operator=(const EasterBunny& theOther);
};