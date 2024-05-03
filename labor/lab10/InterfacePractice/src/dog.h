#include "comparable.h"

class Dog : public Comparable
{
public:
    bool operator==(Comparable const &rhs) const
    {
        return false;
    }
    
    bool operator<(Comparable const &rhs) const
    {
        return true;
    }
};