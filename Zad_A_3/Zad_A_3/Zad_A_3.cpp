// Zad_A_3.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
//#include <ctype.h.>

//_CRT_SECURE_NO_WARNINGS

int main(int argc, char *argv[])
{
	float w,a,b,c;

	printf("Program liczy srednia trzech liczb.\n");
	printf("Podaj liczbe a,b,c - oddzielone spacjami:");

	scanf("%f %f %f", &a, &b, &c);
	printf("\n");


	w = (a + b +c )/ 3;
	printf("Srednia to: %.2f", w);

	return 0;
}
