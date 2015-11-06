// Zad_A_10.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
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




//do zrobienia f-cja wczytaj
int wczytaj ()
{

	return 0;
}

//do zrobienia f-cja wypisz
int wypisz()
{

	return 0;
}

//do zrobienia f-cja odwroc 
int odwroc()
{

	return 0;
}


int main(int argc, char *argv[])

{
	int petla=0;
	char znak;
	char tab1[31];
	char tab2[31];
	int liczbaZnakow=0;

	/*
	printf("\n");
	printf("Program wyswietla ilosc liter i cyfr w tekscie\n");
	printf("\n");
	*/


	//wczytanie ilosci zestawow
	scanf("%i", &petla);

	int x=0;
	int y = 0;
	int i = 0;
	for (int k = 0; k < petla; k++)
	{

		
		scanf("%30s", tab1);
		

		//drugi znak
		znak = tab1[1];
		x = znak;
		//pierwszy znak
		znak = tab1[0];
		y = znak;
	



		//spr. czy drugi znak tekstu to cyfra, aby odczytac liczbe znakow w tekscie 
		if (sprCzyLiteraCyfra(x) == 1)
		{
			liczbaZnakow = 10 * (y-48) + x-48;
			i = 1;
		}
		else
		{
			liczbaZnakow = y-48;
		}

		//




		int b = 0;
		for (int m = i+1; m < liczbaZnakow + 1 + i; m++)
		{
			//
			znak = tab1[m];
			tab2[liczbaZnakow - b -1] = tab1[m];
			//printf("%1c", znak);
			b++;
		}
		
		//printf("\n");
		

		
		for (int n = 0; n < liczbaZnakow ; n++)
		{
			printf("%1c",tab2[n]);
		}







		printf("\n");

	}
	return 0;
}
