// Sortowanie.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "string"
#include "windows.h"




//zapis umo?liwiajacy skrócenie zapisu polece? std::
using namespace std;


//funkcja sortowania szybkiego
void quicksort(int tablica[], int lewy, int prawy)
{

	int i = lewy;
	int j = prawy;
	int x = tablica[(lewy + prawy) >> 1];

	int s = (lewy + prawy) / 2;
	s = (lewy + prawy) >> 1;
	//int x=tablica[(lewy+prawy)/2];

	int licznik_q = 0;

	do
	{

		while (tablica[i]<x) i++; //szukam  elementu po prawej stronie  mniejszego od x - od i do j

		while (tablica[j]>x) j--;

		if (i <= j)  //jezeli
		{
			int temp = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (lewy<j)
		quicksort(tablica, lewy, j);

	if (prawy>i)
		quicksort(tablica, i, prawy);
}




//program g?owny1
int main(void)

{
	//deklaracja zmiennych
	int rozmiarTablicy = 100000;

	//cout << "Podaj ilosc liczb: ";
	//cin >> rozmiarTablicy;

	fstream plik;
	string nazwaPliku;


	int tablicaDanych[100000];

	for (int i0 = 0; i0 < rozmiarTablicy; i0++)
		tablicaDanych[i0] = 0;


	int tmp = 0;

	//cout << "Podaj nazwe pliku (domyslnie rozszerzenie: .txt): ";
	//cin >> nazwaPliku;
	nazwaPliku = "dane100tys";



	std::cout << std::endl;

	nazwaPliku = nazwaPliku + ".txt";
	plik.open(nazwaPliku.c_str(), ios::in);

	if (!plik)
	{
		cout << "Nie mozna otworzyc pliku";
		getchar();
		return 1;
	}

	while (!plik.eof())
		plik >> tablicaDanych[tmp++];




	//wyswietlenie 5 pierwszych liczb z tablicy
	for (int i = 0; i < 5; i++)
	{
		std::cout << tablicaDanych[i] << std::endl;
	}


	//*****************************
	//sortowanie
	std::cout << "1 - Sortowanie przez wstawianie" << std::endl;
	std::cout << "2 - Sortowanie szybkie (quicksort)" << std::endl;
	std::cout << "3 - Sortowanie przez kopcowanie (sortowanie stogowe)" << std::endl;
	std::cout << "Podaj sposob sortowania:";
	int liczba;
std:cin >> liczba;

	int dana1 = 0, dana2 = 0;


	switch (liczba)
	{
	case 1: //Sortowanie przez wstawianie
	{

		int temp = 0, k = 0;
		for (int i = 1; i < rozmiarTablicy; i++)
		{



			for (k = 0; k < i; k++)
			{

				if (tablicaDanych[i - 1 - k] > tablicaDanych[i - k])
				{
					temp = tablicaDanych[i - 1 - k];
					tablicaDanych[i - 1 - k] = tablicaDanych[i - k];
					tablicaDanych[i - k] = temp;


				}
			}
		}

		break;
	}


	case 2: //Sortowanie szybkie (quicksort)
	{

		//przed sortowaniem
		//wyswietlenie 5 pierwszych liczb z tablicy
		for (int i = 0; i < 5; i++)
		{
			std::cout << tablicaDanych[i] << " ";
		}
		std::cout << std::endl;






		//wywo³anie funkcji szybkiego sortowania

		//wyznaczenie wartoœci srodkowej
		int a = 0, b = 0, c = 0, s = 0;
		a = tablicaDanych[0];
		b = tablicaDanych[rozmiarTablicy / 2];
		c = tablicaDanych[rozmiarTablicy - 1];

		std::cout << "a-" << a << "  b-" << b << "  c-" << c << std::endl;

		if ((a > b) && (a > c))
		{
			if (b > c)
				s = b;
			else
				s = c;
		}

		if ((b > a) && (b > c))
		{
			if (a > c)
				s = a;
			else
				s = c;
		}

		if ((c > b) && (c > a))
		{
			if (b > a)
				s = b;
			else
				s = a;
		}

		std::cout << "s-" << s << std::endl;



		quicksort(tablicaDanych, 0, rozmiarTablicy - 1);



		//po sortowaniu
		//wyswietlenie 5 pierwszych liczb z tablicy
		for (int i = 0; i < 5; i++)
		{
			std::cout << tablicaDanych[i] << " ";
		}
		std::cout << std::endl;



		break;
	}

	case 3:  //Sortowanie przez kopcowanie (sortowanie stogowe)
		std::cout << "Niestety metoda jeszcze nie dzia³a :(" << std::endl;
		break;
	default:
		std::cout << "nie wybrano poprawnie" << std::endl;
		break;
	}




	//zapisanie wynikow do pliku
	fstream plik_wynik;
	nazwaPliku = "wynik.txt";
	plik_wynik.open(nazwaPliku.c_str(), ios::out); // .c_str konwertuje zmienna do wersji C
	if (!plik_wynik.good())
	{
		cout << "Nie udalo sie utworzyc pliku!\n";
	}
	else
	{
		cout << "Plik utworzony!\n";
	}


	for (int i = 0; i < rozmiarTablicy; i++)
	{
		plik_wynik << tablicaDanych[i] << " ";
	}

	return 0;
}

