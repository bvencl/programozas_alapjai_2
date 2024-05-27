#include "vector.h"
#include <algorithm>
#include <cassert>

using std::cerr;

Vector::Vector(unsigned maxElementsNum) : elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr)
{
}

Vector::Vector(const Vector &theOther)
{
    pData = nullptr;
    *this = theOther;
}

Vector::~Vector()
{
    delete[] pData;
}

unsigned Vector::size() const
{
    return elementNum;
}

unsigned Vector::getMaxElementsNum() const
{
    return maxElementsNum;
}

void Vector::clear()
{
    delete[] pData;
    pData = NULL;
    elementNum = 0;
}

bool Vector::erase(unsigned position)
{
    if (position >= elementNum)
    {
        cerr << "Hibas index";
        return false;
    }

    if (elementNum == 1)
    {
        delete[] pData;
        pData = NULL;
        elementNum = 0;
        return true;
    }

    int *pTemp = new int[--elementNum];
    for (unsigned i = 0, j = 0; i < elementNum + 1; i++, j++)
    {
        if (i == position)
            j--;
        else
            pTemp[j] = pData[i];
    }
    delete[] pData;
    pData = pTemp;
    return true;
}

bool Vector::insert(unsigned position, int element)
{
    if (elementNum == maxElementsNum)
    {
        std::cerr << "Tobb elem nem fer el a tombben!" << std::endl;
        return false;
    }

    int *pTemp = nullptr;
    if (position < elementNum)
    {
        pTemp = new int[elementNum + 1];

        for (unsigned i = 0, j = 0; i < elementNum; i++, j++)
        {
            if (j == position)
            {
                pTemp[position] = element;
                i--;
            }
            else
                pTemp[j] = pData[i];
        }
        elementNum++;
    }
    else
    {
        pTemp = new int[position + 1];
        for (unsigned i = 0; i < position; i++)
        {
            if (i < elementNum)
                pTemp[i] = pData[i];
            else
                pTemp[i] = 0;
        }
        pTemp[position] = element;
        elementNum = position + 1;
    }
    delete[] pData;
    pData = pTemp;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Vector &v)
{
    int tmp;
    for (size_t i = 0; i < v.getMaxElementsNum() && !is.eof(); i++)
    {
        is >> tmp;
        v.insert(i, tmp);
    }
    return is;
}

Vector &Vector::operator=(const Vector &rhs)
{
    if (this == &rhs)
        return *this;
    delete[] pData;
    pData = new int[rhs.size()];
    for (int i = 0; i < rhs.size(); i++)
    {
        pData[i] = rhs.pData[i];
    }
    elementNum = rhs.elementNum;

    return *this;
}

int &Vector::operator[](unsigned idx)
{
    if (idx >= elementNum)
        throw "overindexing vector";
    return pData[idx];
}

const int &Vector::operator[](unsigned idx) const
{
    if (idx >= elementNum)
        throw "overindexing vector";
    return pData[idx];
}

void Vector::operator*=(unsigned mul)
{
    for (unsigned i = 0; i < elementNum; i++)
    {
        pData[i] *= mul;
    }
}

void Vector::operator+=(unsigned right)
{
    for (unsigned i = 0; i < elementNum; i++)
    {
        pData[i] += right;
    }
}

void Vector::sort(bool (*f)(const int &, const int &))
{
    std::sort(pData, pData + size(), f); // Sokkal hatékonyabb bárminél amit én írni tudtam volna :(
}

bool Sorters::ascend(const int &one, const int &another)
{
    if (one < another)
        return true;
    return false;
}

bool Sorters::descend(const int &one, const int &another)
{
    if (one < another)
        return false;
    return true;
}
