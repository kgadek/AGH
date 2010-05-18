#include <stdio.h>

#define testuj(typ,przyklad,wywolanie)\
printf("NAZWA TYPU: " #typ "\nROZMIAR: %i B\n", sizeof(typ));\
typ temp##wywolanie = przyklad;\
p = (char *) &temp##wywolanie;\
printf("PRZYKLADOWA WARTOSC: " #przyklad "\nZAPIS DWOJKOWY W PAMIECI: ");\
binaryzuj(p,sizeof(typ));\
printf("\n\n")

int temp;

void wypisz(unsigned char x, int n){
if(n<=8){
	wypisz(x/2,n+1);
	printf("%i",x%2);
	}
}

void binaryzuj(unsigned char *p, int size){
int i;
for(i=1;i<=size;i++){
	wypisz(*p,1);
	p++;
	}
}

void testuj_typy(void){
unsigned char *p;
printf("\n\nRozpoczynam testowanie typów prostych...\n\n");
testuj(short int,-11,1);
testuj(unsigned short int,11,2);
testuj(int,-12345,3);
testuj(unsigned int,12345,4);
testuj(long int,-98765,5);
testuj(unsigned long int,98765,6);
testuj(char,'A',7);
testuj(unsigned char,'A',8);
testuj(float,-1.5,9);
testuj(double,123.456,10);
testuj(long double,-123.456,11);
}

int main(void){
int zmienna = 11;
unsigned char *p = (char *) &zmienna;
binaryzuj(p,sizeof(zmienna));
testuj_typy();
return 0;
}