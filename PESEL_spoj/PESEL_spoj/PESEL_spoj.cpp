// PESEL_spoj.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>


int main(int argc, char *argv[])

{
	int iloscPesel;
	char PESEL[11];
	int zestaw[11] = { 9,7,3,1,9,7,3,1,9,7,9 };
	int liczba;
	int sum = 0;
	int suma = 0;

	scanf("%i", &iloscPesel);
	liczba = iloscPesel;
	for (int i = 0; i < liczba;  i++)
	{
		scanf("%11s", PESEL);
		/*
		if (PESEL[0]== '\0')
		{
			return 0;
		}
		*/
		suma = 0;
		for (int k = 0; k < 11; k++)
		{
			sum = (PESEL[k] - 48);
			suma += (PESEL[k] - 48) * zestaw[k];
			//printf("%c",PESEL[k]);
		}
		if ((suma % 10 == 0) && (sum != 0))
			printf("D\n");
		else
			printf("N\n");

	}
	return 0;
}


