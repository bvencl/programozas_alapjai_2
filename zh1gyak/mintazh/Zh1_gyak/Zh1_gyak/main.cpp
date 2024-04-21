#include "Egg.h"
#include <stdio.h>
#include <iostream>
#include "EasterBunny.h"
// Készitsünk egy húsvéti nyuszi osztályt, ami húsvéti tojásokat tárol
// dinamikus adatszerkezetben.
// Minden csokinyusziba különbözö súly tojsokat tesznek (nincs két egyforma súlyú tojás benne).
// A tojásoknak ne legyen getter függvénye.
// Terheljük túl a << , =, tés == operátorokat
// Két húsvéti nyuszi összeadása a listák összefüzését jelenti
// Két nyuszi akkor egyenló, hogy ha ugyanazokat a súly tojásokat és ugyanabban a sorrendben tartalmazza
// Mutassunk rá, hogy a nyuszik egyenlöségének elofeltétele, hogy pl.a tojások egyenlöségét is vizsgálni tudjuk.

int main(int argc, char const *argv[])
{
    Egg redEgg(9);
    Egg glitterEgg(27);
    Egg greenEgg(42);
    Egg orangeEgg(92);
    Egg blueEgg(2);

    EasterBunny bunny1;
    EasterBunny bunny2;
    bunny1.insert(redEgg);
    bunny1.insert(greenEgg);
    bunny1.insert(glitterEgg);
    bunny1.insert(blueEgg);
    bunny1.insert(orangeEgg);

    bunny2.insert(redEgg);
    bunny2.insert(glitterEgg);
    bunny2.insert(greenEgg);
    bunny2.insert(orangeEgg);

    std::cout << bunny1 << std::endl;
    std::cout << bunny2 << std::endl;

    EasterBunny bunny;
    bunny = bunny1 + bunny2; //+ operator
    std::cout << bunny << std::endl;

    if (bunny1 == bunny2)
        std::cout << "Twins" << std::endl;

    return 0;
}
