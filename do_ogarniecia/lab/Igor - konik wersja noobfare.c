#include<stdio.h>

int sprawdz_pozycje(int** tab, int x, int y, int size)
{
	if(x<0 || y<0 || x>=size || y>=size) return 0;
	if(tab[x][y]!=0) return 0;
	return 1;
}

int konik(int** tab,int x,int y, int liczba, int size)
{
	if(sprawdz_pozycje(tab,x,y,size)==0) return 0;
	
	tab[x][y]=liczba;
	
	if(liczba==size*size) return 1;
	
	if(konik(tab,x+1,y-2,liczba+1,size)==0)
		if(konik(tab,x+2,y-1,liczba+1,size)==0)
			if(konik(tab,x+1,y+2,liczba+1,size)==0)
				if(konik(tab,x+2,y+2,liczba+1,size)==0)
					if(konik(tab,x-1,y-2,liczba+1,size)==0)
						if(konik(tab,x-2,y-1,liczba+1,size)==0)
							if(konik(tab,x-1,y+2,liczba+1,size)==0)
								if(konik(tab,x-2,y+1,liczba+1,size)==0)
									{
									tab[x][y]=0;
									return 0;
									}
	return 1;
}


int main()
{
	int **tab;
	int n,i,j;
	scanf("%i",&n);
	tab=(int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
		tab[i]=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			tab[i][j]=0;
	if(konik(tab,0,0,1,n)==1)
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
						printf("%4i",tab[i][j]);
				printf("\n");
			}
	else printf("ble\n");
	system("pause");
}
			
