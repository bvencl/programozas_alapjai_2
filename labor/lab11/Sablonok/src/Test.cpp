#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

template <class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
bool negative(T a) { return a < 0.0; }

// functor : function-objetcum
template <class T>
struct less_than
{
    T a;
    less_than(T const &a) : a(a) {}
    bool operator()(T const &x) { return x < a; }
};

template <class T, class P>
size_t count_if(T first, T last, P pred)
{
    size_t c = 0;

    while (first != last)
    {
        if (pred(*first))
            c++;
        ++first;
    }

    return c;
}

template <class Functor, class T>
class bound2nd
{
    Functor f;
    T v;

public:
    bound2nd(Functor f, T v) : f(f), v(v) {}
    bool operator()(T const &x) { return f(x, v); }
};

template <class Functor, class T>
bound2nd<Functor, T> bind2nd(Functor f, T const &v)
{
    return bound2nd<Functor, T>(f, v);
}

// template<class T, class P>
// struct less
// {
//     operator();
// }

int main()
{

    std::vector<double> vd;
    vd.push_back(5);
    vd.push_back(3.14);
    // size_t cc = std::count_if(vd.begin(), vd.end(), less_than<double>(20.0));

    int a[3] = {1, 2, 1};
    size_t ca = std::count_if(a, a + 3, std::bind(std::less<int>(), std::placeholders::_2, 2));

    double b[3] = {1.0, 2.1, 0.91};
    // size_t cb = count_if(b, b + 3, less_than<double>(2));

    std::cout << ca << std::endl;
    // std::cout << cb << std::endl;
    // std::cout << cc << std::endl;

    // maxTest();

    return 0;
}

#if 0

// 1.c Egészítsd ki a Vector2D osztályt a find_max_elem feladathoz
class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    double length() const
    {
        // Fixme!
        return 0;
    }
};

// 1.b feladat tesztelése - kommentezd ki és hívd meg, ha megvalósítottad a find_max_elem sablont. A lenti kódot ne írd át!
/*
void maxTest() {
    int intArray[] = { 1, 3, 5, 2, 4 };
    double doubleArray[] = { 1.5, 3.2, 2.7, 4.1 };
    int* emptyArray= nullptr;

    int* maxInt = find_max_elem(intArray, 5);
    double* maxDouble = find_max_elem(doubleArray, 4);

    if (maxInt)
        std::cout << "Maximum integer: " << *maxInt << std::endl;
    else
        std::cout << "Empty integer array." << std::endl;

    if (maxDouble)
        std::cout << "Maximum double: " << *maxDouble << std::endl;
    else
        std::cout << "Empty double array." << std::endl;

    maxInt = find_max_elem(emptyArray, 0);
    if (maxInt)
        std::cout << "Maximum integer: " << *maxInt << std::endl;
    else
        std::cout << "Empty integer array." << std::endl;

    ////////////////////////////////////
    1.c feladat - kommentezd ki, ha a Vector2D osztályt megvalósítottad.

    //Vector2D vectors[] = { Vector2D(1.0, 2.0), Vector2D(3.0, 4.0), Vector2D(0.5, 0.5) };
    //Vector2D* maxVector = find_max_elem(vectors, 3);

    //if (maxVector)
    //    std::cout << "Maximum vector length: " << maxVector->length() << std::endl;
    //else
    //    std::cout << "Empty vector array." << std::endl;


}

*/
#endif
