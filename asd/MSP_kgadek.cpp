#ifndef _MSP_KGADEK
#define _MSP_KGADEK

#define MAX(a,b) ((a)>(b)?(a):(b))
int MSP(int *tab, int n) {
	/* Znajdowanie maksymalnego spojnego podciagu (Maximum
	 [Contiguous] Subsequence Problem)
	 
	Zwraca najwieksza mozliwa do uzyskania wartosc.

	Czas dzialania: O(n)
	Pamiec: O(1)

	Parametry:
	 	t - tablica wejsciowa
	 	n - dlugosc tablicy 
	*/
	int c=0,		/* obecnie przetwarzana wartosc */
	    maksimum=0,		/* maksymalna uzyskana wartosc */
	    i=0;		/* licznik petli */
	for( ; i<n; ++i ) {
		if(c<=0)
			c = tab[i];
		else {
			maksimum = MAX(maksimum, c);
			c += tab[i];
		}
	}
	/*dbg*/printf("%d,%d --> %d\n",maksimum,c,MAX(maksimum,c));
	return MAX(maksimum,c);
}

#endif
