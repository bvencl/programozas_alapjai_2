#pragma once
#include <iostream>

namespace Sorters
{
	bool ascend(const int &, const int &);
	bool descend(const int &, const int &);
}

class Vector
{
	unsigned elementNum;

	unsigned maxElementsNum;

	int *pData;

public:
	Vector(unsigned = 20);
	Vector(const Vector &);
	~Vector();

	unsigned size() const;

	unsigned getMaxElementsNum() const;

	void clear();

	bool erase(unsigned);

	int &at(unsigned);

	const int &at(unsigned) const;

	bool insert(unsigned, int);

	Vector &operator=(const Vector &);

	int &operator[](unsigned);
	const int &operator[](unsigned) const;

	void operator*=(unsigned);

	void operator+=(unsigned);

	void sort(bool (*)(const int &, const int &) = Sorters::ascend);
};

std::ostream &operator<<(std::ostream &, const Vector &);

std::istream &operator>>(std::istream &, Vector &);