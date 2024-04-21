#pragma once
#include <ostream>
#include "egg.h"

class EasterBunny
{
private:
    Egg *inside;
    unsigned eggcnt;

public:
    EasterBunny();
    EasterBunny(const EasterBunny &other);
    ~EasterBunny();
    void insert(const Egg &param);
    bool isElement(const Egg &param) const;

    // operatorok
    friend std::ostream &operator<<(std::ostream &, const EasterBunny &);

    EasterBunny operator+(const EasterBunny &theOther);

    bool operator==(const EasterBunny &theOther);

    EasterBunny& operator=(const EasterBunny& theOther);
};