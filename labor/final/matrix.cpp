#include <iostream>
#include <ostream>

template <class Derived>
class MatrixBase
{

public:
    unsigned rows() const
    {
        return static_cast<Derived const &>(*this).rows();
    }
    unsigned cols() const
    {
        return static_cast<Derived const &>(*this).cols();
    }

    double operator()(unsigned row, unsigned col)
    {
        return static_cast<Derived const &>(*this)(row, col);
    }

    void print(std::ostream &os)
    {
        for (unsigned row = 0; row < rows(); row++)
        {
            for (unsigned col = 0; col < cols(); col++)

                os << (*this)(row, col) << ' ';
            os << std::endl;
        }
    }
};

template <unsigned Rows, unsigned Cols>
class Matrix : public MatrixBase<Matrix<Rows, Cols>>
{
public:
    unsigned rows() const { return Rows; }
    unsigned cols() const { return Cols; }

private:
    double elements[Rows][Cols];

    double operator()(unsigned row, unsigned col)
    {
        return elements[row][col];
    }
};

int main()
{
    Matrix<4, 4> m;
    m.print(std::cout);
    return 0;
}
