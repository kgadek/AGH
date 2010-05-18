#include<stdio.h>
#include<string.h>

struct osoba
	{
	char* id;
	struct osoba* left;
	struct osoba* right;
	struct osoba* parent;
	struct osoba* gparent;
	struct osoba** cousin;
	struct osoba** sibling;
	struct osoba** child;
	struct osoba** gchild;
	};
struct osoba* drzewo(struct osoba* root,char* id1, char* id2, char* pokrew)
	{int j;
		if(!root)
		{
			root=(struct osoba*)malloc(sizeof(struct osoba));
			root->id=(char*)malloc(100*sizeof(char));
			strcpy(root->id,id1);
			root->left=0;
			root->right=0;
			root->parent=0;
			root->gparent=0;
			root->cousin=0;
			root->sibling=0;
			root->child=0;
			root->gchild=0;
			if(strcmp(root->id,id2)>0)
			{
				root->right=(struct osoba*)malloc(sizeof(struct osoba));
				root->right->id=(char*)malloc(100*sizeof(char));
				strcpy(root->right->id,id2);
				root->right->left=0;
				root->right->right=0;
				root->right->parent=0;
				root->right->gparent=0;
				root->right->cousin=0;
				root->right->sibling=0;
				root->right->child=0;
				root->right->gchild=0;
				if(strcmp(pokrew,"child-of")==0)
				{
				root->right->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
				root->right->child[0]=root;
				root->parent=root->right;
				}
				else
					if(strcmp(pokrew,"parent-of")==0)
					{
					root->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
					root->child[0]=root->right;
					root->right->parent=root;
					}
					else
					if(strcmp(pokrew,"sibling-of")==0)
						{
						root->sibling=(struct osoba*)malloc(10*sizeof(struct osoba*));
						root->right->sibling=(struct osoba*)malloc(10*sizeof(struct osoba*));
						root->sibling[0]=root->right;
						root->right->sibling[0]=root;
						}
					else
						if(strcmp(pokrew,"cousin-of")==0)
							{
							root->cousin=(struct osoba*)malloc(10*sizeof(struct osoba*));
							root->right->cousin=(struct osoba*)malloc(10*sizeof(struct osoba*));
							root->cousin[0]=root->right;
							root->right->cousin[0]=root;
							}
						else
								if(strcmp(pokrew,"grandparent-of")==0)
								{
								root->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
								root->gchild[0]=root->right;
								root->right->gparent=root;
								}
								else
									if(strcmp(pokrew,"grandchild-of")==0)
									{
									root->right->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
									root->right->gchild[0]=root;
									root->gparent=root->right;
									}
			}
			else
			{
			
				root->left=(struct osoba*)malloc(sizeof(struct osoba));
				root->left->id=(char*)malloc(100*sizeof(char));
				strcpy(root->left->id,id2);
				root->left->left=0;
				root->left->right=0;
				root->left->parent=0;
				root->left->gparent=0;
				root->left->cousin=0;
				root->left->sibling=0;
				root->left->child=0;
				root->left->gchild=0;
				if(strcmp(pokrew,"child-of")==0)
				{
				root->left->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
				root->left->child[0]=root;
				root->parent=root->left;
				}
				else
					if(strcmp(pokrew,"parent-of")==0)
					{
					root->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
					root->child[0]=root->left;
					root->left->parent=root;
					}
						else
						if(strcmp(pokrew,"sibling-of")==0)
						{
						root->sibling=(struct osoba*)malloc(10*sizeof(struct osoba*));
						root->left->sibling=(struct osoba*)malloc(10*sizeof(struct osoba*));
						root->sibling[0]=root->left;
						root->left->sibling[0]=root;
						}
					else
						if(strcmp(pokrew,"cousin-of")==0)
							{
							root->cousin=(struct osoba*)malloc(10*sizeof(struct osoba*));
							root->left->cousin=(struct osoba*)malloc(10*sizeof(struct osoba*));
							root->cousin[0]=root->left;
							root->left->cousin[0]=root;
							}
						else
									if(strcmp(pokrew,"grandparent-of")==0)
									{
									root->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
									root->gchild[0]=root->left;
									root->left->gparent=root;
									}
							else
										if(strcmp(pokrew,"grandchild-of")==0)
										{
										root->left->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
										root->left->gchild[0]=root;
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
						p->id=(char*)malloc(100*sizeof(char));
						strcpy(p->id,id1);
						p->left=0;
						p->right=0;
						p->parent=0;
						p->gparent=0;
						p->cousin=0;
						p->sibling=0;
						p->child=0;
						p->gchild=0;
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
						p->id=(char*)malloc(100*sizeof(char));
						strcpy(p->id,id1);
						p->left=0;
						p->right=0;
						p->parent=0;
						p->gparent=0;
						p->cousin=0;
						p->sibling=0;
						p->child=0;
						p->gchild=0;
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
						g->id=(char*)malloc(100*sizeof(char));
						strcpy(g->id,id2);
						g->left=0;
						g->right=0;
						g->parent=0;
						g->gparent=0;
						g->cousin=0;
						g->sibling=0;
						g->child=0;
						g->gchild=0;
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
						g->id=(char*)malloc(100*sizeof(char));
						strcpy(g->id,id2);
						g->left=0;
						g->right=0;
						g->parent=0;
						g->gparent=0;
						g->cousin=0;
						g->sibling=0;
						g->child=0;
						g->gchild=0;
					}
				}
			}
			int i;
		if(strcmp(pokrew,"child-of")==0)
				{
				p->parent=g;
				if(p->gparent)
					if(g->gparent)p->gparent->parent=g->gparent;
					else g->gparent=p->gparent->parent;
				if(g->parent)
					{
						p->gparent=g->parent;
						if(!g->parent->gchild) g->parent->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
						i=0;
						while(g->parent->gchild[i] && g->parent->gchild[i]!=p)i++;
						if(!g->parent->gchild[i])g->parent->gchild[i]=p;
						
					}
				if(p->gparent)
					{
						g->parent=p->gparent;
						if(!p->gparent->child) p->gparent->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
						i=0;
						while(p->gparent->child[i] && p->gparent->child[i]!=g)i++;
						if(!p->gparent->child[i])p->gparent->child[i]=g;
					}
				if(!g->child) g->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
				i=0;
				while(g->child[i] && g->child[i]!=p)i++;
				if(!g->child[i])g->child[i]=p;
				if(p->sibling)
					while(p->sibling[i]){
							p->sibling[i]->parent=p->parent;
							if(p->gparent)p->sibling[i]->gparent=p->gparent;
							i++;
							}
				i=0;
				if(p->gparent)
					if(p->cousin)
						while(p->cousin[i]){
							p->cousin[i]->gparent=p->gparent;
							i++;
							}
				i=0;
				if(p->child)
					while(p->child[i]){
							p->child[i]->gparent=g;
							i++;
							}
				
				}
				else
					if(strcmp(pokrew,"parent-of")==0)
					{
						g->parent=p;
						if(g->gparent)
							if(p->gparent)g->gparent->parent=p->gparent;
							else p->gparent=g->gparent->parent;
						if(p->parent)
						{
							g->gparent=p->parent;
							if(!p->parent->gchild) p->parent->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
							i=0;
							while(p->parent->gchild[i] && p->parent->gchild[i]!=g)i++;
							if(!p->parent->gchild[i])p->parent->gchild[i]=g;
						
						}
						if(g->gparent)
						{
							p->parent=g->gparent;
							if(!g->gparent->child) g->gparent->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
							i=0;
							while(g->gparent->child[i] && g->gparent->child[i]!=p)i++;
							if(!g->gparent->child[i])g->gparent->child[i]=p;
						}
						if(!p->child) p->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
						i=0;
						while(p->child[i] && p->child[i]!=g)i++;
						if(!p->child[i])p->child[i]=g;
						if(g->sibling)
							while(g->sibling[i]){
								g->sibling[i]->parent=g->parent;
								g->sibling[i]->gparent=g->gparent;
								i++;
								}
						i=0;
						if(g->gparent)
							if(g->cousin)
								while(g->cousin[i]){
									g->cousin[i]->gparent=g->gparent;
									i++;
									}
						i=0;
						if(g->child)
							while(g->child[i]){
								g->child[i]->gparent=p;
								i++;
								}	
					}
					else
						if(strcmp(pokrew,"sibling-of")==0)
						{
						if(p->parent && !g->parent)g->parent=p->parent;
						if(p->gparent && !g->gparent)g->gparent=p->gparent;
						if(g->parent && !p->parent)p->parent=g->parent;
						if(g->gparent && !p->gparent)p->gparent=g->gparent;
						if(!p->sibling)p->sibling=(struct osoba*)malloc(10*sizeof(struct osoba*));
						if(!g->sibling)g->sibling=(struct osoba*)malloc(10*sizeof(struct osoba*));
						i=0;
						while(p->sibling[i] && p->sibling[i]!=g){
											p->sibling[i]->parent=p->parent;
											if(p->parent)p->sibling[i]->parent->parent=p->gparent;
											p->sibling[i]->gparent=p->gparent;
											i++;
											}
						if(!p->sibling[i])p->sibling[i]=g;
						i=0;
						while(g->sibling[i] && g->sibling[i]!=p){
											g->sibling[i]->parent=g->parent;
											if(g->parent)g->sibling[i]->parent->parent=g->gparent;
											g->sibling[i]->gparent=g->gparent;
											i++;
											}
						if(!g->sibling[i])g->sibling[i]=p;
						if(p->parent)p->parent->parent=p->gparent;
						if(g->parent)g->parent->parent=g->gparent;
						}
						else
							if(strcmp(pokrew,"cousin-of")==0)
							{
							if(p->gparent && !g->gparent)
										{
											g->gparent=p->gparent;
											i=0;
											while(g->gparent->gchild[i] && g->gparent->gchild[i]!=g)i++;
											if(!g->gparent->gchild[i])g->gparent->gchild[i]=g;
										}
							if(g->gparent && !p->gparent)
										{
											p->gparent=g->gparent;
											i=0;
											while(p->gparent->gchild[i] && p->gparent->gchild[i]!=p)i++;
											if(!p->gparent->gchild[i])p->gparent->gchild[i]=p;
										}
							if(!p->cousin)p->cousin=(struct osoba*)malloc(10*sizeof(struct osoba*));
							if(!g->cousin)g->cousin=(struct osoba*)malloc(10*sizeof(struct osoba*));
							i=0;
							while(p->cousin[i] && p->cousin[i]!=g){
											if(p->gparent)p->cousin[i]->gparent=p->gparent;
											i++;
											}
							if(!p->cousin[i])p->cousin[i]=g;
							i=0;
							while(g->cousin[i] && g->cousin[i]!=p){
											if(g->gparent)g->cousin[i]->gparent=g->gparent;
											i++;
											}
							if(!g->cousin[i])g->cousin[i]=p;
							if(p->gparent)
							{i=0;
							if(g->sibling)
								while(g->sibling[i])
									{
									g->sibling[i]->gparent=g->gparent;
									i++;
									}
							i=0;
							if(p->sibling)
								while(p->sibling[i])
									{
									p->sibling[i]->gparent=p->gparent;
									i++;
									}
							}
							
							}
							else
								if(strcmp(pokrew,"grandparent-of")==0)
								{
									g->gparent=p;
									if(!p->gchild)p->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
									i=0;
									while(p->gchild[i] && p->gchild[i]!=g) i++;
									if(!p->gchild[i])p->gchild[i]=g;
									if (g->parent)
										{
										i=0;
										if(g->parent->sibling)
											while(g->parent->sibling[i])
												{
												j=0;
												while(p->child[j] && p->child[j]!=g->parent->sibling[i])j++;
												if(!p->child[j])p->child[j]=g->parent->sibling[i];
												g->parent->sibling[i]->parent=p;
												i++;
												}	
										if(!p->child)p->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
										i=0;
										while(p->child[i] && p->child[i]!=g->parent)i++;
										if(!p->child[i])p->child[i]=g->parent;
										g->parent->parent=p;
										g->parent->gparent=p->parent;
										}
									i=0;
									if(g->cousin)
										while(g->cousin[i]){
												g->cousin[i]->gparent=g->gparent;
												i++;
												}
									i=0;
									if(g->sibling)
										while(g->sibling[i]){
												g->sibling[i]->gparent=g->gparent;
												i++;
												}
								}
								else
									if(strcmp(pokrew,"grandchild-of")==0)
									{
											p->gparent=g;
										if(!g->gchild)g->gchild=(struct osoba*)malloc(10*sizeof(struct osoba*));
										i=0;
										while(g->gchild[i] && g->gchild[i]!=p) i++;
										if(!g->gchild[i])g->gchild[i]=p;
										if (p->parent)
											{
											i=0;
											if(p->parent->sibling)
											while(p->parent->sibling[i])
														{
														j=0;
														while(g->child[j] && g->child[j]!=p->parent->sibling[i])j++;
														if(!g->child[j])g->child[j]=p->parent->sibling[i];
														p->parent->sibling[i]->parent=g;
														i++;
														}	
											if(!g->child)g->child=(struct osoba*)malloc(10*sizeof(struct osoba*));
											i=0;
											while(g->child[i] && g->child[i]!=p->parent)i++;
											if(!g->child[i])g->child[i]=p->parent;
											p->parent->parent=g;
											p->parent->gparent=g->parent;
											}
										i=0;
										if(p->cousin)
											while(p->cousin[i]){
													p->cousin[i]->gparent=p->gparent;
													i++;
													}
										i=0;
										if(p->sibling)
											while(p->sibling[i]){
													p->sibling[i]->gparent=p->gparent;
													i++;
													}
									}
		}
	return root;
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
		struct osoba* tmp;
		struct osoba* tmp2=p;
		while(tmp2)
			{
			tmp=g;
			//printf(" ------Pierwszy parent: %s-------\n",tmp2->id);
				while(tmp)
					{
					//printf(" Tutaj idzie drugi parent: %s\n", tmp->id);
					if(strcmp(tmp->id,tmp2->id)==0 && tmp2!=p && tmp!=g ){
						printf("%s\n",tmp2->id);
						return;
						}
					if(tmp->parent) tmp=tmp->parent;
					else tmp=tmp->gparent;
					}
					
			if(tmp2->parent) tmp2=tmp2->parent;
			else tmp2=tmp2->gparent;
			}
			printf("NN\n");
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
