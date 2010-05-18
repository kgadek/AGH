#include<stdio.h>
/* kopcowanie! */
#define m 8
typedef struct pom { int k,i;} pom;
int mniejszy(pom a, pom b)
{ return (a.k<b.k || (a.k==b.k && a.i<b.i)); }

void heapify(pom * T, int max, int i)
{ int left=2*i+1;
  int right=2*i+2;
   int k=i;
    if (left<max && mniejszy(T[i],T[left]))
       k=left;
    if (right<max && mniejszy(T[k],T[right]))
       k=right;
    
    if (k!=i)
    {pom temp=T[i];
       T[i]=T[k];
       T[k]=temp;
      heapify(T,max,k);
      }
}

void buildheap(pom * T)
{ int i;
  for(i=m/2-1; i>=0; i--)
    heapify(T,m,i);
}

void heapsort(int T[])
{ int i;
  pom tp[m];
  for(i=0;i<m;i++) {tp[i].k=T[i]; tp[i].i=i;}
     buildheap(tp);
  for(i=m-1; i>0; i--)
    {pom temp=tp[i];
       tp[i]=tp[0];
       tp[0]=temp;
    heapify(tp,i,0);}
 for (i=0;i<m;i++) {T[i]=tp[i].k; printf("%d ",tp[i].i); }
 printf("\n");
 }
int main()
{int i,T[m]; 
    for(i=0; i<m; i++)
      scanf("%d",&T[i]);
heapsort(T);

for(i=0; i<m; i++)
      printf("%d ",T[i]);
      printf("\n"); 
return 0;
}
