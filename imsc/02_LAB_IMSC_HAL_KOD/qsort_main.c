#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "debugmalloc.h"

#define ARRAY_MAX 5

// Az összehasonlító függvény:
// a tömb két elemét hasonlítja össze.
// Ezt nekünk kell megírnunk, hiszen bármilyen típusú
// tömböt átadhatunk volna a qsortnak, és
// ő nem tud a típusról.
// Miért void pointerek a paraméterei?
// Mert így könnyebb átkasztolni a paramétereket

int compare(const void *a, const void *b)
{
	// 1. FELADAT - ide kell egy break point (töréspont)
	double *da = (double *)a, *db = (double *)b;

	// Visszatérés: <0, ha a a<b; 0, ha a=b;	>0, ha a>b.
	if (*da < *db)
		return -1;
	else if (*da == *db)
		return 0;
	else
		return 1;
	// Válaszok:
	// igen, úgy működik ahogyan vártuk
	// Mert így több különböző szempont szerint rendezhetjük sorba a tömbök elemeit
	//"visszatérési érték" "(*fgvnév)("asd" pram1, "asd" param2...)",
	// Mert így bármilyen típussal tud dolgozni az összehasonlító
}

// 5. FELADAT: qsort paraméterlistájával megegyező függvény, amely rendező algoritmust valósít meg

int is_Sorted(void *base, size_t nmemb, int (*compar)(const void *, const void *))
{
	for (int i = 0; i < (int)nmemb - 1; i++)
	{
		double a = ((double *)base)[i];
		double *ap = &a;

		double b = ((double *)base)[i + 1];
		double *bp = &b;
		if (compare((const void *)ap, (const void *)bp) == 1)
			return 0;
	}
	return 1;
}

void swap(void *a, void *b)
{
	double t = *((double *)a);
	*(double *)a = *((double *)b);
	*((double *)b) = t;
}

void shuffle(void *base, int n)
{
	for (int i = 0; i < n; i++)
	{ 
		int N = (rand() % (n-1)) + 1;
		void *aptr = &(((double *)base)[i]);
		void *bptr = &(((double *)base)[N]);
		swap(aptr, bptr);
	}
}

void first_Max(void* base, size_t nmemb, int (*compar)(const void *, const void *))
{

for (int i = 1; i < (int)nmemb; i++)
{
		double a = ((double *)base)[0];
		double *ap = &a;

		double b = ((double *)base)[i];
		double *bp = &b;


	if(compar(ap, bp) == -1)
	{
		swap(ap, bp);
	}
}

}

void bogosort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	first_Max(base, nmemb, compar);
	while (is_Sorted(base, nmemb, compar) != 1)
	{
		shuffle(base, nmemb);
	}
}

int main()
{
	// 2. FELADAT: tömbméret bekérés a felhasználótól. Használj dinamikus memóriakezelést!

	int n;
	printf("Number of elemts in the array: "),
		scanf_s("%d", &n, sizeof(int));

	double *d = (double *)malloc(n * sizeof(double));

	// 4. FELADAT: biztonságos szövegbevitel. Tipp: scanf_s
	// miért kell scanf_s: ha olyan területre írunk, amit nem foglaltunk le (akár csak kis részben is) => segmentation fault hiba
	// hacker/óvatlan felhasználó leállíthatja a programunk: buffer overflow attack
	// Warning kikapcsolás: C/C++ -> Preprocessor -> Preprocessor definitions: _CRT_SECURE_NO_WARNINGS

	printf("Let's fill the array!\n");

	int i;
	for (i = 0; i < n; i++)
	{
		printf("Enter a number:");
		// 3. FELADAT: scanf háromféleképpen
		scanf_s("%lf", &d[i], sizeof(d[i]));
		// scanf("%lf", &d[i]);
		// fscanf(stdin, "%lf", &d[i]);

		// azért pointert vár a scanf függvény, mert így tudja módosítani a változó értékét referencia funkció nélkül
	}

	bogosort(d, n, sizeof(double), compare);

	for (i = 0; i < n; i++)
	{
		printf("%lf ", d[i]);
	}

	// 2. FELADAT: a korábban lefoglalt dinamikus területet ne felejtsd el felszabadítani!

	free(d);

	return 0;
}