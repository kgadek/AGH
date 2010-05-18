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

struct node* insort(struct node *p){
       struct node *f1, *f2, *w, *t;
       f1=p;
       f2=p->n;
       while (f2){
             t=f2->n;
             if(p->v > f2->v){
                      f1->n = f2->n;
                      f2->n = p;
                      p = f2;}
             else{
             w=p;                    
             while ((w->n->v)<(f2->v) && w->n!=f2){
                   w=w->n;
                   }
             if (w->n!=f2){
                      f1->n = f2->n;
                      f2->n = w->n;
                      w->n = f2;                
                }
                else {f1=f2;}
                }         
                f2=t;
             }                    
       return p;
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

p=insort(p);
                     
writy(p);               

return 0;   
}