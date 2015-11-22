// Zad_A_14.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>


//_CRT_SECURE_NO_WARNINGS

using namespace std;


struct student
{
	char imie[20];
	char nazwisko[20];
	int rok;
};

//funkcja wyszukujaca po nazwisku
int wyszukajPoNazwisku(char nazwisko[20], char nazwaPliku[100]);

//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], student *tab, int liczbaS);


int main()
{
	int liczbaS;
	student *tab;

	cout << "Podaj liczbe struktur : ";
	cin >> liczbaS;

	//student * tab = new student[liczbaStudentow];
	tab = (student*)malloc(liczbaS * sizeof(student));

	for (int i = 0; i < liczbaS; ++i)
	{
		cout << "Podaj imie " << i + 1 << " studenta: ";
		cin >> tab[i].imie;
		cout << "Podaj nazwisko " << i + 1 << " studenta: ";
		cin >> tab[i].nazwisko;
		cout << "Podaj rok studiow " << i + 1 << " studenta: ";
		cin >> tab[i].rok;
	}


	//wyswietlDane(student * &tab, int liczba)
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

	

	// wywolanie funkcji wyszukiwania z pliku
	char nazwisko[20];
	char nazwaPliku[100];
	cout << endl << endl;
	cout << "Podaj nazwe pliku z danymi (domyslnie .dat): ";
	cin >> nazwaPliku;
	cout << "Podaj nazwisko studenta do wyszukania: ";
	cin >> nazwisko;
	int wynik = 0;
	wynik = wyszukajPoNazwisku(nazwisko, nazwaPliku);



	system("pause");
	return 0;
}



//funkcja wyszukujaca po nazwisku
int wyszukajPoNazwisku(char nazwisko[20], char nazwaPliku[100])
{
	strcat(nazwaPliku, ".dat");
	fstream plik;
	std::cout << std::endl;

	plik.open(nazwaPliku, ios::in);

	if (!plik)
	{
		cout << "Nie udalo sie utworzyc pliku ! ! !" << endl;
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
	int pozycja = 0;
	cout << endl;



	for (int k = 0; k < liczbaS; ++k)
	{

		//wyszukiawanie
		if (strcmp(nazwisko, tabN[k].nazwisko) == 0)
		{
			cout << "Znalezioino studenta na pozycji " << k + 1;
			pozycja = k + 1;
			cout << endl
				<< "imie: " << tabN[k].imie << endl
				<< "nazwisko: " << tabN[k].nazwisko << endl
				<< "rok: " << tabN[k].rok << endl
				<< endl;
		}
	}


	return pozycja;
}


//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], student *tab, int liczbaS)
{

	//zapisanie wynikow do pliku
	fstream plik_wynik;


	strcat(nazwa, ".dat");

	plik_wynik.open(nazwa, ios::out);
	if (!plik_wynik.good())
	{

		cout << "Nie udalo sie utworzyc pliku ! ! !" << endl;
		return 1;
	}
	else
	{
		cout << "Plik utworzony!\n";
	}


	for (int i = 0; i < liczbaS; i++)
	{
		plik_wynik << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].rok << " ";// << endl;
	}

	plik_wynik.close();

	return 0;
}
