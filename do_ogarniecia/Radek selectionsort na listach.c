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

struct node *selsort(struct node *p){
	struct node *n=init();
	struct node *f,*max,*maxp;
	while(p){
		f=p;
		max=p;
		while(f->n){
			if((f->n->v) > (max->v)){
				maxp=f;
				max=f->n;
			}
			f=f->n;
		}
		if(max==p){
			p=p->n;
			max->n=n;
			n=max;
		}
		else{
			maxp->n=max->n;
			max->n=n;
			n=max;
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
 
p=selsort(p);
                     
writy(p);               
 
return 0;   
}