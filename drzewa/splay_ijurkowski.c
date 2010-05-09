struct node {
    int val;
    struct node *right, *left, *parent;
};


void zig(struct node *n)
{					/*rotacja w prawo elementu n (wskakuje na miejsce parenta) */
    n->parent->left = n->right;		/*podpina pod lewa galaz parenta prawa galaz elementu rotowanego */
    if (n->right)
	n->right->parent = n->parent;	/*jesli prawa galaz elementu rotowanego nie jest NULLem, to jej
					   parentem bedzie parent elementu n */
    n->right = n->parent;		/*teraz pod prawym synem elementu n jest jego ojciec */
    n->parent = n->parent->parent;	/*nowym ojcem elementu n, jest jego dziadek */
    n->right->parent = n;		/*nowym ojcem bylego ojca elementu n jest jest n (czyli prawy
				   	  syn n, ma teraz za ojca element n) */
    if (n->parent) {			/*jesli ojciec n nie jest NULLem (czyli n nie jest rootem) */
	if (n->parent->right == n->right)	/*sprawdz którym synem (lewym czy prawym) powinien byc
						   element n */
	    n->parent->right = n;
	else
	    n->parent->left = n;
    }
}

void zag(struct node *n)
{					/*rotacja w lewo elementu n */
    n->parent->right = n->left;
    if (n->left)
	n->left->parent = n->parent;
    n->left = n->parent;
    n->parent = n->parent->parent;
    n->left->parent = n;
    if (n->parent) {
	if (n->parent->left == n->left)
	    n->parent->left = n;
	else
	    n->parent->right = n;
    }
}


void zig_zig(struct node *n)
{						/*rotacja dwa razy w prawo (bez dodatkowej zmiennej */
    n->parent->parent->left = n->parent->right;	/*lewym synem dziadka bedzie prawy syn ojca */
    if (n->parent->right)
	n->parent->right->parent = n->parent->parent;	/*jesli prawy syn ojca nie jest NULLem to
							   jego ojcem bedzie dziadek */
    n->parent->right = n->parent->parent;	/*prawym synem ojca staje sie teraz dziadek */
    n->parent->left = n->right;			/*lewym synem ojca staje sie prawy syn elementu n */
    if (n->right)
	n->right->parent = n->parent;		/*jesli prawy syn elementu n nie jest NULLem to jego ojcem
					  	 bedzie ojciec n */
    n->right = n->parent;			/*ojciec elementu n staje sie jego prawym synem */
    n->parent = n->parent->parent->parent;	/*nowym ojcem elementu n jest jego pradziadek */
    n->right->parent->parent = n->right;	/*nowym ojcem dziadka zostaje byly ojciec elementu n
						   (prawy syn n) */
    n->right->parent = n;			/*ojcem bylego ojca elementu n (teraz prawego syna n)
				  		 staje sie n */
    if (n->parent) {				/*jesli ojciec n nie jest NULLem (n nie jest rootem) */
	if (n->parent->left == n->right->right)	/*podepnij n'a jako odpowiedniego syna swojego ojca */
	    n->parent->left = n;
	else
	    n->parent->right = n;
    }
}


void zag_zig(struct node *n)
{						/*rotacja w lewo, a potem w prawo (z dodatkowa zmienna tmp) */
    struct node *tmp = n->parent;
    n->parent = n->parent->parent->parent;
    tmp->right = n->left;
    if (n->left)
	n->left->parent = tmp;
    tmp->parent->parent = n;
    tmp->parent->left = n->right;
    if (n->right)
	n->right->parent = tmp->parent;
    n->left = tmp;
    n->right = tmp->parent;
    tmp->parent = n;
    if (n->parent) {
	if ((n->parent->left) == n->right)
	    n->parent->left = n;
	else
	    n->parent->right = n;
    }
}
