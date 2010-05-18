#include<stdio.h>

int a[8]={2,1,-1,-2,-2,-1,1,2},
    b[8]={1,2,2,1,-1,-2,-2,-1};

void licz(int* R, int **T,int x,int y, int n)
{  int u,v,i,j;
     for(j=0; j<8; j++)
   {    u=x+a[j]; v=y+b[j]; R[j]=0;
     if(u>=0 && u<n && v>=0 && v<n && !T[u][v])
      for(i=0; i<8; i++)
       
       if(u+a[i]>=0 && u+a[i]<n && v+b[i]>=0 && v+b[i]<n && !T[u+a[i]][v+b[i]])
        { R[j]++; /*printf("%d %d %d\n",u+a[i],v+b[i],T[u+a[i]][v+b[i]]); */}
      
   }
}

int min(int *R)
{ int min_i=-1, min_val=9,i;
    for(i=0;i<8;i++)
   if(R[i] && R[i]<min_val) {min_val=R[i]; min_i=i;}

return min_i;
}
   
int konik(int **T, int i, int x, int y,int n)
{ int R[8],k=8,m,mx,my,l;
   licz(R,T,x,y,n);
   
  while(k--)
  { 
    m=min(R);
  if(m>=0 && i<n*n){ mx=x+a[m]; my=y+b[m];
           T[mx][my]=i; /*printf("Zapisuje (%d,%d): %d\n",mx,my,T[mx][my]);*/
           
           
             if(!konik(T,i+1,mx,my,n)) 
             {
             T[mx][my]=0; R[m]=0; }
             /*printf("Odpisuje (%d,%d): %d\n",mx,my,T[mx][my]);*/
             else return 1; 
             }
  
  else if(i<n*n) return 0; else { for(l=0; l<8; l++) 
   if(x+a[l]>=0 && x+a[l]<n && y+b[l]>=0 && y+b[l]<n && !T[x+a[l]][y+b[l]])
     {T[x+a[l]][y+b[l]]=i; return 1;} }
  }
  return 0;
}
    
    
int main()
{ int n,i,j;
    scanf("%d",&n);
 
   int **T=(int**)malloc(n*sizeof(int*));
   for(i=0; i<n; i++) T[i]=(int*)malloc(n*sizeof(int)); 
                      
   for(i=0; i<n; i++)
            for(j=0; j<n; j++)
              T[i][j]=0;
              
T[0][0]=1; 
/*int R[8];
licz(R,T,2,4,n);
for(i=0; i<8; i++) printf("%d ",R[i]);

printf("\n%i\n",min(R));*/
if(konik(T,2,0,0,n)) 
 for(i=0; i<n; i++){
            for(j=0; j<n; j++)
              printf("%3d ",T[i][j]);
            printf("\n");
            }
   else printf("pff..\n");  
return 0;
}
     
    
