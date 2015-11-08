// Wyszukiwanie binarne.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;



int wyszukajLiczbe(int d, int g, int szukana, int  *tab)
{
	//int s =( g-d) >> 1;
	int s = (g - d) / 2;
	//int pozycja = 0;
	int wartosc = 0;
	int d1 = d;
	int g1 = g;
	//wartosc = tab[g1-1];
	
	if (tab[g1-1] == szukana)
		return g1;
	else
	{

		while (g1 - d1 >= 1)
		{

			int s = d1 + (g1 - d1) / 2;

			wartosc = tab[s - 1];

			if (wartosc == szukana)
			{
				return s;
			}
			else
			{
				if (g1 - d1 == 1)
					return-1;
				else
				{
					if (wartosc < szukana)
					{
						d1 = s;
					}
					else
					{
						g1 = s;
					}
				}

			}

		}

	}
		return -1;

}






int main()
{
   

	int liczba = 0;

	//losowanie tablicy

	int rand1 = 0;
	int randMax = 0;

	double p = 0;
	int n = 0; //zakres
	int m = 0; //ilosc losow

	double los = 0;
	
	srand((unsigned)time(NULL));

	cout << "Podaj ilosc liczb: ";
	cin >> n;

	cout << "Podaj ilosc losow: ";
	cin >> m;

	int n1 = n;
	int m1 = m;

	int *tab = new int[m];

	if (n == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			los = (double)rand() / (RAND_MAX + 1);

			// obliczenie p-stwa
			p = (double)m1 / n1;
		
			if (p > los)
			{
				printf("%i ", i);
				tab[m - m1] = i;
				m1--;
			}

			n1--;
		}
	}


	/*
	for (int a = 0; a < m; a++)
		printf("%i ", tab[a]);
    */

	
	//wywoalnie f-cji wyszukiwania
	int pozycja = 0;
	int szukana;

	printf("\n");

	cout << "Podaj szukana liczbe: ";
	cin >> szukana;

	pozycja = wyszukajLiczbe(1, m, szukana,tab);

	if (pozycja == -1)
		cout << endl  <<"Brak liczby w przedziale";
	else
		cout << endl <<"Szukana liczba znajduje sie na pozycji: " << pozycja;

	 


	cout << endl;
	system("pause");
	return 0;
}

