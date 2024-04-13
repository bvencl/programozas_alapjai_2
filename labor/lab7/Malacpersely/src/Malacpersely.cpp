#include "Malacpersely.h"

void Malacpersely::bedob(int penz) {
	osszeg += penz;
}

void Malacpersely::atont(Malacpersely& masik) {
	osszeg += masik.osszeg;
	masik.osszeg = 0;
}
std::ostream& operator<<(std::ostream &os, Malacpersely const &mp)
{
	os << mp.ertek() << "Ft.";
	return os;
}