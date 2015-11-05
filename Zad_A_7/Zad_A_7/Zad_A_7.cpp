// Zad_A_7.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

//_CRT_SECURE_NO_WARNINGS

/*
((x >= 65) && (x <= 90))     male litery  (65-90) [A-Z]
((x >= 97) && (x <= 122))    wielkie litery (97-122) [a-z]
(((x >= 48) && (x <= 57)))   cyfry (48 57) [0..9]

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


	/*/
	printf("\n");
	printf("Program wyswietla ilosc liter i cyfr w tekscie\n");
	printf("\n");
	*/


	//wczytanie ilosci zestawow
	scanf("%i", &petla);

	for (int k = 0; k < petla; k++)
	{


		scanf("%30s", tekst);
		int x;

		for (int i = 0; i < 30; i++)
		{
			znak = tekst[i];
			//printf("%c ", znak);

			x = tekst[i];

			if ((i + 1) % 2 == 0)
			{
				if (((x >= 48) && (x <= 57)))
				{
				}
				else
				{
					if (sprCzyLitera(x))
					{
						printf("%c", znak);
					}
					else
					{
						break;
					}
				}
			}

		}
		printf("\n");

	}
	return 0;
}
