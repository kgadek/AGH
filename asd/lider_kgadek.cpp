#ifndef _LIDER_CIAGU_KGADEK
#define _LIDER_CIAGU_KGADEK

int lider(int *tab, int n) {
		/* Zwraca pozycje lidera lub -1 gdy lider nie istnieje */
	int i,ile,j=-1;
	for(i=ile=0; i<n; ++i, ++ile) {
		if(!ile)
			j = i;
		else if(tab[i]!=tab[j])
			ile -= 2;	/* naprawde to ile-=1 
					 ale jeszcze jest ++ile */
	}
	for(i=ile=0; i<n; ++i) {
		if(tab[i]==tab[j])
			++ile;
	}
	if(ile*2 > n)
		return j;
	return -1;
}

#endif
