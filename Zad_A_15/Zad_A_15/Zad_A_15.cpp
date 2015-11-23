// Zad_A_15.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>


//_CRT_SECURE_NO_WARNINGS

using namespace std;


struct student
{
	char imie[20];
	char nazwisko[20];
	int rok;
};



//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], student *tab, int liczbaS);


//f-cja sortujaca plik po nazwisku
int sortujPlikPoNazwisku(char nazwaPliku[100]);




int main()
{
	int liczbaS=1;
	cout << "Podaj liczbe struktur : ";
	cin >> liczbaS;

	student *tab;
	tab = (student*)malloc(liczbaS * sizeof(student));

    //	string str3;
	//char znaki[20];

	for (int i = 0; i < liczbaS; ++i)
	{
		cout << "Podaj imie " << i + 1 << " studenta: ";
		cin >> tab[i].imie;
		cout << "Podaj nazwisko " << i + 1 << " studenta: ";
		cin >> tab[i].nazwisko;
		cout << "Podaj rok studiow " << i + 1 << " studenta: ";
		cin >> tab[i].rok;
	}
	
	
	//wyswietl dane
	cout << endl;
	for (int k = 0; k < liczbaS; ++k)
	{
		cout << k + 1
			<< "."
			<< tab[k].imie
			<< " " << tab[k].nazwisko
			<< " - " << tab[k].rok
			<< endl;
	}


	//zapisanie wynikow do pliku
	char nazwa[100];
	cout << "Podaj nazwe pliku do zapisu danych (domyslnie .dat): ";
	cin >> nazwa;
	zapiszDaneDoPliku(nazwa, tab, liczbaS);



	//wywo³anie f-cji sortowania		
	char nazwaPliku[100];
	cout << endl << endl;
	cout << "Podaj nazwe pliku z danymi do posortowania (domyslnie .dat): ";
	cin >> nazwaPliku;
	sortujPlikPoNazwisku(nazwaPliku);
	

	system("pause");
	return 0;
}




//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], student *tab, int liczbaS)
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
		string str1, str2;
		int licz;

		for (int i = 0; i < liczbaS; i++)
		{
			plik_wynik << tab[i].imie << endl << tab[i].nazwisko << endl << tab[i].rok << endl;
			/*
			str1 = tab[i].imie;
			str2 = tab[i].nazwisko;
			licz = tab[i].rok;
			plik_wynik << str1 << endl << str2 << endl << licz << endl;
			*/
		}

		plik_wynik.close();		
		cout << "Plik utworzony!\n";
	}

	return 0;
}







//f-cja sortujaca plik po nazwisku
int sortujPlikPoNazwisku(char nazwaPliku[100])
{
	strcat(nazwaPliku, ".dat");
	fstream plik;
	std::cout << std::endl;

	plik.open(nazwaPliku, ios::in);

	if (!plik)
	{
		::cout << "Nie udalo sie utworzyc pliku ! ! !" << endl;
		getchar();
		return 1;
	}
	

	int liczbaS = 0;
	size_t rozmiar;
	rozmiar = 1;

	student *tabN;
	tabN = (student*)malloc(rozmiar * sizeof(student));


	while (!plik.eof())
	{
		plik >> tabN[liczbaS].imie;
		plik >> tabN[liczbaS].nazwisko;
		plik >> tabN[liczbaS].rok;
		++liczbaS;
		rozmiar = liczbaS + 1;
		tabN = (student*)realloc(tabN, rozmiar * sizeof(student));
	}

	plik.close();

	liczbaS--;
	//int pozycja = 0;

	//wyswietl dane
	cout << endl;
	cout << "Z pliku podczytano ponizsze dane:" << endl;

	for (int k = 0; k < liczbaS; ++k)
	{
		cout << k + 1
			<< "."
			<< tabN[k].imie
			<< " " << tabN[k].nazwisko
			<< " - " << tabN[k].rok
			<< endl;
	}


	student *tmp = new student[1];
	int  k = 0;
	int wynik = -99;

	for (int i = 1; i <= liczbaS - 1; i++)
	{
		k = 0;

		for (k = 0; k < i; k++)
		{
			/*
			cout << "n-1: " << tabN[i - 1-k ].nazwisko << endl;
			cout << "n:   " << tabN[i-k].nazwisko << endl;
			*/

			wynik = strcmp(tabN[i - 1-k].nazwisko, tabN[i-k].nazwisko);

			if (wynik > 0)
			{

				/*
				------------------------------------
				kopiuje wy³acznie pierwszy element :(   ???????????

				memcpy ( &tmp[0], &tabN[i-1], sizeof(tabN) );

				------------------------------------
				*/

				memcpy(tmp[0].imie, tabN[i - 1 - k].imie, 20);
				memcpy(tmp[0].nazwisko, tabN[i - 1 - k].nazwisko, 20);
				tmp[0].rok = tabN[i - 1 - k].rok;

				memcpy(tabN[i - 1 - k].imie, tabN[i - k].imie, 20);
				memcpy(tabN[i - 1 - k].nazwisko, tabN[i - k].nazwisko, 20);
				tabN[i - 1 - k].rok = tabN[i - k].rok;

				memcpy(tabN[i - k].imie, tmp[0].imie, 20);
				memcpy(tabN[i - k].nazwisko, tmp[0].nazwisko, 20);
				tabN[i - k].rok = tmp[0].rok;
			
			}
		}
	}

	delete (tmp);


	cout << endl;
	cout << "Poni¿ej posortowane dane:" << endl;

	for (int k = 0; k < liczbaS; ++k)
	{
		cout << k + 1
			<< "."
			<< tabN[k].imie
			<< " " << tabN[k].nazwisko
			<< " - " << tabN[k].rok
			<< endl;
	}

	cout << endl;


	//zapisanie wynikow do pliku
	char nazwa[100];
	cout << "Podaj nazwe pliku do zapisu wyniku (domyslnie .dat): ";
	cin >> nazwa;
	zapiszDaneDoPliku(nazwa, tabN, liczbaS);
	
	return 0;
}
