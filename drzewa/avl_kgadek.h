#ifndef __AVL_H
#define __AVL_H

struct _avlNode {
	int key;			/* klucz w węźle */
	int bal;			/* wartosc balansu (potrzebne 3B) */
	struct _avlNode *l[2];		/* link do dzieci */
};
typedef struct _avlNode avlNode;

void avlInit(avlNode*);			/* zainicjuj wierzcholek */
avlNode* avlQuery(avlNode *,int);	/* szukaj(1) */
avlNode* avlInsert(avlNode **,int);	/* dodaj */
void avlFree(avlNode*);			/* czysc pamiec */
/* (1): avlInsert zwraca wskaznik do dodanego wierzcholka lub do istniejacego
	o tym samym kluczu */



/* makra do uproszczenia zmiany alokacji z
   C (malloc/free) na C++ (new/delete) */
#define MEMALLOC(type) ((type*)malloc(sizeof(type)))
#define MEMFREE(obj) free(obj)


#endif
