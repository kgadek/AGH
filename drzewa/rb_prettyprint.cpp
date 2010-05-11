#include <cstdio>
#include <cstdlib>

class node {
public:
	node *left, *right;
	int color;
	int value;
	node(int val=0, int col=1) { value=val; color=col; left=right=NULL; }
	~node() { if(left) delete left; if(right) delete right; }
};

namespace print_tree {
	char sym = 'o';
	int a=1, b=0;
	void print(node *x, int h) {
		if(h<=0) return;
		if(x==NULL) {
			for(h=(1<<(h-1))-1;h>=0;--h)
				putchar('\n');
			return;
		}
		int i=a*(2*h-1)+2*b;
		print(x->left,h-1);
		while(--i>0) putchar(' ');
		printf("%c[;%dm%c%c[%dm\n",0x1B,31-x->color,sym,0x1B,0);
		print(x->right,h-1);
	}
};

int main() {
	node *R = new node(11,1);
	R->left = new node(2,0);
	R->right = new node(14,1);
	R->left->left = new node(1,1);
	R->left->right = new node(7,1);
	R->left->right->left = new node(5,0);
	R->left->right->right = new node(8,0);
	R->right->right = new node(15,0);
	print_tree::print(R,4);
	return 0;
}

