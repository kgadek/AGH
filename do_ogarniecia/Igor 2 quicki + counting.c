#include<stdio.h>
const int n=50;
int t[n];

void quickhoare(int *tab,int l,int p)
{
     int i,j,pivot,temp;
     i=l;
     j=p;
     pivot=tab[(l+p)/2];
     do
     {
               while(tab[i]<pivot) i++;
               while(tab[j]>pivot) j--;
               if (i<=j){
                         temp=tab[i];
                         tab[i]=tab[j];
                         tab[j]=temp;
                         i++;
                         j--;
                         }
               }while (i<j);
               if(j>l)
               quickhoare(tab,l,j);
               if(i<p)
               quickhoare(tab,i,p);
               }
               
void quicklemuto(int *tab,int l,int p)
{
     int i,j,pivot,temp;
     pivot=tab[p];
     j=l;
     i=l-1;
     for (j=l;j<p;j++){
           if(tab[j]<=pivot){
                             i++;
                   temp=tab[i];
                   tab[i]=tab[j];
                   tab[j]=temp;
                   }
                   }
                   i++;
                   temp=tab[i];
                   tab[p]=tab[i];
                   tab[i]=temp;
                   
                   if(l<i-1)quicklemuto(tab,l,i-1);
                   if(i+1<p)quicklemuto(tab,i+1,p);          
}


void countingsort(int *tab)
{int tab2[999],i,temptab[n];
for(i=0;i<998;i++)tab2[i]=0;
for(i=0;i<n;i++)tab2[tab[i]]+=1;
for(i=1;i<998;i++)tab2[i]+=tab2[i-1];
for(i=n-1;i>=0;i--)
{
                   temptab[tab2[tab[i]]-1]=tab[i];
                   tab2[tab[i]]--;
                   }
for(i=0;i<n;i++)tab[i]=temptab[i];
}
     




int main()
{
int i;
FILE *plik;
FILE *plik2;
     plik2=fopen("posortowane2.txt","w+");
      plik=fopen("dane","r");
    for (i=0;i<=n-1;i++) fscanf(plik,"%i",t+i);
    fclose(plik);
    //quickhoare(t,0,n-1);
    //quicklemuto(t,0,n-1);
    countingsort(t);
     for (i=0;i<=n;i++)
         //printf("%i ",t[i]);
         fprintf(plik2,"%i ",t[i]);
     fclose(plik2);
    getchar();
    getchar();
    getchar();
}
