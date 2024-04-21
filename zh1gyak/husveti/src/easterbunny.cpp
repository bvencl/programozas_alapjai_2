#include "EasterBunny.h"
#include "egg.h"
#include <ostream>

EasterBunny::EasterBunny() : inside(nullptr), eggcnt(0){};

EasterBunny::EasterBunny(const EasterBunny &other)
{
}

bool EasterBunny::isElement(const Egg &param) const
{
    for (unsigned i = 0; i < eggcnt; i++)
    {
        if (inside[i] == param)
            return true;
    }
    return false;
}

void EasterBunny::insert(const Egg &param)
{
    if (!isElement(param))
        return;

    eggcnt++;
    Egg *tmp = new Egg[eggcnt];
    for (int i = 0; i < eggcnt; i++)
    {
        tmp[i] = inside[i];
    }
    delete[] inside;

    tmp[eggcnt] = param;
    
    inside = tmp;
}

std::ostream& operator<<(std::ostream &os, const EasterBunny & bunny)
{
    os << "Egg "; 
    for(unsigned i = 0; i < bunny.eggcnt; i++)
        os << bunny.inside[i].mass;
    os << ".";
}

EasterBunny& EasterBunny::operator=(const EasterBunny& theOther)
    {
        if(this == &theOther)
            return *this;
        delete[] inside;
        if(theOther.eggcnt == 0)
        {
            eggcnt = 0;
            inside = nullptr;
            return *this;
        }

        eggcnt = theOther.eggcnt;
    inside = new Egg[eggcnt];
    for(unsigned i = 0; i < eggcnt; i++)
    {
        inside[i] = theOther.inside[i];
    }
    return *this;
    }

    
    EasterBunny EasterBunny::operator+(const EasterBunny &theOther)
    {
        EasterBunny newBunny;

        newBunny.eggcnt = eggcnt + theOther.eggcnt;

        if (newBunny.eggcnt == 0)
            return newBunny;

        newBunny.inside = new Egg[newBunny.eggcnt];
    unsigned idx = 0;
        for (unsigned i = 0; i < eggcnt; i++, idx++)
        {
            newBunny.inside[i] = inside[i];
        }

        for (unsigned i = 0; i < theOther.eggcnt; i++, idx++)
        {
            newBunny.inside[idx] = theOther.inside[i];
        }

        return newBunny;
    }

    bool EasterBunny::operator==(const EasterBunny &theOther)
    {
        if (eggcnt != theOther.eggcnt)
            return false;
        for (int i = 0; i < eggcnt; i++)
        {
            if (inside[i] == theOther.inside[i])
                continue;
            return false;
        }
        return true;
    }