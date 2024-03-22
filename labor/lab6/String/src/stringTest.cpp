#include <iostream>
#include "string.h"

using HomeMadeString::String;


int main()
{

	// Tesztelj�k a param�ter n�lk�li konstruktort
	String s1;
	// Tesztelj�k a r�gi t�pus� sztringet v�r� konstruktort
	String s2 = "Hello, hello!";
	std::cout << "Szia Hello " << 23 << '\t' << 4.6 << std::endl;
	// Ki�ratjuk az eredm�nyeket:
	std::cout << "s1";
	s1.print(std::cout);
	std::cout << std::endl;

	std::cout << "s2\t\t";

	s2.print(std::cout);
	std::cout << std::endl << std::endl;

#if 0
	// Tesztelj�k a m�sol� f�ggv�nyt, ki�ratjuk
	String::copy(s1, s2);
	cout << "s1:=s2\t\t";
	s1.print(cout);
	cout << endl;
	cout << "s2\t\t";
	s2.print(cout);
	cout << endl;

	// Tesztelj�k az �sszehasonl�t� f�ggv�nyt
	if (String::compare(s1, s2))
		cout << "s1 and s2 are the same!" << endl;

	// Tesztelj�k a "minta" konstruktort
	String s3('-', 15);
	cout << "s3\t\t";
	s3.print(cout);
	cout << endl;

	// Tesztelj�k a concatenate f�ggv�nyt �s a m�sol� konstruktort
	String s4 = String::concatenate(s2, s3);
	cout << "s4:=s2+s3\t";
	s4.print(cout);
	cout << endl;

	// Tesztelj�k az at f�ggv�nyt
	cout << "s4.at(*)\t";
	for (int i = 0; i<s4.getLength(); i++)
		cout << s4.at(i);
	cout << endl;

	// C Stringet visszaad� f�ggv�ny tesztje
	cout << "s4 cstr\t\t";
	cout << s4.getCString() << endl;
#endif
	return 0;
}

