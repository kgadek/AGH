#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randomize(float *tab, int n)
{
    int i;
    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++)
	tab[i] = (float)(((rand() % RAND_MAX) / (RAND_MAX + 0.0)) * 20 - 10);
}

void insertionsort(float *tab, int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
	j = i - 1;
	key = tab[i];
	while (j >= 0 && key < tab[j]) {
	    tab[j + 1] = tab[j];
	    j--;
	}
	tab[j + 1] = key;
    }
}

int main()
{
    int n;
    float *tab;
    int i;
    scanf("%i", &n);
    tab = (float*)malloc((unsigned int)n*sizeof(float));
    randomize(tab, n);
    for (i = 0; i < n; i++)
	printf("%f ", tab[i]);
    printf("\n\n");
    insertionsort(tab, n);
    for (i = 0; i < n; i++)
	printf("%f ", tab[i]);
    free(tab);
    return 0;
}
