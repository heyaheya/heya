// Zad_A_17.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream> //cout
#include <string.h> //string
//#include <fstream> //obs³uga plikow
//#include <cstdlib>


//_CRT_SECURE_NO_WARNINGS

using namespace std;

int Konwertuj(int liczba)
{
	int i=31;
	int tab[31];
	

	while ( i--)
	{
		tab[30-i] = ((liczba >> i) & 1);
		//cout << tab[30-i];

	}

	cout << endl;

	int stan = 0;
	int a = 0;

	for (int k = 0; k < 31; k++ )
	{
		if ((tab[k]!=0) && (stan==0))
			stan = 1;
		
		if (stan == 1)
			cout << tab[k];
	}

	return 0;
}



int main()
{
	int liczba;


	cout << "Podaj liczbe do konwersji: ";
	cin >> liczba;

	
	cout << endl;

	cout << "Liczba w systemie binarnym: ";
	Konwertuj(a);

	cout << endl;	

	system("PAUSE");
	
	return 0;
}