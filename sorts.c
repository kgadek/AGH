#include "sorts.h"
#include <stdio.h>

int check(int *tab, int len) {
    int i, l;
    if(!len)
	return 1;
    l=tab[0];
    for(i=1; i<len; ++i) {
	if(l>tab[i])
	    break;
	l=tab[i];
    }
    return i==len;
}

void swap(int *a, int *b) {
    int x;
    x = *a; *a = *b; *b = x;
}

void combsort_kg(int *tab, int len) {
    int gap, sw, i;
    printf("Comb-Sort by KG\n");
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

void nosort(int *tab, int len) {
    printf("Empty algorithm for internal testing\n");
}
