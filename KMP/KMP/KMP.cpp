#include "stdafx.h"
#include <stdio.h>
#include <iostream>


/*
65-90 [A-Z]
97-122 [a-z]
funkcja spr czy znak jest z zakresu 
*/

int sprCzyZakres(int x)
{
	
	if (((x > 64) && (x < 91)) || ((x>96) && (x < 123)))	
		return 1;
	else
		return 0;
}


int main(int argc, char *argv[])

{
	//zrobiæ przez stworzenie tablicy dynamicznej - f-cja malloc wyk³ad cpp str 89
	char wzorzecP[10000];
	char zestawZnakow[10000];
	int iloscZadan, wzorzec;

	scanf("%i", &iloscZadan);
	
	for (int i = 0; i < iloscZadan; i++)
	{
		scanf("%i", &wzorzec);
		scanf("%s", wzorzecP);
		scanf("%s", zestawZnakow);


		for (int k = 0; k < 10000; k++) //petla po ilosci spr
		{
			for (int j = 0; j < wzorzec; j++)
			{
				if (((wzorzecP[j] == zestawZnakow[k + j])) && (sprCzyZakres(zestawZnakow[k + j])==1))
				{
					if (j == wzorzec-1)
						printf("%i\n", k);
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}


