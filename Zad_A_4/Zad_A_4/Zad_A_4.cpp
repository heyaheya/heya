// Zad_A_4.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
//#include <ctype.h.>

//_CRT_SECURE_NO_WARNINGS

int main(int argc, char *argv[])

{
	int a, h;
	float w, x, c;
	printf("\n");
	printf("Program liczy pole trojkata.\n");
	printf("Podaj podstawe i wysokosc a,h - oddzielone spacjami:");

	scanf("%i %i", &a, &h);
	printf("\n");

	x = a;
	c = h;
	w = (x * c) / 2;
	printf("Pole trojkata wynosi: %.3f", w);

	printf("\n");

	return 0;
}
