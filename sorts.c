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
    printf("Comb-Sorti11 by KG\n");
    gap = len;
    sw = 1;
    while(sw || gap>1) {
	gap = gap*10/13;
	if(!gap)
	    gap = 1;
	else if(gap==9 || gap==10) /* Comb-Sort 11 */
	    gap = 11;
	sw = 0;
	for(i=0; i+gap<len; ++i) {
	    if(tab[i+gap]<tab[i]) {
		swap(tab+i+gap,tab+i);
		sw = 1;
	    }
	}
    }
}

void inssort_mk(int *tab, int len) {
    int x,j,i;
    printf("Insertion-Sort by MK\n");
    for(i=1; i<len; ++i) {
	x = tab[i];
	j = i-1;
	while(j>=0 && tab[j]>x) {
	    tab[j+1] = tab[j];
	    --j;
	}
	tab[j+1] = x;
    }
}

void selsort_mk(int *tab, int len) {
    int min, i, j;
    printf("Selection-Sort by MK\n");
    for(i=0; i<len-1; ++i) {
	min = i;
	for(j=i+1; j<len; ++j)
	    if(tab[j]<tab[min])
		min = j;
	swap(tab+i, tab+min);
    }
}

void bubblesort_mk(int *tab, int len) {
    int i, j;
    printf("Bubble-Sort by MK\n");
    for(i=0; i<len; ++i) {
	for(j=0;j<len-1;++j)
	    if(tab[j+1]<tab[j])
		swap(tab+j+1, tab+j);
    }
}

void quicksort_h_mk(int *tab, int len) {
    printf("Quick-Sort by MK\n");
    quicksort_h_mk_int(tab,0,len-1);
}

void quicksort_h_mk_int(int *tab, int l, int p) {
    int i, j, x;
    i = l;
    j = p;
    x = tab[(i+j)/2];
    while(i<j) {
	while(tab[i]<x) ++i;
	while(x<tab[j]) --j;
	if(i<=j) {
	   swap(tab+i, tab+j);
	   ++i;
	   --j;
	}
    }
    if(j>l)
	quicksort_h_mk_int(tab,l,j);
    if(i<p)
	quicksort_h_mk_int(tab,i,p);
}

void shlsort_mk(int *tab, int len) {
    int gaps[] = {1,3,7,15,31,63,127,255,511,1023,2047,4095,8191};
    int i, j, gap, x, k;
    printf("Shell-Sort by MK\n");
    for(i=0; i<13; ++i) {
	gap = gaps[i];
	for(j=gap; j<len; ++j) {
	    x = tab[j];
	    k = j-gap;
	    while(k>=0 && x<tab[k]) {
		tab[k+gap] = tab[k];
		k -= gap;
	    }
	    tab[k+gap] = x;
	}
    }
}

