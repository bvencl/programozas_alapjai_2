#include "VendingMachine.h"

int main()
{
	// kóla definiálása
	std::string Cola("Coca-Cola");

	// TODO másfajta ital(ok) definiálása
	std::string Capy("Capy");
	// automata létrehozása
	VendingMachine coldDrinkMachine;

	// feltöltés 5 Coca-colával
	coldDrinkMachine.refill(Cola, 5);

	// ellenõrzés
	coldDrinkMachine.print();

	// TODO vásárlás és másoló konstruktor kipróbálása, több automata létrehozása
	std::string drink = coldDrinkMachine.removeOne();
	coldDrinkMachine.print();

	VendingMachine hotDrinkMachine = coldDrinkMachine;
	hotDrinkMachine.print();
	coldDrinkMachine.refill(Capy, 2);
	coldDrinkMachine.print();
}