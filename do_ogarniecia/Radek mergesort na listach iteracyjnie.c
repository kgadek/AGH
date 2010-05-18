#include <stdio.h>
#include <stdlib.h>
 
struct node{
       struct node *n;
       int v;
       };
 
struct node* init(){
       return NULL;
       }
       
void add(struct node **p, int v){
     struct node *t=*p;
     *p=(struct node*)malloc(sizeof(struct node));
     (*p)->v=v;
     (*p)->n=t;
     }
     
void writy(struct node *p){
     while(p){
     printf("%i ",p->v);
     p=p->n;}
     }

struct node *merge(struct node *a, struct node *b){
	struct node *n=init();
	struct node *t, *e;
	if(a->v < b->v){
		t=a;
		a=a->n;
		t->n=NULL;
		n=t;
		e=t;
	}
	else{
		t=b;
		b=b->n;
		t->n=NULL;
		n=t;
		e=t;
	}
	while(a && b){
		if(a->v < b->v){
			t=a;
			a=a->n;
			t->n=NULL;
			e->n=t;
			e=t;
		}
		else{
			t=b;
			b=b->n;
			t->n=NULL;
			e->n=t;
			e=t;
		}
	}
	if(a){
		e->n=a;
	}
	else{
		e->n=b;
	}
	return n;
}

struct node *mergesort(struct node *p){
	struct node *n=p;
	struct node *t,*f;
	while(p->n && p->n->v > p->v){
		p=p->n;
	}
	if(p->n){		
		f=p->n;
		p->n=NULL;
		p=f;
		while(p){
			while(p->n && p->n->v > p->v){
			p=p->n;
			}
			if(p){
				t=p->n;
				p->n=NULL;
				n=merge(n,f);
				f=t;
				p=t;
			}
		}
	}
	return n;
}

int main(){
struct node* p = init();
int n;
scanf("%i", &n);
int i;
int a;
for (i=1;i<=n;i++){
    scanf("%i", &a);
    add(&p,a);
    }  
 
p=mergesort(p);
                     
writy(p);               
 
return 0;   
}