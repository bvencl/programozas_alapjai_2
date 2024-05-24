#include <cstring>

class String
{
public:
    String(char const *str = "")
    {
        len = std::strlen(str);
        pData = new char[len + 1];
        std::strcpy(pData, str);
    }

    ~String()
    {
        delete[] pData;
    }

    String(String const &rhs)
    {
        pData = nullptr;
        *this = rhs;
    }

    String(String &&rhs) // rvlaue reference, MOVE konstruktor
    {
        len = rhs.len;
        pData = rhs.pData;
        rhs.pData = nullptr;
    }

    String &operator=(String const &rhs)
    {
        if (this == &rhs)
            return *this;
        delete[] pData;
        len = rhs.len;
        pData = new char[len + 1];
        std::strcpy(pData, rhs.pData);
        return *this;
    }

    String &operator=(String &&rhs) // rvlaue reference
    {
        delete[] pData;
        len = rhs.len;
        pData = rhs.pData;
        rhs.pData = nullptr;
    }

private:
    char *pData;
    size_t len;
};

String f()
{
    return String("my favourite string");
}

int main()
{
    String c;
    c = f();
    return 0;
}
