#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
const int max=5;
 
struct skipek{
    struct skipek** nexts;
    int data;
};
 
struct skipleb{
    struct skipek* head;
    int wzrost;
};
 
void init(struct skipleb* co){
    co->wzrost=0;
    co->head=(struct skipek*)malloc(sizeof(struct skipek));
    co->head->nexts=(struct skipek**)calloc(max,sizeof(struct skipek*));
    int i;
    for(i=max;i>0;i--) co->head->nexts[i-1]=NULL;
    }
    
struct skipleb insert(struct skipleb gdzie, int co){
    struct skipek* temp=(struct skipek*)malloc(sizeof(struct skipek));
    temp->data=co;
    int los=1;
    while( (rand()%2) && los<=gdzie.wzrost ) los++;
    if(los>max) los=max;
    if(los>gdzie.wzrost) gdzie.wzrost=los;
    temp->nexts=(struct skipek**)calloc(los,sizeof(struct skipek*));
    int i;
    struct skipek* p=gdzie.head;
    for(i=gdzie.wzrost-1;i>=0;i--){
        while(p->nexts[i] && p->nexts[i]->data<=co) p=p->nexts[i];
        if(i<=los-1){
            temp->nexts[i]=p->nexts[i];
            p->nexts[i]=temp;
            }
        }
    return gdzie;
}
 
struct skipleb del(int co, struct skipleb gdzie){
int i;
struct skipek* p=gdzie.head;
for(i=gdzie.wzrost-1;i>0;i--){
    while(p->nexts[i] && p->nexts[i]->data<co) p=p->nexts[i];
    if(p->nexts[i] && p->nexts[i]->data==co ) p->nexts[i]=p->nexts[i]->nexts[i];
    }
while(p->nexts[0] && p->nexts[0]->data!=co) p=p->nexts[0];
if(p->nexts[0]){
    struct skipek* temp=p->nexts[0];
    p->nexts[0]=p->nexts[0]->nexts[0];
    free(temp);
    }
if(!gdzie.head->nexts[gdzie.wzrost-1]) gdzie.wzrost--;
return gdzie;
}
    
void wypisz(struct skipleb co){
    int i;
    struct skipek* p;
    for(i=co.wzrost-1;i>=0;i--){
        p=co.head;
        while(p->nexts[i]){
            printf("(%i)->",p->nexts[i]->data);
            p=p->nexts[i];
            }
        printf("\n");
    }
}
    
int main(void){
    srand(time(0));
    struct skipleb a;
    init(&a);
    a=insert(a, 35);
    a=insert(a, 5);
    a=insert(a, 3);
    a=insert(a, -35);
    a=insert(a, 65);
    a=insert(a, 15);
    a=insert(a, 51);
    a=insert(a, 31);
    a=insert(a, 315);
    a=insert(a, 6511);
    a=insert(a, 0);
    a=insert(a, 50);
    a=insert(a, 30);
    a=insert(a, -305);
    a=insert(a, 605);
    wypisz(a);
    printf("\n");
    a=del(50,a);
    a=del(15,a);
    a=del(66,a);
    wypisz(a);
    return 0;
    }