#include<stdio.h>
#include<string.h>

struct osoba
	{
	char* id;
	char k;
	struct osoba* left;
	struct osoba* right;
	struct osoba* parent;
	struct osoba* gparent;
	struct osoba** child;
	};
	
void przepnij(struct osoba* p, struct osoba* g,int step)
	{
			p->parent=g;
				if(p->gparent)g->parent=p->gparent;
				if(g->parent && step<3)przepnij(p->parent,g->parent,step+1);
				
	}
		
struct osoba* drzewo(struct osoba* root,char* id1, char* id2, char* pokrew)
	{
	if(!root)
		{
			root=(struct osoba*)malloc(sizeof(struct osoba));
			root->id=(char*)malloc(50*sizeof(char));
			strcpy(root->id,id1);
			root->left=0;
			root->right=0;
			root->parent=0;
			root->gparent=0;
			root->child=0;
			if(strcmp(root->id,id2)>0)
			{
				root->right=(struct osoba*)malloc(sizeof(struct osoba));
				root->right->id=(char*)malloc(50*sizeof(char));
				strcpy(root->right->id,id2);
				root->right->left=0;
				root->right->right=0;
				root->right->parent=0;
				root->right->gparent=0;
				root->right->child=0;
				if(strcmp(pokrew,"child-of")==0)
				{
				root->right->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
				root->right->child[0]=root;
				root->parent=root->right;
				}
				else
					if(strcmp(pokrew,"parent-of")==0)
					{
					root->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
					root->child[0]=root->right;
					root->right->parent=root;
					}
					else
								if(strcmp(pokrew,"grandparent-of")==0)
								{
								root->right->gparent=root;
								}
								else
									if(strcmp(pokrew,"grandchild-of")==0)
									{
									root->gparent=root->right;
									}
			}
			else
			{
			
				root->left=(struct osoba*)malloc(sizeof(struct osoba));
				root->left->id=(char*)malloc(50*sizeof(char));
				strcpy(root->left->id,id2);
				root->left->left=0;
				root->left->right=0;
				root->left->parent=0;
				root->left->gparent=0;
				root->left->child=0;
				if(strcmp(pokrew,"child-of")==0)
				{
				root->left->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
				root->left->child[0]=root;
				root->parent=root->left;
				}
				else
					if(strcmp(pokrew,"parent-of")==0)
					{
					root->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
					root->child[0]=root->left;
					root->left->parent=root;
					}
						else
									if(strcmp(pokrew,"grandparent-of")==0)
									{
									root->left->gparent=root;
									}
							else
										if(strcmp(pokrew,"grandchild-of")==0)
										{
										root->gparent=root->left;
										}
			}
		}
		else
		{
		struct osoba* p;
		struct osoba* g;
		p=root;
		g=root;
		while(strcmp(p->id,id1)!=0)
			{
				if(strcmp(p->id,id1)>0)
				{
					if(p->right)p=p->right;
					else
					{
						p->right=(struct osoba*)malloc(sizeof(struct osoba));
						p=p->right;
						p->id=(char*)malloc(50*sizeof(char));
						strcpy(p->id,id1);
						p->left=0;
						p->right=0;
						p->parent=0;
						p->gparent=0;
						p->child=0;
					}
				}
				else
				if(strcmp(p->id,id1)<0)
				{
				if(p->left)p=p->left;
					else
					{
						p->left=(struct osoba*)malloc(sizeof(struct osoba));
						p=p->left;
						p->id=(char*)malloc(50*sizeof(char));
						strcpy(p->id,id1);
						p->left=0;
						p->right=0;
						p->parent=0;
						p->gparent=0;
						p->child=0;
					}
				}
			}
		while(strcmp(g->id,id2)!=0)
			{
				if(strcmp(g->id,id2)>0)
				{
					if(g->right)g=g->right;
					else
					{
						g->right=(struct osoba*)malloc(sizeof(struct osoba));
						g=g->right;
						g->id=(char*)malloc(50*sizeof(char));
						strcpy(g->id,id2);
						g->left=0;
						g->right=0;
						g->parent=0;
						g->gparent=0;
						g->child=0;
					}
				}
				else
				if(strcmp(g->id,id2)<0)
				{
				if(g->left)g=g->left;
					else
					{
						g->left=(struct osoba*)malloc(sizeof(struct osoba));
						g=g->left;
						g->id=(char*)malloc(50*sizeof(char));
						strcpy(g->id,id2);
						g->left=0;
						g->right=0;
						g->parent=0;
						g->gparent=0;
						g->child=0;
					}
				}
			}
			int i;
		if(strcmp(pokrew,"child-of")==0)
				{
				p->parent=g;
				if(g->parent)p->gparent=g->parent;
				if(p->gparent)
					{
						g->parent=p->gparent;
						if(!p->gparent->child) p->gparent->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
						i=0;
						while(p->gparent->child[i] && p->gparent->child[i]!=g)i++;
						if(!p->gparent->child[i])p->gparent->child[i]=g;
					}
				if(!g->child) g->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
				i=0;
				while(g->child[i] && g->child[i]!=p)i++;
				if(!g->child[i])g->child[i]=p;
				i=0;
				if(p->child)
					while(p->child[i]){
							p->child[i]->gparent=g;
							i++;
							}
				if(g->parent)przepnij(p->parent,g->parent,0);
				
				}
				else
					if(strcmp(pokrew,"parent-of")==0)
					{
						g->parent=p;
						if(p->parent)g->gparent=p->parent;
						if(g->gparent)
						{
							p->parent=g->gparent;
							if(!g->gparent->child) g->gparent->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
							i=0;
							while(g->gparent->child[i] && g->gparent->child[i]!=p)i++;
							if(!g->gparent->child[i])g->gparent->child[i]=p;
						}
						if(!p->child) p->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
						i=0;
						while(p->child[i] && p->child[i]!=g)i++;
						if(!p->child[i])p->child[i]=g;
						i=0;
						if(g->child)
							while(g->child[i]){
								g->child[i]->gparent=p;
								i++;
								}	
					if(p->parent)przepnij(g->parent,p->parent,0);
					}
					else
						if(strcmp(pokrew,"sibling-of")==0)
						{
						if(p->gparent && !g->gparent)g->gparent=p->gparent;
						if(p->parent && !g->parent){
										g->parent=p->parent;
										przepnij(g,p->parent,2);
										}
						if(g->gparent && !p->gparent)p->gparent=g->gparent;
						if(g->parent && !p->parent){
										p->parent=g->parent;
										przepnij(p,p->parent,2);
										}
						
						}
						else
							if(strcmp(pokrew,"cousin-of")==0)
							{
							if(p->gparent)g->gparent=p->gparent;
								else if(g->gparent)p->gparent=g->gparent;
							if(g->parent && g->gparent)przepnij(g,g->parent,1);
							
							}
							else
								if(strcmp(pokrew,"grandparent-of")==0)
								{
									g->gparent=p;
									if (g->parent)
										{
										if(!p->child)p->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
										i=0;
										while(p->child[i] && p->child[i]!=g->parent)i++;
										if(!p->child[i])p->child[i]=g->parent;
										g->parent->parent=p;
										g->parent->gparent=p->parent;
										}
									if(g->parent)przepnij(g->parent,p,0);
								}
								else
									if(strcmp(pokrew,"grandchild-of")==0)
									{
											p->gparent=g;
										if (p->parent)
											{	
											if(!g->child)g->child=(struct osoba*)malloc(4*sizeof(struct osoba*));
											i=0;
											while(g->child[i] && g->child[i]!=p->parent)i++;
											if(!g->child[i])g->child[i]=p->parent;
											p->parent->parent=g;
											p->parent->gparent=g->parent;
											}
										if(p->parent)przepnij(p->parent,g,0);
									}
		}
	return root;
		}
char* szukaj(struct osoba* p, struct osoba* g, struct osoba* g2)
	{	char* a, *b;
	a="NN";
	b="NN";
		if(g2->k && g2->k=='T' && g2!=p && g2!=g )
						{
						return g2->id;
						}
		if(g2->parent) a=szukaj(p,g,g2->parent);
		if(strcmp(a,"NN")==0)
			if(g2->gparent && (!g2->parent || !g2->parent->parent)) b=szukaj(p,g,g2->gparent);
		if(strcmp(a,"NN")!=0) return a;
			else return b;
	}
void koloruj(struct osoba* p, struct osoba* p2)
	{
			if(!p2->k || p2->k=='N')p2->k='T';
				else p2->k='N';
			if(p2->parent) koloruj(p,p2->parent);
					if(p2->gparent && (!p2->parent || !p2->parent->parent)) koloruj(p,p2->gparent);
	}

void wyszukajprzodka(struct osoba* root, char* id1, char* id2)
	{
		struct osoba* p;
		struct osoba* g;
		p=root;
		g=root;
		while(strcmp(p->id,id1)!=0)
			{
			if(strcmp(p->id,id1)>0)
			{
				if(p->right)p=p->right;
				else
					{
					printf("NN\n");
					return;
					}
			}
			else
			{
				if(p->left)p=p->left;
				else
					{
					printf("NN\n");
					return;
					}
				}
			}
			
		while(strcmp(g->id,id2)!=0)
			{
			if(strcmp(g->id,id2)>0)
			{
				if(g->right)g=g->right;
				else
					{
					printf("NN\n");
					return;
					}
			}
			else
			{
				if(g->left)g=g->left;
				else
					{
					printf("NN\n");
					return;
					}
				
			}
			}
		koloruj(g,g);
		printf("%s\n",szukaj(g,p,p));
		koloruj(g,g);
		return;
		}				
		

int main()
{
char imie1[100];
char nazw1[40];
char imie2[100];
char nazw2[40];
char pokrew[15];
struct osoba* root=0;
while(scanf("%s",imie1)!=EOF)
{
	scanf("%s %s %s %s",nazw1,pokrew, imie2, nazw2);
	strcat(imie1," ");
	strcat(imie1,nazw1);
	strcat(imie2," ");
	strcat(imie2,nazw2);
	if(strcmp(pokrew,":")==0)
		{
		wyszukajprzodka(root,imie1,imie2);
		}
	else
		{
		root=drzewo(root,imie1,imie2,pokrew);
		}
}
return 0;
}
