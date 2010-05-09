#include <stdio.h>
#include<stdlib.h>


struct Node {
    char val;
    int end;
    struct Node *child;
    struct Node *next;
};
typedef struct Node node;

node *root;			/* wartownik na początek drzewka */

node *find(const char *txt, node ** where) /* 'const char' by dzialalo bezposrenie przekazywanie napisu */
{
    int i;

    for (i = 0; txt[i]; i++) {
	while (*where && txt[i] != (*where)->val)
	    where = &((*where)->next);
	if (*where && txt[i + 1])
	    where = &((*where)->child);
    }

    return *where;
}


void insert(const char *txt, node ** p)
{
    char c = *txt;
    while (*p && c != (*p)->val)
	p = &((*p)->next);
    if (!*p) {			/* next jest nulem, nie ma litery */
	*p = (node *) malloc(sizeof(node));
	(*p)->val = c;
	(*p)->next = (*p)->child = NULL;
	if (!*(txt + 1))
	    (*p)->end = 1;
    }
    /*p wskazuje na wskaznik do szukanej litery */
    if (*(txt + 1))
	insert(++txt, &((*p)->child));
}


void del(const char *txt, node * where)
{
    node *akt = find(txt, &where);
    if (!akt);
    /*error - brak wyrazu */
    else
	akt->end = 0;		/*juz nie wystepuje takie slowo*/

}


int main()
{
    /* 
     * inicjalizacja drzewka - root jest wartownikiem bez wartości
     * zrobiłem go wcześniej, ale teraz insert jest ze wskaźnikiem do
     * wskaźnika, więc wartownik na dobrą sprawę jest niepotrzebny
     */
    root = (node *) malloc(sizeof(node));
    root->val = 0;
    root->end = 1;
    root->child = NULL;
    root->next = NULL;

    insert("BARTEK", &(root->child));
    insert("BAR", &(root->child));
    insert("BAZA", &(root->child));
    del("BAZA", root->child);

    return 0;
}
