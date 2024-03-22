﻿#pragma once

#include <iostream>

namespace HomeMadeString
{
	class String
	{
		// A karakterek aktuális száma. A NULL terminátor nem számít bele, de ugyanúgy tároljuk.
		unsigned elementNum; // unsigned === unsigned int

		// A karaktereket tartalmazó memóriaterületre mutató pointer
		char *pData;

	public:
		// Összefűz két stringet, és visszatér vele
		static String concatenate(String const &, String const &);

		// Összehasonlít két stringet
		static bool compare(String const &, String const &);

		// A második stringet az első stringbe másolja
		static void copy(String &, String const &);

		// Argumentum nélküli konstruktor:
		String();

		// Másoló konstruktor
		String(String const &);
		// Egy NULL végű stringet váró konstruktor
		String(char const *);

		// Egy karaktert (c) és egy előjel nélküli egészet (times) váró konstruktor,
		// amely times darab c karakterrel inicializálja a stringet
		String(char c, unsigned times);
		// A destruktor
		~String();

		// Visszaadja a tárolt C stringet
		char const *getCString() const;

		// Visszatér a string hosszával
		size_t getLength() const
		{
			return elementNum;
		}

		// Kiírja a stringet a megadott kimeneti adatfolyamba (A 'cout' ostream típusú.
		// A .h állományban nem használunk using namespace-t, mert nem tudjuk, hova lesz
		// beépítve, és ott milyen hatása lesz. Ezért kiíjuk az std::-t. Ez a .cpp állományban
		// már nem kell, ott használhatjuk a using namespace std utasítást):
		void print(std::ostream &) const;

		// Visszaadja a megadott pozícióban lévo karaktert, egyébként nullát:
		char at(unsigned) const;
	};
}