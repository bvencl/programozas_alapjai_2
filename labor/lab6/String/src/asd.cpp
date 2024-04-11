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

    String::String(char c, unsigned times)
    {
        elementNum = times;
        pData = new char[times + 1];
        for (unsigned i = 0; i < times; i++)
        {
            pData[i] = c;
        }
        pData[times] = '\0';
    }

    String::String(String const & rhs)
    {
        pData = nullptr;
        copy(*this, rhs);
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

    void String::copy(String &dst, String const&src)
    {
        if (&src == &dst)
            return;
        dst.elementNum = src.elementNum;
        delete[] dst.pData;
        dst.pData = new char[dst.elementNum + 1];
        std::strcpy(dst.pData, src.getCString());
    }

    bool String::compare(String const &s1, String const &s2)
    {
        return std::strcmp(s1.getCString(), s2.getCString()) == 0;
    }

    String String::concatenate(String const &lhs, String const &rhs)
    {
        String res;
        res.elementNum = lhs.elementNum + rhs.elementNum;
        res.pData = new char[res.elementNum + 1];
        std::strcpy(res.pData, lhs.getCString());
        std::strcat(res.pData, rhs.getCString());
        return res;
    }

    char String::at(unsigned idx) const
    {
        if(idx >= elementNum)
            throw "String Overindexed";
        return pData[idx];
    }
}