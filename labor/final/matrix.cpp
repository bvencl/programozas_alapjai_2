#include <iostream>
#include <functional>

template <class Derived>
class MatrixBase
{
public:
	static unsigned const ROWS = Derived::ROWS;
	static unsigned const COLS = Derived::COLS;

	Derived const &derived() const { return static_cast<Derived const &>(*this); }
	Derived &derived() { return static_cast<Derived &>(*this); }

	unsigned rows() const { return derived().rows(); }
	unsigned cols() const { return derived().cols(); }
	double operator()(unsigned row, unsigned col) const { return derived()(row, col); }

	void print(std::ostream &os = std::cout) const
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
	static unsigned const ROWS = Rows;
	static unsigned const COLS = Cols;

	unsigned rows() const { return ROWS; }
	unsigned cols() const { return COLS; }
	double operator()(unsigned row, unsigned col) const { return elements[row][col]; }

private:
	double elements[Rows][Cols];
};

template <unsigned Rows>
class UnitMatrix : public MatrixBase<UnitMatrix<Rows>>
{
public:
	static unsigned const ROWS = Rows;
	static unsigned const COLS = Rows;

	unsigned rows() const { return ROWS; }
	unsigned cols() const { return COLS; }
	double operator()(unsigned row, unsigned col) const { return row == col ? 1.0 : 0.0; }
};

template <class LhsDerived, class RhsDerived, class BinOp>
class ElemwiseBinaryOp : public MatrixBase<ElemwiseBinaryOp<LhsDerived, RhsDerived, BinOp>>
{
	static_assert(LhsDerived::ROWS == RhsDerived::ROWS && LhsDerived::COLS == RhsDerived::COLS, "Elementwise binary operation on matrices of different size");

public:
	static unsigned const ROWS = LhsDerived::ROWS;
	static unsigned const COLS = LhsDerived::COLS;

	ElemwiseBinaryOp(LhsDerived const &lhs, RhsDerived const &rhs, BinOp op)
		: lhs(lhs), rhs(rhs), op(op)
	{
	}

	unsigned rows() const { return ROWS; }
	unsigned cols() const { return COLS; }
	double operator()(unsigned row, unsigned col) const { return op(lhs(row, col), rhs(row, col)); }

private:
	LhsDerived const &lhs;
	RhsDerived const &rhs;
	BinOp op; // functors are conventionally stored and passed by value
};

template <class LhsDerived, class RhsDerived>
ElemwiseBinaryOp<LhsDerived, RhsDerived, std::plus<double>>
operator+(MatrixBase<LhsDerived> const &lhs, MatrixBase<RhsDerived> const &rhs)
{
	return ElemwiseBinaryOp<LhsDerived, RhsDerived, std::plus<double>>(lhs.derived(), rhs.derived(), std::plus<double>());
}

template <class LhsDerived, class RhsDerived>
ElemwiseBinaryOp<LhsDerived, RhsDerived, std::minus<double>>
operator-(MatrixBase<LhsDerived> const &lhs, MatrixBase<RhsDerived> const &rhs)
{
	return ElemwiseBinaryOp<LhsDerived, RhsDerived, std::minus<double>>(lhs.derived(), rhs.derived(), std::minus<double>());
}

int main()
{
	UnitMatrix<3> u;
	Matrix<3, 3> m1, m2;
	(u + m1 - m2).print();

#if 0
	// HW: transposition with lazy evaluation
	Matrix<4,5> m3, m4;
	(m3 - m4).transposed().print();
#endif
	
	return 0;
}