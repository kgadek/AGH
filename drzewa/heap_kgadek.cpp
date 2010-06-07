#include "heap_kgadek.h"
#include <cstdio>

heapNode::heapNode(int) { c[0]=c[1]=NULL; }

void printHeap(heapNode *R) {
	/* po wywolaniu trzeba samemy wypisac znak konca linii */
	if(!x)
		return;
	printHeap(x->c[0]);
	printf("%d ",x->val);
	printHeap(x->c[1]);
}

void heapAdd(heapNode **R, int x) {
	while(*R)
		R = &((*R)->c[x >= (*R)->val]);
	(*R) = new heapNode(x);
}

