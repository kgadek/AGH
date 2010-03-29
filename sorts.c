#include "sorts.h"

void swap(int *a, int *b) {
    int x;
    x = *a; *a = *b; *b = x;
}

void combsort_kg(int *tab, int len) {
    int gap, sw, i;
    gap = len;
    sw = 1;
    while(sw || gap>1) {
	gap = gap*10/13;
	if(!gap)
	    gap = 1;
	sw = 0;
	for(i=0; i+gap<len; ++i) {
	    if(tab[i+gap]<tab[i]) {
		swap(tab+i+gap,tab+i);
		sw = 1;
	    }
	}
    }
}
