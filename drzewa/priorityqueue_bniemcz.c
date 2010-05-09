#include <stdio.h>
#define MAX 20
int max = 10;

void heap(int i, int A[])
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxi, t;
    if (l < max && A[l] > A[i])	/* szukamy maximum */
	maxi = l;
    else
	maxi = i;
    if (r < max && A[r] > A[maxi])
	maxi = r;
    if (maxi != i) {		/*zamiana miejsc, najwiekszy idzie na poczatek kolejki */
	t = A[i];
	A[i] = A[maxi];
	A[maxi] = t;
	heap(maxi, A);
    }
}

void heap_build(int A[])
{
    int i;
    for (i = max / 2 - 1; i >= 0; i--)
	heap(i, A);
}

void put(int el, int A[])
{
    if (max + 1 > MAX);		/*error - brak pamięci */
    else {
	int i = max++;
	while (i > 0 && A[(i - 1) / 2] < el) {
	    A[i] = A[(i - 1) / 2];
	    i = (i - 1) / 2;
	}
	A[i] = el;
    }
}


int get(int A[])
{
    int tmp;			/*maksymlana wartość */
    if (!max)
	return 0;		/* error - brak elementów */
    else {
	tmp = A[0];
	A[0] = A[--max];
	heap(0, A);
	return tmp;
    }
}

int main()
{
    int A[MAX] = { 4, 5, 2, 1, 0, 6, 9, 8, 3, 7 };
    int i;
    heap_build(A);		/*tworzenie kopca */

    /*wypisanie kopca */
    for (i = 0; i < max; i++)
	printf("%d ", A[i]);
    printf("\n");

    put(-10, A);
    put(5, A);
    put(0, A);
    put(3, A);

    for (i = 0; i < max; i++)
	printf("%d ", A[i]);
    printf("\n");

    while (max)
	printf("%d ", get(A));


    return 0;
}
