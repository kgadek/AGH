#include "bst_kgadek.h"
#include <cstdio>

bstNode::bstNode(int x) : val(x) { c[0]=c[1]=NULL; }

void printBst(bstNode *R) {
	/* po wywolaniu trzeba samemy wypisac znak konca linii */
	if(!R)
		return;
	printBst(R->c[0]);
	printf("%d ",R->val);
	printBst(R->c[1]);
}

void bstAdd(bstNode **R, int x) {
	while(*R)
		R = &((*R)->c[x >= (*R)->val]);
	(*R) = new bstNode(x);
}

