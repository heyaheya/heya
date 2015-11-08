// Zad_A_1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
//#include <ctype.h.>



int main(int argc, char *argv[])
{
	int a,b;
	double x, y;
	float w;
			
	printf("Program liczy funkcje ax+b=0\n");
	printf("Podaj liczbe a i b - oddzielone spacjami:");

	scanf("%i %i", &a, &b);
	printf("\n");
		
	x = a;
	y = b;
	w = -y / x;
	printf("Wartosc szukana x=%.2f", w);
	
	return 0;
}


