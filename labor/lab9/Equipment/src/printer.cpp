#include <iostream>
#include "printer.h"

using namespace std;

//A serialNo �s a price param�tereket is el kell t�rolnunk valahol

void Printer::setCartridgePrice(unsigned cartridgePrice)
{
	this->cartridgePrice = cartridgePrice;
}

unsigned Printer::getCartridgePrice() const
{
	return cartridgePrice;
}

void Printer::print(std::ostream & os) const
{
	Equipment::print(os);
	os << " Printer, price: " << price;
}
