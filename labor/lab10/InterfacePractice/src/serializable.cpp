#include "serializable.h"

std::ostream &operator<<(std::ostream &os, const Serializable &s)
{
    s.serialize(os); //kb print
    return os;
}

std::istream &operator>>(std::istream &is, Serializable &s)
{
    s.deserialize(is); //kb get
    return is;
}