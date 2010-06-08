#include "bst_kgadek.h"
#include <cstdio>

bstNode::bstNode(int) { c[0]=c[1]=NULL; }

void printBst(bstNode *R) {
	/* po wywolaniu trzeba samemy wypisac znak konca linii */
	if(!x)
		return;
	printBst(x->c[0]);
	printf("%d ",x->val);
	printBst(x->c[1]);
}

void bstAdd(bstNode **R, int x) {
	while(*R)
		R = &((*R)->c[x >= (*R)->val]);
	(*R) = new bstNode(x);
}

