#ifndef _MSP_KGADEK
#define _MSP_KGADEK

#define MAX(a,b) ((a)>(b)?(a):(b))
int MSP(int *tab, int n) {
	/* Znajdowanie maksymalnego spojnego podciagu (Maximum
	 [Contiguous] Subsequence Problem)
	 
	Parametry:
	 	t - tablica wejsciowa
	 	n - dlugosc tablicy
	 
	Algorytm dziala dynamicznie; wymaga O(1) pamieci i O(n) czasu
	
	Zwraca najwieksza mozliwa do uzyskania wartosc.
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
