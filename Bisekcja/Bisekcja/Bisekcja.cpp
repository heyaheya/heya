// Bisekcja.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#include <iomanip>

using namespace std;


double f(double x)
{
		return x*x - 4;
}



double bisekcja(double a, double b, double Eps)
{
	double s;

	if (f(a)*f(b) < 0)
	{
		s = a;

		while ((b - a) >= Eps)
		{
			s = (b + a) / 2;

			if (f(a)*f(s) < 0)
			{
				b = s;
			}
			else
			{
				if (f(s)*f(b) < 0)
				{
					a = s;
				}
			} 
		}
	}
	else
		s = -0, 0;

	return(s);
}



int main()
{
	double a = 0, b = 0, Eps, s;

	cout << "Program wyznaczania miejsc zerowych f-cji x*x-4" << endl;
	cout << "Podaj przedzial" << endl;

	cout << "Podaj a: ";
	cin >> a;

	//cout << endl;

	cout << "Podaj b: ";
	cin >> b;

	cout << endl;

	cout << "Podaj precyzje: ";
	cin >> Eps;

	cout << endl;

	if (a < b)
	{
		s = bisekcja(a, b, Eps);
	}
	else
	{
		s = bisekcja(b, a, Eps);
	}
	
	//cout << "Wynik: " << s << endl;

	printf("Wynik: %0.2f", s);

	cout << endl;
	cout << endl;

	system("pause");

	return 0;

}

