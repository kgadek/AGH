#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

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
		swap(&tab[i+gap], &tab[i]);
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
	swap(&tab[i], &tab[min]);
    }
}

void bubblesort_mk(int *tab, int len) {
    int i, j;
    printf("Bubble-Sort by MK\n");
    for(i=0; i<len; ++i) {
	for(j=0;j<len-1;++j)
	    if(tab[j+1]<tab[j])
		swap(&tab[j+1], &tab[j]);
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
	   swap(&tab[i], &tab[j]);
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
    int gaps[] = {1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071, 262143, 524287};
    int i, j, gap, x, k;
    printf("Shell-Sort by MK\n");
    for(i=18; i>=0; --i) {
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

void mergesort_mk(int *tab, int len) {
    printf("Merge-Sort by MK\n");
    mergesort_mk_int(tab,0,len-1);
}

void mergesort_mk_int(int *tab, int l, int p) {
    int s, i1, i2, i;
    int *b;
    b = malloc((unsigned int)(p-l+1)*sizeof *b);
    if(b==NULL) {
	fprintf(stderr,"Nie mozna zadeklarowac pamieci.\n");
	exit(1);
    }
    s = (l+p+1)/2;
    if(1<s-l)
	mergesort_mk_int(tab,l,s-1);
    if(0<p-s)
	mergesort_mk_int(tab,s,p);
    i1 = l;
    i2 = s;
    for(i=l; i<=p; ++i) {
	if( i1==s || (i2<=p && tab[i2]<tab[i1]) )
	    b[i-l] = tab[i2++];
	else
	    b[i-l] = tab[i1++];
    }
    for(i=l; i<=p; ++i)
	tab[i] = b[i-l];
    free(b);
}

void quicksort_h_kg(int *tab, int len) {
    printf("Quick-Sort(H)::iter by KG\n");
    quicksort_h_kg_int(tab,0,len-1);
}

void quicksort_h_kg_int(int *tab, int p, int q) {
    int i,j;
    Sinit();
    Spush(p); Spush(q);
    while(!Sempty()) {
	q = Sfront(); Spop();
	p = Sfront(); Spop();
	if(p<q) {
	    quicksort_h_kg_part(tab,p,q,&i,&j);
	    if(j-p>q-i) {
		Spush(p); Spush(j);
		Spush(i); Spush(q);
	    } else {
		Spush(i); Spush(q);
		Spush(p); Spush(j);
	    }
	}
    }
    Sclear();
}

void quicksort_h_kg_part(int *tab, int p, int q, int *i, int *j) {
    int x;
    x = tab[(p+q)/2];
    *i = p;
    *j = q;
    while((*i)<=(*j)) {
	while(tab[*i]<x) ++(*i);
	while(x<tab[*j]) --(*j);
	if((*i)<=(*j)) {
	    swap(&tab[*i], &tab[*j]);
	    ++(*i); --(*j);
	}
    }
}

struct stck* R;

void Sinit(void) {
    R = NULL;
}

void Spush(int x) {
    struct stck* t;
    t = malloc(sizeof *t);
    t->n = R;
    t->v = x;
    R = t;
}

void Spop(void) {
    struct stck* t;
    if(!R)
	return;
    t = R->n;
    free(R);
    R = t;
}

int Sfront(void) {
    if(R)
	return R->v;
    return 0;
}

int Sempty(void) {
    return R==NULL;
}

void Sclear(void) {
    struct stck *t;
    while(R) {
	t = R->n;
	free(R);
	R = t;
    }
}

