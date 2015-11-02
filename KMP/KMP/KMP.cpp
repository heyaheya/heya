#include "stdafx.h"
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <fstream>
//#include <vector>


//program glowny1
int main(int argc, char *argv[])

{
	char sZadan[100000];
	//    int iZadan;
	char wzorzecP[100000];
	char kmpNext[100000];
	int liczbaPetli;
	int wzorzec;
	int liczbaWzorca;
	int iloscZadan;
	int znak;

	scanf("%s", sZadan);

	for (int t = 0; t<100000; t++)
	{
		znak = sZadan[t];
		if (znak != 10)
			iloscZadan = t;
		//printf("niemozliwe = %i", iloscZadan);
		break;
	}


	liczbaPetli = iloscZadan + 1;
	for (int i = 0; i < liczbaPetli; i++)
	{
		scanf("%i", &wzorzec);
		liczbaWzorca = wzorzec;

		scanf("%s", wzorzecP);
		scanf("%s", kmpNext);



		for (int k = 0; k < 100000; k++) //petla po ilosci spr
		{
			for (int j = 0; j < liczbaWzorca; j++)
			{

				if ((wzorzecP[j] == kmpNext[k + j])) //&& (wzorzecP[j] !=10))
				{
					//znak=wzorzecP[j];
					if (j == 2)
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


