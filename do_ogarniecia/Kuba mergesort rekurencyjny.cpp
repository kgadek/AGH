#include <iostream>
 
using namespace std;
 
int n=10;
int tab[]={2,4,2,3,7,4,9,1,6,9};
 
void merge(int *tab, int l, int m, int h)
     {
                     int* tab2;
                     tab2=new int[n];
                     int i=l,j=m+1,p=0;
                     while (i<=m && j<=h)
                     {
                           if(tab[i]<tab[j])
                           {tab2[p]=tab[i];
                           p++; i++;
                           }
                           else {
                                tab2[p]=tab[j];
                                p++;j++;
                                }
                                }
     int z;
     for (z=i;z<=m;z++){
         tab2[p]=tab[z];
         p++;}
     for (z=j;z<=h;z++){
         tab2[p]=tab[z];
         p++;
         }
     for (z=0;z<h-l+1;z++) tab[l+z]=tab2[z];
     delete[] tab2;
         }
void mergesort(int *tab,int l, int h)
     {int m;
                   if (l<h)
                   {
                           m=(h+l)/2;
                           mergesort(tab,l,m);
                           mergesort(tab,m+1,h);
                           merge(tab,l,m,h);
                           }
                           }
int main()
{
   mergesort(tab,0,n-1);

   for (int a=0;a<n;++a) cout<<tab[a]<<"\t";
   getchar();
   return 0;
}
