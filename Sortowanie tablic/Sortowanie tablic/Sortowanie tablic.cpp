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

//test


//zapis umo?liwiajacy skrócenie zapisu polece? std::
using namespace std;

//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], int *tablicaDanych, int liczbaS);



//funkcja sortowania szybkiego
void quicksort(int *tablicaDanych, int lewy, int prawy)
{

	int i = lewy;
	int j = prawy;
	int x = tablicaDanych[(lewy + prawy) >> 1];

	int s = (lewy + prawy) / 2;
	s = (lewy + prawy) >> 1; //dzielenie binarne
	//int x=tablica[(lewy+prawy)/2];

	int licznik_q = 0;

	do
	{

		while (tablicaDanych[i]<x) i++; //szukam  elementu po prawej stronie  mniejszego od x - od i do j

		while (tablicaDanych[j]>x) j--;

		if (i <= j)  
		{
			int temp = tablicaDanych[i];
			tablicaDanych[i] = tablicaDanych[j];
			tablicaDanych[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (lewy<j)
		quicksort(tablicaDanych, lewy, j);

	if (prawy>i)
		quicksort(tablicaDanych, i, prawy);
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

	int zakresMin, zakresMax;

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


	/*

	//zapis do pliku
	//zapis danych do pliku
	char nazwaPliku[100];
	cout << "Podaj nazwe pliku (domyslnie rozszerzenie: .dat): ";
	cin >> nazwaPliku;
	zapiszDaneDoPliku(nazwaPliku, tablicaDanych, rozmiarTablicy);

	*/


	std::cout << std::endl;






		std::cout << std::endl;



		system("PAUSE");
	return 0;
}


//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], int *tablicaDanych, int liczbaS)
{

	//zapisanie wynikow do pliku
	fstream plik_wynik;


	strcat(nazwa, ".dat");

	plik_wynik.open(nazwa, ios::out | ios::out);
	if (!plik_wynik.good())
	{

		cout << "Nie udalo sie utworzyc pliku ! ! !" << endl;
		return 1;
	}
	else
	{
		cout << "Plik utworzony!\n";
	}

	string str1, str2;

	
	for (int i = 0; i < liczbaS; i++)
	{
		
		plik_wynik << tablicaDanych [i]<< " ";
	}

	
	plik_wynik.close();

	return 0;
}
