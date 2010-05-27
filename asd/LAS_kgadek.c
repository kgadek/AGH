#ifndef _LAS_KGADEK
#define _LAS_KGADEK

#include <stdlib.h>

void LAS(int *t, int n, int **ff, int **ww) {
	/* Znajdowanie najdluzszego podciagu rosnacego (Longest Ascending
	   Sequence) w tablicy t[0 .. n-1].

	   Parametry:
	   	t - wskaznik do tablicy wartosci
		n - dlugosc tablicy
		ff - tu zwracany jest wskaznik na obliczona tablice fi
		ww - tu zwracany jest wskaznik na obliczona tablice w

	   Algorytm dziala dynamicznie; wymaga pamieci O(n) i czasu O(n^2).

	   Uwagi:
	   	* NIE SA obslugiwane bledy alokacji etc.
	   	* recznie trzeba czyscic pamiec z ff i ww po wykorzystaniu
	*/
	   
	int *fi, *w,		/* tablice wartosci i poprzednika */
	    i, j,		/* iteratory */
	    jm,			/* znalezione j: maksymalizuje fi[0 .. i] */
	    mf, mi;		/* wartosc i miejsce konca najdluzszego podciagu */

						/* A1. Alokacja i ustawienia poczatk. */
	fi = (int*)malloc((unsigned int)n*sizeof(int));		/* alokacja pamieci */
	w = (int*)malloc((unsigned int)n*sizeof(int));
	for(i=0;i<n;++i) {					/* czyszczenie tablic */
		fi[i] = 0;					/* maksymalna uzyskana dlugosc
								   LAS tablicy t[0 .. i] */
		w[i] = -1;					/* brak poprzednika */
	}
	fi[0] = 1;						/* podciag dlugosci 1 */
	mf = 1;							/* najw. fi jest dla i=0 */
	mi = 0;
	for(i=1; i<n; ++i) {
		for(j=0, jm=i; j<i; ++j) {	/* A2 znajdowanie najdluzszego podciagu
						   t[0 .. i-1] do ktorego mozna dolaczyc t[i] */
			if(t[j]<t[i] && fi[jm]<fi[j]) {		
				jm = j;				/* zmieniamy podciag na dluzszy */
				w[i] = j;			/* zapamietujemy poprzednik */
			}
			if(fi[i]>mf) {				/* jesli LAS t[0 .. i] najdluzszy z
								   dotychczas znalezionych */
				mf = fi[i];			/*  -> zapamietaj */
				mi = i;
			}
		}
	}
	*ff = fi;				/* A3. Zwracanie wartosci */
	*ww = w;
	return;
	
}

#endif
