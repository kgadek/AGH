#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char* argv[])
{

	/* pomocnicze zmienne */
	int i,szukana_litera,c;

	/* zmienne zliczajace dla pojedynczego plik */
	int linie, slowa, znaki, litera;

	/*zmienne zliczające dla wszystkich plików */
	int zbiorcze_linie, zbiorcze_slowa, zbiorcze_znaki, zbiorcza_litera;

	/*zmienna sprawdzająca, czy podano opcję -f*/
	char sprawdzac_litere='N';

	/*zmienna sprawdzająca, czy znajdujemy się w środku wyrazu*/
	char wyraz='N';
	FILE* plik;

	/*sprawdzenie, czy podano jakiekolwiek argumenty*/
	if (argc==1)
			{
					printf("Nie podano nazwy pliku do sprawdzenia\n");
					system("pause");
					return 0;
			}

	/*sprawdzenie, czy podano opcję -f */
	if(strcmp(argv[1],"-f")==0)
			{
					/*sprawdzenie, czy podano argument dla opcji -f*/
					if(argv[2])
						{
							szukana_litera=*argv[2];
							sprawdzac_litere='T';

							/*sprawdzenie, czy podano odpowiedni argument dla opcji -f*/
							if (*++argv[2])
									{
											printf("Nie podano pojedynczego znaku dla opcji -f\n");
											system("pause");
											return 0;
									}
						}
					else
						{
							printf("Nie podano argumentu dla opcji -f\n");
							system("pause");
							return 0;
						}
			}
	else
		if(*argv[1]=='-')
					{
							printf("Nieznana opcja dla polecenia wc\n");
							system("pause");
							return 0;
					}

	/*sprawdzenie, czy podano wystarczająco dużo argumentów, jeśli wywołano opcję -f*/
	if(sprawdzac_litere=='T')	
				{
						i=3;
						if(argc==3)
							{
									printf("Nie podano nazwy pliku do sprawdzenia\n");
									system("pause");
									return 0;
							}
				}
	else		i=1;
	zbiorcze_linie=zbiorcze_slowa=zbiorcze_znaki=zbiorcza_litera=0;
	while(i<argc)
				{
						plik=fopen(argv[i],"r");

						/*sprawdzenie czy podany plik istnieje*/
						if(!plik)
								{
									printf("Nie znaleziono pliku %s\n", argv[i]);
								}
						else
								{
									linie=znaki=slowa=litera=0;
									c=1;

									/*pętla zliczająca*/
									while(c!=EOF)
										{
												c=getc(plik);
												znaki++;
												if(sprawdzac_litere=='T' && c==szukana_litera) litera++;
												if(c=='\n')linie++;

												/* jeśli "c" będzie w słowie, to zajdzie warunek, jeśli będzie w nim po raz pierwszy to licznik słowa zwiększy się */
												if(!isspace(c) && c!=EOF) 
													{
														if (wyraz=='N')
															{	
																wyraz='T';
																slowa++;
															}
													}
												else wyraz='N';
										}

									/*dopisanie do zbiorczych liczników*/

									zbiorcze_linie+=linie;
									zbiorcze_slowa+=slowa;
									zbiorcze_znaki+=znaki;

									/*jeśli wywołano opcję -f, to doda do zbiorczego licznika danej litery oraz wypisze wc dla danego pliku */
									if(sprawdzac_litere=='T') 
											{
												zbiorcza_litera+=litera;
												printf("%6i  %6i  %6i  %6i   %s\n",linie, slowa, znaki, litera, argv[i]);
											}
									else

										/*wypisanie wc bez opcji -f dla danego pliku*/
											printf("%6i  %6i  %6i   %s\n",linie, slowa, znaki, argv[i]);
								}
						fclose(plik);
						i++;
				}

	/*wypisanie zbiorczych danych, jeśli zajdzie warunek to z opcja -f, w innym wypadku bez niej*/
	if(sprawdzac_litere=='T')
				printf("%6i  %6i  %6i  %6i\n",zbiorcze_linie, zbiorcze_slowa, zbiorcze_znaki, zbiorcza_litera);
	else
				printf("%6i  %6i  %6i\n",zbiorcze_linie, zbiorcze_slowa, zbiorcze_znaki);	
	system("pause");
	return 0;
}			
																																
												
								
					
									
			
