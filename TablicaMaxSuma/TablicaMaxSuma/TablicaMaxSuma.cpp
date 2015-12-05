// Sortowanie.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "string"
#include "windows.h"
#include <time.h>
#include <string.h>


using namespace std;


//f-cja wyszukuj¹ca sume max w przedziale z przedzialu :)
int WyszukajSumaMaxAlgLiniowy(int *tab, int liczbaS,int minP)
{
	int j = 0;
	int minZ = 0;
	int maxZ = 0;
	int maxsofar = minP;
	int maxsofar_old = minP;
	int maxhere = 0;

	 
	for (int i = 0; i < liczbaS; i++)
	{
		/* niezmiennik: maxhere i maxsofar s¹ 	prawid³owe dla x[0..i-1] */

		maxsofar_old = maxsofar;	
		maxhere = max(maxhere + tab[i], 0);
		maxsofar = max(maxsofar, maxhere);
	
		if (maxhere >= maxsofar)
		{
			//maxsofar = max(maxsofar, maxhere);
			maxZ = i;		
		}

	}

	int suma=0;
	for (int j = maxZ; suma <= maxsofar;j--)
	{
		suma += tab[j];
		if (suma == maxsofar) 
		{
			minZ = j;
			break;
		}		
	}

	
	cout << endl << "Suma maksymalna: " << maxsofar << endl;
	cout << "w przedziale: " << minZ + 1 << " ___ " << maxZ +1 << endl << endl;
	
	suma = 0;
	for (int k = minZ; k <= maxZ ; k++)
	{
		suma += tab[k];
	}
	
	cout << endl
		<< "suma=" <<suma
		<< "    spr=" << maxsofar - suma << endl;

	return 0;
}




//program
int main(void)

{
	//deklaracja zmiennych
	int rozmiarTablicy = 10;

	int iloscWyswietlanychDanych = 10;

	//zape³nienie tablicy liczbami losowymi

	int liczba = 0;

	//losowanie tablicy


	int los = 0;

	srand((unsigned)time(NULL));

	int zakresMin = 0, zakresMax= 10;


	cout << "Podaj dolny zakresu danych: ";
	cin >> zakresMin;

	cout << "Podaj gorny zakres danych: ";
	cin >> zakresMax;

	cout << "Podaj ilosc losow: ";
	cin >> rozmiarTablicy;



	int *tablicaDanych = new int[rozmiarTablicy];

	
	for (int i = 0; i < rozmiarTablicy; i++)
	{
		los = (double)rand() / (RAND_MAX + 1) * (zakresMax - zakresMin) + zakresMin;
		liczba = int(los);
		cout << liczba << "  ";
		tablicaDanych[i] = liczba;
	}

	

	std::cout << std::endl;
	std::cout << std::endl;

	WyszukajSumaMaxAlgLiniowy(tablicaDanych, rozmiarTablicy, zakresMin);


	std::cout << std::endl;
	system("PAUSE");
	return 0;
}

