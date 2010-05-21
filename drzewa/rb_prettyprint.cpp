#include <cstdio>
#include <cstdlib>

class node {
public:
	int color;
	int value;
	node *left, *right;
	node(int val=0, int col=1)
		: color(col), value(val), left(NULL), right(NULL)
		{}
	~node() { if(left) delete left; if(right) delete right; }
	/* kod tylko by g++ warningow nie rzucal, nieprzydatny wiec prawie zerowa
	   faktyczna funkcjonalnosc */
	node& operator=(const node&);
	node(const node &x)
		: color(x.color), value(x.value), left(NULL), right(NULL)
		{}
};

node& node::operator=(const node &x) {
	color = x.color;
	value = x.value;
	left = right = NULL;
	return *this;
}

namespace print_tree {
	int a=1, b=0, c=5;
	void _print(node *x, int h) {
		/*  */
		if(h<=0) return;
		if(x==NULL) {
			for(h=(1<<(h-1))-1;h>=0;--h)
				putchar('\n');
			return;
		}
		int i=a*(c*(h-1))+b+1;
		_print(x->left,h-1);
		while(--i>0) putchar(' ');
		printf("%c[;%dm(%3d)%c[%dm\n",
				0x1B,31-x->color,x->value,
				0x1B,0);
		_print(x->right,h-1);
	}
	void print_rev(node *x, int h) {
		a=1;
		_print(x,h);
	}
	void print_norm(node *x, int h) {
		a=-1;
		b+=(h-1)*c;
		_print(x,h);
		b-=(h-1)*c;
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
	print_tree::print_norm(R,4);
	/*dbg*/printf("____________________________________________________\n");
	print_tree::print_rev(R,4);
	return 0;
}

