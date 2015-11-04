// Zad_A_5.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.,b
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

//_CRT_SECURE_NO_WARNINGS

int main(int argc, char *argv[])

{
	int petla; 
	char znak;
	char a, b;

	printf("\n");
	printf("Program wyswietla kolejne litery alfabetu w podanym przedziale.\n");
	printf("Podaj pierwsza i ostatnia litere zakresu - oddzielone spacjami:");

	//wczytanie ilosci zestawow
	scanf("%i", &petla);
	
	for (int k = 0; k < petla; k++)

	{
		scanf("%1s %1s", &a, &b);

		for (int i = a; i <= b; i++)
		{

			//znak = i;
			printf("%1s ", i);
			if (i = petla - 1)
				printf("\n");
		}

	}
	return 0;
}
