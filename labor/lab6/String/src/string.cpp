#include "string.h"
#include <cstring>

namespace HomeMadeString
{
    String::String()
    {
        elementNum = 0;
        pData = nullptr;
    }

    String::String(char const *s)
    {
        elementNum = std::strlen(s);
        pData = new char[elementNum + 1];
        std::strcpy(pData, s);
    }

    String::~String()
    {
        delete[] pData;
    }

    void String::print(std::ostream &os) const
    {
        os << getCString();
    }

    char const *String::getCString() const
    {
        if (pData == nullptr)
            return "";
        return pData;
    }

    void String::copy(String &dst, String &src)
    {
        dst.elementNum = src.elementNum;
        delete[] dst.pData;
        dst.pData = new char[dst.elementNum + 1];
        std::strcpy(dst.pData, src.getCString());
    }

}