// Zad_A_2.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
//#include <ctype.h.>



int main(int argc, char *argv[])

{
	int a1, b1, a2, b2;
	// a, b;
	float x1, y1,x2, y2;
	//float x,y;

	printf("Program obliczajacy wspolrzedne wektora - liczby ca³kowite.\n");
	printf("Podaj wspolrzedne punktow (x1,y1) (x2,y2) - oddzielone spacjami:");

	scanf("%i %i %i %i", &a1, &b1, &a2, &b2);
	//printf("\n");
	
	printf("Wspolrzedne wektora wynosza (x y) %i %i\n", a1-a2, b1-b2);

	printf("Program obliczajacy wspolrzedne wektora - liczby rzeczywiste.\n");
	printf("Podaj wspolrzedne punktow (x1,y1) (x2,y2) - oddzielone spacjami:");

	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	//printf("\n");

	printf("Wspolrzedne wektora wynosza (x y) %.2f %.2f", x1 - x2, y1 - y2);
	
	return 0;
}



