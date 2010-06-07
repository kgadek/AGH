#ifndef _HEAP_KGADEK
#define _HEAP_KGADEK

class heapNode {
	int val;
	heapNode *c[2];	/* c[0] - lewe dziecko; c[1] - prawe dziecko */
	heapNode(int x=0) : val(x);
};

void printHeap(heapNode*);
void heapAdd(heapNode**,int);

#endif
