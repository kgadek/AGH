/* Skiplista klasyczna v1.1a ("płointer na płointer") - Michał Idzik, patched by p4r4oj4*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max 16                         /*Maskymalna wysokość listy*/                     
typedef struct skipwezel                                     /*Podstawowy element skiplisty:*/
                        { int key;                           /*Jakiś tam klucz*/                   
                          int h;                            /*Wysokość węzła*/
                          struct skipwezel ** next;     /*Kolejna kolumna skiplisty*/
                          } * skipw;

typedef struct skiphead                                     /*Wygodne oddzielenie głowy od reszty*/
                       { int h;                             /*Obecna wysokość całej skiplisty*/
                         skipw head;                        /*Wskaźnik na pustą głowę- uwaga, ona nie ma klucza!*/
                         } * skiph;


int los()                    /*Prymitywna funkcja losująca- chcesz lepszą? Spytaj Radka*/
{int i=1, r=RAND_MAX/2;
  
   while(i<max && rand()<r) i++; /*Powiedzmy że to losuje z p-stwem 1/2...*/
return i;                        /*... a w każdym razie zwraca wysokość z zakresu [1,max] */
}

int find(skiph head, int key) /*Szukajka*/
{ skipw p=head->head;  /*Ustawiamy się na głowie*/
 int i;
    for(i=head->h-1; i>=0; i--) /*Szukamy na kolejnych poziomach*/
     { while (p->next[i] && p->next[i]->key<key) p=p->next[i]; /*Przesuwamy się po "wierszu" listy, dopóki nie znajdziemy większego lub równego el.*/
        if(p->next[i] && p->next[i]->key==key) return 1; } /*Gdy już znaleźliśmy, kończymy, jeśli nie- o poziom w dół, ale od tego samego miejsca w wierszu*/
return 0;
} 


skiph insert(skiph head, int key) /*Wstawianie elementu, czyli gwóźdź programu*/
{ /*------------Definiowanie nowego elementu-------------*/
  skipw dodaj_mnie=(skipw)malloc(sizeof(struct skipwezel)); 
  dodaj_mnie->h=los();
  dodaj_mnie->key=key;
 

if(dodaj_mnie->h > head->h) dodaj_mnie->h=++head->h;                         /*Gdy wysokość nowonarodzonego elementu jest większa, przycynamy i zwiększamy też wysokość listy*/
 dodaj_mnie->next=(skipw*)malloc(dodaj_mnie->h*sizeof(skipw));    /*alokujemy dynamicznie kolumnę dla nowego elementu*/
/*-------------------------------------------------------*/
skipw p=head->head;
 int i;
   for(i=head->h-1; i>=0; i--) 
   {
     while (p->next[i] && p->next[i]->key<key) p=p->next[i]; /*Czynności analogiczne jak przy find*/
     
     if(i<dodaj_mnie->h) {   /*Gdy zejdziemy na odpowiednią wysokość, zaczynamy wpinanie (na każdym kolejnym niższym poziomie też)*/
     dodaj_mnie->next[i]=p->next[i];
     p->next[i]=dodaj_mnie; } 
   }
 
 return head; /*Zwracamy nową głowę*/
}   

skiph del(skiph head, int key) /*Destrukcja!*/
{ if(!find(head,key)) return head; /*Gdy chcemy usunąć coś, czego nie ma. Niepotrzebne w sumie*/

else 
{ 
     
skipw p=head->head; 
        int q=0,i=head->h-1;
while(i>=0 && !q)                                           /*Jedziemy tak jak zwykle, zatrzymujemy się gdy znajdziemy najwyższy rząd gdzie element występuje.*/
  { while(p->next[i] && p->next[i]->key<key) p=p->next[i];  /*W celu usprawnienia, można pogmerać trochę w find tak by zwracało od razu adres pierwszego wystąpienia*/
      if (p->next[i] && p->next[i]->key==key) q=1;          /*Ale szczerze mówiąc nie chce mi się*/
      else
      i--;
  }
 
skipw t=p->next[i]; /*Pamiętamy adres elementu (stały dla wszystkich rzędów) i przepinamy wszystko co trzeba*/
while(i>=0) { while(p->next[i] && p->next[i]->key<key) p=p->next[i];
              p->next[i]=p->next[i]->next[i];   
                        
              i--; }
 free(t); /*Naciskamy czerwony guziczek*/
if(head->head->next[head->h-1]==NULL) --head->h; /*Nic się z tego zrozumieć może nie da, ale można wierzyć na słowo,*/ 
return head; }                                   /* że zmniejsza wysokość całej listy, gdy usuwany element był jedynym najwyższym*/
}


void wypisz(skiph head, int n) /*Średnio praktyczne, bajeranckie wypisywanie, którego nie będę komentował*/
{ skipw p,q;

 int i,j;

     for(i=head->h-1; i>=0; i--) {
      j=1; p=q=head->head;
      while(j++<=n) {
       if(p->next[i] && p->next[i]->key==q->next[0]->key) 
         {printf("%3d",p->next[i]->key); p=p->next[i]; }
       
       else printf("---");
       
       q=q->next[0];
       }
   printf("\n");
   }   
}



int main()
{ int i,a,n;
/*-------Inicjowanie skiplisty-----------------*/
  skiph skiplist=(skiph)malloc(sizeof(struct skiphead));
  skiplist->head=(skipw)malloc(sizeof(struct skipwezel));
  skiplist->head->next=(skipw*)malloc(max*sizeof(skipw));
for(i=max-1; i>=0; i--)  skiplist->head->next[i]=NULL;
  skiplist->h=0;
/*---------------------------------------------*/
  
printf("Ile liczb?\n"); 
 scanf("%d",&n);
printf("Podaj zatem %d roznych liczb z zakresu 0-99\n",n);
 for(i=0; i<n; i++) { scanf("%d",&a);
                      skiplist=insert(skiplist,a);
                      }
printf("Gotowa lista:\n");
 wypisz(skiplist,n);
 
 printf("\nPodaj liczbe do wyszukania\n");
 scanf("%d",&a); 
 printf("%d %s\n",a,(find(skiplist,a))?"Jest na liscie":"Ni mo."); 
 
 printf("\nPodaj liczbe do usniecia\n");
 scanf("%d",&a); 
 skiplist=del(skiplist,a);
 printf("Po usunieciu %d:\n",a);
 wypisz(skiplist,n-1);

 return 0;
 
}
