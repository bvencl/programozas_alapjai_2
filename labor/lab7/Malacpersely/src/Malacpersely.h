#pragma once
#include <iostream>

class Malacpersely
{
	int osszeg;

public:
	Malacpersely(int penz = 0) : osszeg(penz) {}
	void bedob(int penz);
	void atont(Malacpersely &masik);
	int ertek() const { return osszeg; }

	Malacpersely operator+(int p) const { return Malacpersely(osszeg + p); }
	Malacpersely &operator+=(int p)
	{
		osszeg += p;
		return *this;
	};
	Malacpersely operator+=(Malacpersely &p2)
	{
		this->atont(p2);
		return *this;
	}
	Malacpersely operator+(Malacpersely const &mp2) const
	{
		return Malacpersely(osszeg + mp2.osszeg);
	}
};

std::ostream &operator<<(std::ostream &os, Malacpersely const &mp);