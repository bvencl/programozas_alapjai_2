#include <stdio.h>
#include <iostream>
#include "egg.h"
#include "easterbunny.h"


//Készítsünk egy húsvéti nyuszi osztályt, ami húsvéti tojásokat tárol dinamikus adatszerkezetben.
//Minden csokinysuziba különböző súlyú tojásokat tesznek (nincs két egyforma súlyú tojás benne).
//A tojásoknak ne legyen getter függvénye.
//Terheljük túl a << , == és + operátorokat
//Két húsvéti nyuszi összeadása a listák összefűzését jelenti
//Két nyuszi akkor egyenlő, hogy ha ugyanazokat a súlyú tojásokat és ugyanabban a sorrendben tartalmazza
//Mutassunk rá, hogy a nyuszik egyenlőségének előfeltétele, hogy pl.a tojások egyenlőségét is vizsgálni tudjuk.



int main()
{
    Egg redEgg(9);
    Egg glitterEgg(27);
    Egg greenEgg(42);

    EasterBunny bunny1;
    EasterBunny bunny2;
    bunny1.insert(redEgg);
    bunny1.insert(greenEgg);
    bunny2.insert(glitterEgg);
    bunny2.insert(greenEgg);
    std::cout << bunny1 << std::endl;
    std::cout << bunny2 << std::endl;

    EasterBunny bunny;
    bunny = bunny1 + bunny2;

    std::cout << bunny << std::endl;

    if (bunny1 == bunny2)
        std::cout << "Twins." << std::endl;
    bunny1 = bunny2;
    if (bunny1 == bunny2)
        std::cout << "Twins." << std::endl;
    getchar();
    return 0;
}