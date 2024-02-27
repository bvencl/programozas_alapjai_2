#include <iostream>
#include <stdio.h>

using namespace std;

class Point
{
    int x;
    int y;

public:    
    void setX(int param)
    {
        x = param;
    }

    void setY(int param)
    {
        y = param;
    }

    void draw()
    {
        printf("Point here: x %d, y %d\n");
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};

class Circle
{
    int x;
    int y;

public:
    void setX(int param)
    {
        x = param;
    }

    void setY(int param)
    {
        y = param;
    }

    void draw()
    {
        printf("Point here: x %d, y %d\n");
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};

int main()
{
    Point p1;
    p1.setX(100);
    p1.setY(200);

    Point p2;
    p2.setX(300);
    p2.setY(400);

    return 0;
}