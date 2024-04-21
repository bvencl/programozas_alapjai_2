

#include "modules.h"

int main()
{
    Tractor zetor;
    Spray s1(1); // 1-es tipus, pl. csigaolo permet
    Spray s2(2); // 2-es tipus, pl. bekataszito permet
    zetor.addSpray(s1);
    zetor.addSpray(s2);
    zetor[0].vaporize(); //(*) “Permet: 1”
    // A túlcímzéssel nem kell foglalkoznunk.
    zetor[0].vaporize(); // “Mar felhasznaltak.”
    zetor[1].vaporize(); // ”Permet: 2”
}