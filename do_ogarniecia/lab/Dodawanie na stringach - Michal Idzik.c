#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dodaj(char * a, char *b)
{ int l1=strlen(a), l2=strlen(b),  x=abs(l1-l2), max=l1, r=0, w,i;
  char *p, tp[2];
  
   if(x) {
  p=(char*)malloc((unsigned int) (x+1)*sizeof(char));
     for(i=0; i<x; i++) p[i]='0'; 
     p[x]='\0';
     
     if(l1>l2) {strcat(p,b); b=p; }
        else {strcat(p,a); a=p; max=l2; }
        
        }
 
  char* wynik=(char*)malloc((unsigned int) (max+1)*sizeof(char));
  wynik[max]='\0';
  for(i=max-1; i>=0; i--)
   { w=a[i]+b[i]-2*'0'+r;
     r=w/10;
     wynik[i]=w%10+'0';
   }
   
if(r) {tp[0]=r+'0'; tp[1]='\0'; strcat(tp,wynik); wynik=tp; }

printf("%s\n",wynik);
}

int main()
{ char a[255], b[255];
  int i;
  
  scanf("%s %s",a,b);
  
  dodaj(a,b);
  
return 0;
}
  
