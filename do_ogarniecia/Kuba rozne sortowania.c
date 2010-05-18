#include <stdio.h>

const int N=10000;


void czytajDane(FILE* pfile,int* ptab)
{
	pfile=fopen("dane","r");
	int i;
	for (i=1;i<=N;i++) fscanf(pfile,"%i",&ptab[i]);
	fclose(pfile);
}

char* ShellSort (int* ptab)
{
	const int gaps[]={1,4,13,40,121,364,1093,3280,9841};
	int a,gap,i,j,x;
	for (a=8;a>=0;--a) {
		gap=gaps[a];
		for (i=gap;i<N+1;++i) {
			x=ptab[i];
			for (j=i-gap;j>0 && ptab[j]>x;j-=gap) ptab[j+gap]=ptab[j];
			ptab[j+gap]=x;
		}
	}
	return "posortowane ShellSortem";
}		

char* CombSort (int* ptab)
{
	int gap=N;
	int swapped=1,i,temp;
	while ( gap>1 || swapped) {
		gap=(gap*10)/13;
		if (gap==9 || gap==10) gap=11;
		if (gap==0) gap=1;
		swapped=0;
		for (i=1;i<N+1-gap;++i)
			if (ptab[i]>ptab[i+gap]) {
				temp=ptab[i];
				ptab[i]=ptab[i+gap];
				ptab[i+gap]=temp;
				swapped=1;
			}
	}
	return "posortowane CombSortem11";
}

char* InsertionSort (int* ptab) 
{
      int a=2;	
      for (a;a<N+1;a++)
      {
          int klucz=ptab[a];
          ptab[0]=klucz; //wartownik
          int i=a;
          while (ptab[i-1]>klucz)
          {
                ptab[i]=ptab[i-1];
                i--;
          }
          ptab[i]=klucz;
      }
      return "posortowane InsertionSortem";
}

char* SelectionSort (int* ptab)
{
	int i,j,k,temp;
	for (i=1;i<N;i++)
	{
		k=i;
		for (j=i+1;j<=N;j++) if (ptab[j]<ptab[k]) k=j;
		temp=ptab[i];
		ptab[i]=ptab[k];
		ptab[k]=temp;
	}
	return "posortowane SelectionSortem";
}

char* BubbleSort (int* ptab)
{
	int i,j,temp;
	for (i=1;i<N;i++)
		for (j=N;j>1;j--)
			if (ptab[j]<ptab[j-1])
			{
				temp=ptab[j];
				ptab[j]=ptab[j-1];
				ptab[j-1]=temp;

			}
	return "posortowane BubbleSortem";
}	

main()
{
      int tablica[N+1]; // pierwszy element o indeksie 0 to wartownik!
      FILE* pfile;	
      czytajDane(pfile,tablica);	
      printf("%s\n",InsertionSort(tablica));
    //  printf("%s\n",SelectionSort(tablica));
    //  printf("%s\n",BubbleSort(tablica));
	//  printf("%s\n",ShellSort(tablica));
	//	printf("%s\n",CombSort(tablica));
      int a; 
      for (a=1;a<=N;a++) printf("%i ",tablica[a]);
      return 0;
}