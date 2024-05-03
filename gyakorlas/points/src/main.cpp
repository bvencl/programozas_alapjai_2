
class Point
{
private:
public:
    double x;
    double y;

    Point(double x, double y) : x(x), y(y){};

    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point &other) const
    {
        if (x == other.x && y == other.y)
            return true;
        return false;
    }

    Point operator-()
    {
        return Point(-x, -y);
    }


};

