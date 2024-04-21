#include "EasterBunny.h"
#include "Egg.h"

EasterBunny::~EasterBunny()
{
    delete[] eggs;
}

void EasterBunny::insert(const Egg &egg)
{
    if (!isElement(egg))
    {
        Egg *temp = new Egg[eggCount + 1];

        for (unsigned i = 0; i < eggCount; i++)
        {
            temp[i] = eggs[i];
        }
        temp[eggCount] = egg;
        delete[] eggs;
        eggs = temp;
        eggCount++;
    }
}

bool EasterBunny::isElement(const Egg &egg) const
{

    for (unsigned i = 0; i < eggCount; i++)
        if (eggs[i] == egg) // operator overload
            return true;

    return false;
}

unsigned EasterBunny::operator[](unsigned i) const
{
    return eggs[i].getWeight();
}

std::ostream &operator<<(std::ostream &os, const EasterBunny &bunny)
{
    os << "Egg:";
    for (unsigned i = 0; i < bunny.eggCount; i++)
    {
        os << bunny[i] << " ";
    }
    os << "." << std::endl;
    return os;
}

EasterBunny &EasterBunny::operator+(const EasterBunny &other)
{
    for (unsigned i = 0; i < other.eggCount; i++)
    {
        if (isElement(other.eggs[i]))
        {
        }
        else
            insert(other.eggs[i]);
    }
    return *this;
}

EasterBunny &EasterBunny::operator=(const EasterBunny &other)
{
    if (this == &other)
        return *this;

    if (other.eggCount == 0)
    {
        eggCount = 0;
        eggs = nullptr;
        return *this;
    }

    eggCount = other.eggCount;
    eggs = new Egg[eggCount];
    for (unsigned i = 0; i < eggCount; i++)
    {
        eggs[i] = other.eggs[i];
    }
    return *this;
}
bool EasterBunny::operator==(const EasterBunny &other) const
{
    if (eggCount == other.eggCount)
        return true;

    unsigned similar = 0;
    for (unsigned i = 0; i < other.eggCount; i++)
    {

        if (isElement(other.eggs[i]))
            similar++;
    }
    if (similar == eggCount && other.eggCount == similar)
        return true;
    return false;
}

// TODO: masolo konstruktor
/*{
    // Ezt egy masik fuggveny meghivasaval egyszeruen, 2 sorbol oldd meg!
    pData = nullptr;
    *this = theOther;
}*/