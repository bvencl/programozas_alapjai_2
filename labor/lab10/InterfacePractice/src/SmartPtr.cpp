// Double-t tárooló Shared Pointer osztály megírása IMSC feladat

// probléma:

int main()
{
//     double *p = new double (3.14);
//     double *q = p;
//     delete p;
//     delete q;

SharedPtr p = SharedPtr(new (doubel(3.14)));
SharedPtr q = p; // itt történik a csoda, ugyan oda mutat, nincs másolás
SharedPtr z = q; 

delete p;   //nem törlődik
delete z;   // még nem törlödik
delete q;   // csak itt törlődik az object

}



/*
p két pointert tárol, egyet ami a 3.14-re mutat, egyet ami egy counterre mutat.
Az ugyan úgy értékadott pointerek counterje közös
Közös objektum közös cnt
copyconstruktornál a refcnt növekszik

nullpointer tényleg nullpointert tárol refcounter is nullptr
dereferálni lehessen, értéket vissza lehessen adni operator*
összehasonlítás ==
nem lehet rajta pointeraritmetikát végezni
cconst, const
értékadás constansra, nem constra,
destrukktor
nullptr-t is tudjon
*/