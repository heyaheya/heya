// ConsoleApplication1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "iostream"
#include "stdio.h"


int main()
{

	int iloscPesel;
	char PESEL[11];
	int zestaw[11] = { 9,7,3,1,9,7,3,1,9,7,9 };
	int liczba;
	char znak;
	//int sum=0;
	int suma = 0;

	scanf("%i", &iloscPesel);
	liczba = iloscPesel;
	for (int i = 0; i < liczba; i++)
	{
		scanf("%11s", PESEL);
		suma = 0;
		for (int k = 0; k < 11; k++)
		{
			znak = PESEL[k];
			//liczba = PESEL[k];
			//sum=(PESEL[k]-48) * zestaw[k];
			suma += (PESEL[k] - 48) * zestaw[k];
			//printf("%i-%c-%i-%i-%i-%i ," , k+1 , znak,liczba,PESEL[k]-48,sum,suma);
			printf("%c", znak);
		}
		if (suma % 10 == 0)
			printf(" D");
		else
			printf(" N");

		printf("\n");
	}

    return 0;
}

