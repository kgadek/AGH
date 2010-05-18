#include<stdio.h>
#include<iostream>
const int n=10;
int t[n];
int tab2[n];


void insertionsort(int *tab)
{int i;
     for(i=1; i<=n-1; i++)
     {
             int key=tab[i];
             int j=i-1;
             while (j>=0 && tab[j]>key)
             {
                   tab[j+1]=tab[j];
                   j--;
             }
             tab[j+1]=key;
     }
}



void selectionsort(int* tab)
{
     int temp, i, j;
     for (i=0;i<n;i++) 
     { 
         int m=i;  
         for (j=i+1;j<n;j++) 
         {
             if (tab[j]<tab[m]) m=j;
             }
         temp=tab[i]; 
         tab[i]=tab[m];
         tab[m]=temp;
         }
         }
void bubblesort(int * tab)
     {
                    int i,j,temp;
                    for(i=1;i<=n;i++)
                         for(j=i;j>0;j--)
                         {
                             if (tab[j-1]>tab[j])
                             {
                                temp=tab[j-1];
                                tab[j-1]=tab[j];
                                tab[j]=temp;
                                }
                         }
     }                 
              

void shellsort(int *tab)
     {
                   const int gaps[]={1,3,4,6,20,40,400,670};
                   int gap,i,j,a,k;
                   for (a=6;a>=0;a--)
                   {
                       gap=gaps[a];
                       for (i=gap;i<n;i++)
                       {
                           k=tab[i];
                           j=i-gap;
                           while   (j>=0 && tab[j]>k) 
                           {
                                   tab[j+gap]=tab[j];
                                   j-=gap;
                                   }
                           tab[j+gap]=k;
                           }
                           }
                           } 
                                
                                
void combsort(int *tab)
     {
                  int gap,i,temp;
                  gap=n;
                  int swap=1;
                  while(gap>1 || swap)
                  {
                              swap=0;
                              gap=gap*10/13;
                              if(gap==9 || gap==10) gap=11;
                              if(gap==0) gap==1;
                              for (i=0;i<n-gap;i++)
                                  {
                                  if (tab[i]>tab[i+gap])
                                  {
                                      swap=1;
                                      temp=tab[i];
                                      tab[i]=tab[i+gap];
                                      tab[i+gap]=temp;
                                      }
                                      }
                  }
     } 
      
void merge(int *tab, int l, int m, int h)
     {
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
         for (z=0; z<h-l+1;z++) tab[l+z]=tab2[z];
         }
void mergesort(int *tab, int l, int h)
     {int m;
                   if (l<h)
                   {
                           m=(h+l)/2;
                           mergesort(tab,l,m);
                           mergesort(tab,m+1,h);
                           merge(tab,l,m,h);
                           }
                           }
                           
                           
void heapify(int i, int max)
     {
                 int l=2*i+1;
                 int r=2*i+2;
                 int maxi,temp;
                 if (l<max && t[l]>t[i])
                           maxi=l;
                 else
                     maxi=i;
                 if (r<max && t[r]>t[i])
                           maxi=r;
                 if (maxi !=i)
                 {
                          temp=t[i];
                          t[i]=t[maxi];
                          t[maxi]=temp;
                          heapify(maxi,max);
                          }
                          }
void buildheap()
     {
                   int i;
                   for (i=n/2-1;i>=0;i--)heapify(i,n);
     }

void heapsort()
     {
                  int i,temp;
                  buildheap();
                  for (i=n-1;i>0;i--){
                      temp=t[0];
                      t[0]=t[i];
                      t[i]=temp;
                      heapify(0,i);
                      }
                      }
                                              
int main()
{ int i;
/*FILE *plik;
FILE *plik2;
     plik2=fopen("posortowane.txt","w+");
      plik=fopen("dane","r");
    for (i=0;i<=n-1;i++) fscanf(plik,"%i",t+i);
    fclose(plik);*/
   //insertionsort(t);
   //selectionsort(t);
  for (i=0;i<n;i++) scanf("%i ",t+i);     //wpisywanie
   //bubblesort(t);
   //shellsort(t);
   //combsort(t);
   //mergesort(t,0,n-1);
   heapsort();
   for (i=0;i<n;i++)
            //fprintf(plik2,"%i ",t[i]);
            printf("%i ",t[i]);
            //fclose(plik2);
    getchar();
    getchar();
    system("pause");
}
            
