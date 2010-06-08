#ifndef _BST_KGADEK
#define _BST_KGADEK

class bstNode {
	int val;
	bstNode *c[2];	/* c[0] - lewe dziecko; c[1] - prawe dziecko */
	bstNode(int x=0) : val(x);
};

void printBst(bstNode*);
void bstAdd(bstNode**,int);

#endif
