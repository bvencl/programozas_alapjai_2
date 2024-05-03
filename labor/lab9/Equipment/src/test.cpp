#include <iostream>
// #include "display.h"
#include "printer.h"
#include "equipment.h"

int main()
{
	int maxEquipment = 4;

	// Equipment e(123456);
	// Printer p(87612873, 3.14);

	// std::cout << e << std::endl;
	// std::cout << p << std::endl;


	Equipment e1(1);
	Printer p1(2);
	Equipment e2(3);
	Printer p2(4);

	Equipment* equipments[5];

	equipments[0] = new Equipment(1);
	equipments[1] = new Printer(2, 1211112);
	equipments[2] = new Equipment(3);
	equipments[3] = new Equipment(4);
	equipments[4] = new Printer(5, 3.12);

	// Equipment* t2 = &p1;
	// Equipment* t3 = &e2;
	// Equipment* t4 = &p2;


	// Itt hozzunk létre 4 eszközt, az alábbi kimenetek meghatározzák a paramétereiket.
	// Heterogén kollekcióban akarjuk őket tárolni (közös tömbben)

	/************************Elvárt kimenet**************************\
	 Serial Number:1 Price:200 HUF
	 Serial Number:2 Price:12000 HUF Cartridge Price (Printer):12000
	 Serial Number:3 Price:2000 HUF Age (Display): 6
	 Serial Number:4 Price:312000 HUF Cartridge Price (Printer):51000
	\****************************************************************/
	
	for (int i = 0; i < maxEquipment; i++)
	{
		std::cout << *equipments[i] <<std::endl;
	}
	for(int i = 0; i < maxEquipment; i++)
	{
		delete equipments[i];
	}

	return 0;
}