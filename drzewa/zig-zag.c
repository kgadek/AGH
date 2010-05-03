struct node{
	int val;
	struct node *right,*left,*parent;
	};
	
	
void zig (struct node* n)   				 		 	/*rotacja w prawo elementu n (wskakuje na miejsce parenta)*/
{
	n->parent->left=n->right;							/*podpina pod lew� ga��� parenta praw� ga��� elementu rotowanego*/
		if(n->right) n->right->parent=n->parent;		/*je�li prawa ga��� elementu rotowanego nie jest NULLem, to jej parentem b�dzie parent elementu n*/
	n->right=n->parent;									/*teraz pod prawym synem elementu n jest jego ojciec*/
	n->parent=n->parent->parent;						/*nowym ojcem elementu n, jest jego dziadek*/
	n->right->parent=n;									/*nowym ojcem by�ego ojca elementu n jest jest n (czyli prawy syn n, ma teraz za ojca element n)*/
		if(n->parent)	
		{												/*je�li ojciec n nie jest NULLem (czyli n nie jest rootem)*/
			if(n->parent->right==n->right) 				/*sprawd� kt�rym synem (lewym czy prawym) powinien by� element n*/
					n->parent->right=n;
			else 
					n->parent->left=n;
		}
}

void zag(struct node* n)							/*rotacja w lewo elementu n*/
{
	n->parent->right=n->left;
		if(n->left) n->left->parent=n->parent;
	n->left=n->parent;
	n->parent=n->parent->parent;
	n->left->parent=n;
		if(n->parent)
		{
			if(n->parent->left==n->left)
					n->parent->left=n;
			else 
					n->parent->right=n;
		}
}


void zig-zig(struct node *n)														/*rotacja dwa razy w prawo (bez dodatkowej zmiennej*/
{
	n->parent->parent->left=n->parent->right;										/*lewym synem dziadka b�dzie prawy syn ojca*/
		if(n->parent->right) n->parent->right->parent=n->parent->parent;			/*je�li prawy syn ojca nie jest NULLem to jego ojcem b�dzie dziadek*/
	n->parent->right=n->parent->parent;												/*prawym synem ojca staje si� teraz dziadek*/
	n->parent->left=n->right;														/*lewym synem ojca staje si� prawy syn elementu n*/
		if(n->right) n->right->parent=n->parent;									/*je�li prawy syn elementu n nie jest NULLem to jego ojcem b�dzie ojciec n*/
	n->right=n->parent;																/*ojciec elementu n staje si� jego prawym synem*/
	n->parent=n->parent->parent->parent;											/*nowym ojcem elementu n jest jego pradziadek*/
	n->right->parent->parent=n->right;												/*nowym ojcem dziadka zostaje by�y ojciec elementu n (prawy syn n)*/
	n->right->parent=n;																/*ojcem by�ego ojca elementu n (teraz prawego syna n) staje si� n*/
		if(n->parent)
		{																			/*je�li ojciec n nie jest NULLem (n nie jest rootem)*/
			if(n->parent->left==n->right->right)									/*podepnij n'a jako odpowiedniego syna swojego ojca*/
					n->parent->left=n;
			else
					n->parent->right=n;
		}
}


void zag-zig(struct node *n)														/*rotacja w lewo, a potem w prawo (z dodatkow� zmienn� tmp)*/
{
	struct node* tmp=n->parent;
	n->parent=n->parent->parent->parent;
	tmp->right=n->left;
		if(n->left) n->left->parent=tmp;
	tmp->parent->parent=n;
	tmp->parent->left=n->right;
		if(n->right) n->right->parent=tmp->parent;
	n->left=tmp;
	n->right=tmp->parent;
	tmp->parent=n;
		if(n->parent)
		{
			if(n->parent->left=n->right)
					n->parent->left=n;
			else
					n->parent->right=n;
		}
}			
