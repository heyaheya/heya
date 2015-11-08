// Zad_A_6.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

//_CRT_SECURE_NO_WARNINGS

/*
65-90 [A-Z]
97-122 [a-z]
funkcja spr czy znak jest z zakresu
*/

int sprCzyLitera(int x)
{

	if (((x >= 65) && (x <= 90)) || ((x >= 97) && (x <= 122)))
		return 1;
	else
		return 0;
}



int main(int argc, char *argv[])

{
	int petla;
	char znak;
	char tekst[31];
	int iloscCyfr, iloscLiter;

	
	/*/
	printf("\n");
	printf("Program wyswietla ilosc liter i cyfr w tekscie\n");
	printf("\n");
	*/


	//wczytanie ilosci zestawow
	scanf("%i", &petla);

	for (int k = 0; k < petla; k++)
	{

		iloscCyfr = 0;
		iloscLiter = 0;

		scanf("%30s", tekst);
		int x;

		for (int i = 0; i < 30; i++)
		{
			znak = tekst[i];
			//printf("%c ", znak);

			x = tekst[i];
			if (((x >= 48) && (x <= 57)))
			{
				iloscCyfr++;
			}
			else
			{
				if (sprCzyLitera(x))
				{
					iloscLiter++;
				}
				else
				{
					break;
				}
			}

		}
		printf("%i %i\n", iloscLiter , iloscCyfr);

	}
	return 0;
}
