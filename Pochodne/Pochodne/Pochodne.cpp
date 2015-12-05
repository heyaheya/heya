// Calka MonteCarlo.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream> 
//#include <string.h>
//#include <fstream>
#include <string>


//_CRT_SECURE_NO_WARNINGS

using namespace std;

float f(float x)
{
	return (x * x);
}

float pochodna1(float x, float h)
{
	return ((f(x + h) - f(x - h)) / (2 * h));
}

float pochodna2(float x, float h)
{
	return ((f(x + h) + f(x - h) - 2 * f(x)) / (h * h));
}

int main()
{
	float x = 0, h = 0;

	cout << "Funkcja x^2" << endl;
	cout << "Podaj wartosc x: ";
	cin >> x;
	cout << "Podaj wartosc h: ";
	cin >> h;
	cout << endl;
	cout << "Pochodna f-cji wynosi: " << pochodna1(x, h) << endl;
	cout << "Druga pochodna f-cji wynosi: " << pochodna2(x, h) << endl;

	system("PAUSE");
	return 0;
}


