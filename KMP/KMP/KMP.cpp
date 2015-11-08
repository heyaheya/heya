#include "stdafx.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */




int sprCzyZakres(int x)
{
	
	if (((x > 64) && (x < 91)) || ((x>96) && (x < 123)))	
		return 1;
	else
		return 0;
}


int main(int argc, char *argv[])

{
	//zrobiæ przez stworzenie tablicy dynamicznej - f-cja malloc wyk³ad cpp str 89

	int iloscZadan;
	size_t wzorzec1;
	char *wzorzecP;
	char *zestawZnakow;
	int g = 1;
	char znak;
	int iloscZnakow;
	int wzorzec = 0;

	scanf("%i", &iloscZadan);
	
	for (int i = 0; i < iloscZadan; i++)
	{
		scanf("%i", &wzorzec);
		wzorzec1 = wzorzec;
		wzorzecP = (char*)malloc(wzorzec1 * sizeof(char));
		
		scanf("%c", &znak);

		for (int d = 0; d < wzorzec; d++)
		{
			scanf("%c", &znak);
			wzorzecP[d] = znak;
		}

		zestawZnakow = (char*)malloc(1 * sizeof(char));
		g = 0;

		scanf("%c", &znak);
		int wynik = 0;
		
		do
		{
			wynik = (scanf("%c", &znak));

			if ((znak == 10) || (wynik < 0))
			{
				wynik = -1;
			}
			else
			{

				if (g != 0)
				{
					zestawZnakow = (char*)realloc(zestawZnakow, (g + 1) * sizeof(char));
				}

				//*(zestawZnakow + g) = znak;
				zestawZnakow[g] = znak;

				g++;

			}
		} while (wynik>0);
		
		

		iloscZnakow = wzorzec;


		for (int k = 0; k < g; k++) //petla po ilosci spr
		{
			for (int j = 0; j < iloscZnakow; j++)
			{
				if (((wzorzecP[j] == zestawZnakow[k + j]))) // && (sprCzyZakres(zestawZnakow[k + j])==1))
				{
					if (j == iloscZnakow -1)
						printf("%i\n", k);
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}


