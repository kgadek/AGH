#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

#define ALGCNT 2

int main(int argc, char *argv[]) {
    int n, i, *t, id;
    clock_t start,stop;
    void (*funcT[])(int *, int) = { combsort_kg, nosort };
    if(argc!=2) {
	fprintf(stderr,"Uzycie: %s ID\n\tID - id algorytmu\n",argv[0]);
	exit(1);
    } 
    id = atoi(argv[1]);
    if(id<0 || id>=ALGCNT) {
	fprintf(stderr,"ID musi byc z zakresu 0..%d\n",ALGCNT-1);
	exit(1);
    }
    scanf("%d",&n);
    t = (int*)malloc(n*sizeof *t);
    if(t==NULL) {
	fprintf(stderr,"Nie mozna zadeklarowac pamieci.\n");
	exit(1);
    }
    for(i=0; i<n; ++i)
	scanf("%d",t+i);
    start = clock();
    (*funcT[id])(t,n);
    stop = clock();
    printf("Exec time: %d [ticks]\n",(int)(stop-start));
    if(!check(t,n)) {
	fprintf(stderr,"Zle posortowana tablica!\n");
    }
    /*for(i=0; i<n; ++i)
	printf("%d ",t[i]);
    printf("\n"); */
    free(t);
    return 0;
}

