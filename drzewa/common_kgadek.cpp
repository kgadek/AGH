#include "common_kgadek.h"
#include <cstdio>

int print_tree::a = 1;
int print_tree::b = 0;
int print_tree::c = 5;

void print_tree::_print(avlNode *x, int h) {
	if(h<=0) return;
	if(x==NULL) {
		for(h=(1<<(h-1))-1;h>=0;--h)
			putchar('\n');
		return;
	}
	int i=a*(c*(h-1))+b+1;
	print_tree::_print(x->l[1],h-1);
	while(--i>0) putchar(' ');
	printf("%c[;%dm(%3d)%c[%dm\n",
			0x1B,32+x->bal,x->key,
			0x1B,0);
	print_tree::_print(x->l[0],h-1);
}

void print_tree::print_rev(avlNode *x, int h) {
	a=1;
	print_tree::_print(x,h);
}
void print_tree::print_norm(avlNode *x, int h) {
	/*dbg*///printf("__________________________________________________\n");
	a=-1;
	b+=(h-1)*c;
	print_tree::_print(x,h);
	b-=(h-1)*c;
}

