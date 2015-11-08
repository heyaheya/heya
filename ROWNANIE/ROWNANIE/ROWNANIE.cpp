// ROWNANIE.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>


int delta(float a, float b, float c)
{
	int iloscPierwiastkow;
	float delta;
	delta = (b * b - 4 * a * c);
	if (delta == 0)
		iloscPierwiastkow = 1;
	else
	{
		if (delta>0)
			iloscPierwiastkow = 2;
		else
			iloscPierwiastkow = 0;
	}
	return iloscPierwiastkow; //return  wynik;
}

//program glowny
int main(int argc, char *argv[])
{

	float  a, b, c;


		while		(scanf("%f %f %f", &a, &b, &c) >-1)
		//printf("%f   %f    ,   %f \n",a,b,c);

		if (a == 0) //Wspó?czynnik a musi by? ró?ny od 0 poniewa? dla a = 0 otrzymujemy równanie liniowe
		{
			printf("%d \n", 0);
		}
		else
		{
			printf("%d \n", delta(a, b, c));
		}


	return 0;
}

