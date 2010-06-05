#ifndef __AVL_KGADEK
#define __AVL_KGADEK

#include "avl_kgadek.h"
#include "common_kgadek.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>


void avlInit(avlNode *x) {
	x->bal = 0;
	x->l[0] = x->l[1] = NULL;
}

avlNode* avlInsert(avlNode **R, int k) {
	/* A1-A9 to numery sektorow analogiczne jak w oryginale [1].
	   Zrodla:
	   	[1] Donald Knuth, Sztuka programowania, Tom 3 (oryg. The Art of Computer Programming),
			rozdz. 6.2.3: Balanced Trees
		[2] http://www.eternallyconfuzzled.com/tuts/datastructures/jsw_tut_avl.aspx
	 */
	avlNode *head, *p, *q, *r, *s, *t, *u;
	int a,d;
	if((*R) == NULL) {					/* A0: puste drzewo */
		(*R) = MEMALLOC(avlNode);	/* utworz node'a */
		assert( *R != NULL );
		avlInit(*R);			/* zainicjuj */
		(*R)->key = k;			/* ustaw mu wartosc */
		return *R;
	}
	u = NULL;				/* aby sie kompilator nie rzucal */
	head = MEMALLOC(avlNode); 		/* utworzenie HEAD */
	avlInit(head);
	head->l[1] = *R;					/* A1. inicjacja */
	t = head;
	p = s = *R;
	while(1) {						/* A2. szukanie */
		if(k == p->key)			/* exit_success */
			return p;
		d = (k > p->key);
		q = p->l[d];					/* A3/A4. przejscie lewo/prawo */
		if(q == NULL)
			break;
		if(q->bal != 0) {
			t = p;
			s = q;
		}
		p = q;
	}
	p->l[d] = u = q = MEMALLOC(avlNode);			/* A5. wstawianie */
	avlInit(q);
	q->key = k;
	r = p = s->l[ a = (k > s->key) ];			/* A6. poprawa wartosci balansow */
	a = 2*a - 1;
	while(p!=q) {				/* dla kazdego wierzcholka miedzy P a Q (bez Q) */
		d = (k > p->key);		/* 	wybierz kierunek */
		p->bal = 2*d - 1;		/* 	popraw balans */
		p = p->l[d];			/* 	przejdz dalej */
	}
	if(s->bal == 0) {				/* A7.i - lekkie zaburzenie balansu (+1 lub -1) */
		s->bal = a;				/* 	czyli drzewo uroslo */
		return u;
	} else if(s->bal == -a) {			/* A7.ii - wstawienie poprawilo balans drzewa */
		s->bal = 0;
		return u;
	}						/* A7.iii - zaburzenie balansu (+2 lub -2) */
	assert( s->bal == a );
	d = a<0?0:1;
	if(r->bal == a ) {				/* A8. pojedyncza rotacja */
		p = r;				/* rotuj w lewo/prawo (a = +1/-1) wokol wierzch. S */
		s->l[d] = r->l[!d];
		r->l[!d] = s;
		s->bal = r->bal = 0;
	} else {					/* A9. podwojna rotacja */
		p = r->l[!d];			/* rotuj w prawo/lewo (a = +1/-1) wokol wierz. R */
		r->l[!d] = p->l[d];		/* a nastepne */
		p->l[d] = r;			/* rotuj w lewo/prawo (a = +1/-1) wokol wierz. S */
		s->l[d] = p->l[!d];
		p->l[!d] = s;
		s->bal = r->bal = 0;		/* wartosci balansu S i R zaleza od podprzypadkow: */
		if(p->bal == a)			/*                       | (-a,0) , gdy p->bal == a */
			s->bal = -a;		/* ( s->bal , r->bal ) = | (0,0)  , gdy p->bal == 0*/
		else if(p->bal == -a)		/*                       | (0,a)  , gdy p->bal == -a */
			r->bal = a;
		p->bal = 0;
	}
	t->l[s == t->l[1]] = p;		/* wpp popraw wskazanie od ojca P */
	(*R) = head->l[1];
	MEMFREE(head);				/* pozbycie sie tymczasowego HEAD-a */
	return u;				/* zwroc wsk. do dodanego wierzcholka */
}

avlNode* avlQuery(avlNode *R, int k) {
	while(R && R->key != k)
		R = R->l[k > R->key];
	return R;
}

void avlFree(avlNode *x) {
	if(x==NULL)
		return;
	avlFree(x->l[0]);
	avlFree(x->l[1]);
	MEMFREE(x);
}

#endif
