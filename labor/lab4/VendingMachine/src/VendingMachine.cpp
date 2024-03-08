#include "VendingMachine.h"
#include <cstdio>

// alapértelmezett konstruktor
// kezdetben üres a gép
VendingMachine::VendingMachine()
{
	drinkNumber = 0;
	drinks = nullptr;
}

// TODO
// másoló konstruktor
VendingMachine::VendingMachine(const VendingMachine & other)
{
	using namespace std;

	drinkNumber = other.drinkNumber;
	drinks = new string[other.drinkNumber];
	for(int i = 0; i < drinkNumber; i++)
	{
		drinks[i] = other.drinks[i];
	}
}

int VendingMachine::getDrinkNumber() const
{
	return drinkNumber;
}

VendingMachine::~VendingMachine()
{
	// fel kell szabadítani az italoknak lefoglalt memóriaterületet
	delete[] drinks;
}

// elsõ ital kivétele
// visszatér a nevével
std::string VendingMachine::removeOne()
{
	// ellenõrzés, hogy van-e még üdítõ az automatában
	if (drinkNumber <= 0)
		throw "Empty";

	// visszatérési érték, elsõ elem
	std::string value = drinks[0];

	// kisebb méretû tömb lefoglalása
	std::string* tmp;
	tmp = new std::string[drinkNumber - 1];

	// elsõ utáni elemek átmásolása
	for (int i = 1; i < drinkNumber; i++)
		tmp[i-1] = drinks[i];

	// darabszám csökkentése
	drinkNumber = drinkNumber - 1;

	// régi tömb felszabadítása
	delete[] drinks;

	// új tömb beírása az osztályba
	drinks = tmp;

	// visszatérés
	return value;
}

// vásárlás
// egyszerre több italt is lehet vásárolni, alapértelmezetten 1
// ha többet vennénk, mint amennyi készleten van, hamissal tér vissza, egyébként igazzal
// sikeres vásárlás esetén csökkenteni kell a darabszámot, és törölni az elemeket
bool VendingMachine::buy(int num)
{
	if (num > drinkNumber)
		return false;
	for (int i = 0; i < num; i++)
	{
		printf("Vasarolt ital: %s\n", removeOne().c_str());
	}
	return true;

}

// TODO
// automata feltöltése
// meg kell adni az ital nevét, és hogy mennyit rakunk belõle a gépbe
bool VendingMachine::refill(std::string const & pName, int pQty)
{
	using namespace std;

	// csak pozitív értékkel mûködjön
	if(pQty < 0)
		throw "nem jo szam .refill";
	//nagyobb tömb lefoglalása
	string * tmp = new string[drinkNumber + pQty];
	// meglévõ elemek átmásolása
	for(int i = 0; i < drinkNumber; i++)
	{
		tmp[i + pQty] = drinks[i];
	}
	// új elemek betöltése
	for(int i = 0; i < pQty; i++)
	{
		tmp[i] = pName;
	}
	// darabszám felülírása
	drinkNumber += pQty;
	// régi tömb törlése
	delete[] drinks;
	// új tömb átírása
	drinks = tmp;

	return true;
}

// készlet kiírása
void VendingMachine::print() const
{
	printf("Keszlet: %d\n", drinkNumber);
	for (int i = 0; i < drinkNumber; i++)
		printf("%s\n", drinks[i].c_str());
	printf("---Lista vege---\n\n");
}
