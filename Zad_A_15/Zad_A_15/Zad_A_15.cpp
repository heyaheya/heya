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
	string imie;
	string nazwisko;
	int rok;
};

struct student_c
{
	char imie[20];
	char nazwisko[20];
	int rok;
};


//funkcja wyszukujaca po nazwisku
int wyszukajPoNazwisku(string nazwisko, char nazwaPliku[100]);

//f-cja zapisu tablicy danych do pliku
int zapiszDaneDoPliku(char nazwa[100], student_c *tab, int liczbaS);



//f-cja sortujaca plik po nazwisku
int sortujPlikPoNazwisku(char nazwaPliku[100])
{
	strcat(nazwaPliku, ".dat");
	fstream plik;
	std::cout << std::endl;

	plik.open(nazwaPliku, ios::out);

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

	string str0;
	int liczba;

	while (!plik.eof())
	{

		plik >> str0;
		tabN[liczbaS].imie=str0;
		plik >> str0;
		tabN[liczbaS].nazwisko=str0;
		plik >> liczba;
		//liczba = str;
		tabN[liczbaS].rok=liczba;
		++liczbaS;
		rozmiar = liczbaS + 1;
		tabN = (student*)realloc(tabN, rozmiar * sizeof(student));
	}

	plik.close();



	liczbaS--;
	int pozycja = 0;
	cout << endl;


	//wyswietl dane
	cout << endl;
	for (int k = 0; k < liczbaS; ++k)
	{
		cout << k + 1
			<< "."
			<< tabN[k].imie
			<< " " << tabN[k].nazwisko
			<< " - " << tabN[k].rok
			<< endl;
	}

	string strA, strB;

	student tmp;

	int  k = 0;
	string naz1, naz2;

	for (int i = 1; i < liczbaS - 1; i++)
	{
				

	for (k = 0; k < 20; k++)
		{

			strA = tabN[i - 1].nazwisko[k];
			strB = tabN[i].nazwisko[k];
			cout << strA << endl;
			cout << strB << endl;

			if (strA > strB) 
			{
				
				tmp.imie = tabN[i - 1].imie;
				tmp.nazwisko = tabN[i - 1].nazwisko;
				tmp.rok = tabN[i - 1].rok;

				tabN[i ].imie = tabN[i - 1].imie;
				tabN[i].nazwisko = tabN[i - 1].nazwisko;
				tabN[i].rok = tabN[i - 1].rok;

				tabN[i-1].imie = tmp.imie;
				tabN[i-1].nazwisko = tmp.nazwisko;
				tabN[i-1].rok = tmp.rok;			
				break;
			}

		}

	}

	//delete (tmp);
	return 0;
}


int main()
{
	int liczbaS;
	student_c *tab;


	

	cout << "Podaj liczbe struktur : ";
	cin >> liczbaS;

	//student * tab = new student[liczbaS];
	tab = (student_c*)malloc(liczbaS * sizeof(student_c));

	string str3;
	char znaki[20];

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


	/*
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

	*/
	

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
int zapiszDaneDoPliku(char nazwa[100], student_c *tab, int liczbaS)
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
	int licz;

	for (int i = 0; i < liczbaS; i++)
	{
		//plik_wynik << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].rok << " ";// << endl;

		str1 = tab[i].imie;
		str2 = tab[i].nazwisko;
		licz = tab[i].rok;
		
		plik_wynik << str1 << endl << str2 << endl <<licz << endl;
	}

	plik_wynik.close();

	return 0;
}
