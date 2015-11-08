// Generowanie ciagow.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    
	int rand1=0;
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



	//wstawic warunek na zero liczb

	if (n == 0)
	{
		return 0;
	}
	else
	{


		for (int i = 1; i <= n ; i++)
		{

				los = (double)rand() / (RAND_MAX + 1);

				// obliczenie p-stwa
				p = (double)m1 / n1;


				if (p > los)
				{
					m1--;					
					printf("%i ", i);
				}

				n1--;		
		}
	}


	system ("pause");
	return 0;
}

