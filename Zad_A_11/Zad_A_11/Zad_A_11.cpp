// Zad_A_11.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

//_CRT_SECURE_NO_WARNINGS

using namespace std;

/*
((x >= 65) && (x <= 90))     male litery  (65-90) [A-Z]
((x >= 97) && (x <= 122))    wielkie litery (97-122) [a-z]
(((x >= 48) && (x <= 57)))   cyfry (48 57) [0..9]

funkcja spr czy znak jest z zakresu
*/

/*
sprCzyLiteraCyfra:
Result 1 - cyfra
Result 2 - litera mala
Result 3 - litera wielka
Reselt !(123) - inny znak
*/
int sprCzyLiteraCyfra(int x)
{

	if ((x >= 65) && (x <= 90)) //male litery
		return 2;
	else
	{
		if ((x >= 97) && (x <= 122)) // wielkie litery
			return 3;
		else
		{
			if ((x >= 48) && (x <= 57)) //cyfry
				return 1;
			else
				return 0;
		}
	}


}




int wczytaj(char *tab1)
{
	int t = 0;
	int liczbaZnakow;
	scanf("%i", &liczbaZnakow);
	return liczbaZnakow;
}


int wypisz(int *tab1, int liczbaZnakow)
{
	int znak;
	for (int i = 0; i < liczbaZnakow; i++)
	{
		znak = tab1[i];
		printf("%i ", znak);
	}
	return 0;
}


int odwroc(char *tab1, char *tab2, int ilosc)
{
	for (int i = 0; i < ilosc; i++)
	{
		tab2[i] = tab1[ilosc - i - 1];
	}

	return 0;
}


int alokuj(int liczba)
{
	int *tab = new int[liczba];
	return 0;
}

int wypelnij(int *tab, int liczba)
{
	int kkk = 0;
	for (int i = 0; i < liczba; i++)
	{
		*(tab + i) = liczba - i;
		kkk = *(tab + i);
	}
	return 0;
}


int main(int argc, char *argv[])

{
	int liczbaZnakow = 0;

	while (scanf("%i", &liczbaZnakow) > -1)
	{

		int *tab = new int[liczbaZnakow];

		//alokuj
		alokuj(liczbaZnakow);

		//wypelnij
		wypelnij(tab, liczbaZnakow);

		wypisz(tab, liczbaZnakow);
		
		printf("\n");

		//kasowanie tab[]

	}

	system("PAUSE");
	return 0;
}


