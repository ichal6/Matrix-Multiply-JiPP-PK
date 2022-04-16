﻿// kolokwium1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
/*#define N 8
#define M 12
#define K 5*/

FILE* fd = NULL;

int main()
{

	int s = 0;
	int t = 0;

	const int N = 8, M = 12, K = 5;
	
	double** A; // wskaźnik na tablice dwuwymiarową
	double** B; // wskaźnik na tablice dwuwymiarową
	double* D1; // wskaźnik na tablice 
	double** C; // wskaźnik na tablice dwuwymiarową

	//otwarcie pliku
	if (!(fd = fopen("grupa_b.txt", "r")))
	{
		printf("Blad otwarcia pliku\n");
		exit(2);
	}

	

	A = (double**)malloc(sizeof(double*) * N); // alokowanie wskaźnika na tablicę wskaźników

	//alokowanie pamięci
	for (int x = 0; x < N; x++)
	{
		A[x] = (double*)malloc(sizeof(double) * M); // alokuj pamięc na wiersz tablicy
		if (!A[x])
		{
			return 2; //błąd alokacji
		}
	}
	
	B = (double**)malloc(sizeof(double*) * N); // alokowanie wskaźnika na tablicę wskaźników

	//alokowanie pamięci
	for (int x = 0; x < M; x++)
	{
		B[x] = (double*)malloc(sizeof(double) * K); // alokuj pamięc na wiersz tablicy
		if (!B[x])
		{
			return 2; //błąd alokacji
		}
	}




	D1 = (double*)malloc(sizeof(double) * K); // alokuj pamięc na wiersz tablicy
	
	C = (double**)malloc(sizeof(double*) * N); // alokowanie wskaźnika na tablicę wskaźników

	//alokowanie pamięci
	for (int x = 0; x < N; x++)
	{
		C[x] = (double*)malloc(sizeof(double) * K); // alokuj pamięc na wiersz tablicy
		if (!C[x])
		{
			return 2; //błąd alokacji
		}
	}

	//double C[N][K];



	double bufor;

	//

	//Wypełnianie macierzy A
	int n = 0, k = 0;
	while (k < N)
	{
		n = 0;
		while(n < M)
		{
			fscanf(fd,"%lf" ,&bufor);
			A[k][n] = bufor;
			n++;
		}
		printf("\n");
		k++;
	}

	//Wypełnianie macierzy B
	n = 0;
	k = 0;
	while (k < M)
	{
		n = 0;
		while (n < K)
		{
			fscanf(fd, "%lf", &bufor);
			B[k][n] = bufor;
			n++;
		}
		printf("\n");
		k++;
	}

	//Wypełnianie wektora D1
	n = 0;
	k = 0;
	
		while (n < K)
		{
			fscanf(fd, "%lf", &bufor);
			D1[n] = bufor;
			n++;
		}
		k++;
	
	//drukowanie macierzy A
	n = 0;
	k = 0;
	printf("Macierz A:\n");
	while (k < N)
	{
		n = 0;
		while(n < M)
		{
			printf("%+2.1lf\t", A[k][n]);
			n++;
		}
		printf("\n");
		k++;
	}
	

	
	//drukowanie macierzy B
	printf("Macierz B:\n");
	k = 0;
	while (k < M)
	{
		n = 0;
		while (n < K)
		{
			printf("%+2.1lf\t", B[k][n]);
			n++;
		}
		printf("\n");
		k++;
	}
	
	
	int i, j;
	double tmp;

	k = 0;

	//Mnożenie macierzy v2  
	for (i = 0;i < N  ;i++)
	{ 
		for (j = 0;j < K   ;j++)
		{
			//tmp = 0; 
			C[i][j] = 0;
				for (k = 0;k < M    ;k++)
				{
					
					C[i][j] = (A[i][k] * B[k][j]) + C[i][j];
				}
				
			//C[i][j] = tmp;
		}
	}
	double wynik;

	//drukowanie macierzy
	printf("Drukowanie macierzy C:\n\n\n");
	k = 0;
	
	while (k < N)
	{
		n = 0;
		while (n < K)
		{
			printf("%+2.2lf\t", C[k][n]);
			n++;
		}
		printf("\n");
		k++;
	}

	//szukaj elementu maksymalnego
	wynik = C[0][0];
	k = 0;
	int x = 0;
	int y = 0;
	while (k < N)
	{
		n = 0;
		while (n < K)
		{
			if (wynik < C[n][k])
			{
				wynik = C[n][k];
				x = n;
				y = k;
			}

			n++;
		}
		k++;
	}

	printf("Najwiekszy element w tablicy to %lf o wspolrzednych %i,%i\n\n", wynik, x, y);

	//szukaj elementu minimalnego
	wynik = C[0][0];
	k = 0;
	x = 0;
	y = 0;
	while (k < N)
	{
		n = 0;
		while (n < K)
		{
			if (wynik > C[n][k])
			{
				wynik = C[n][k];
				x = n;
				y = k;
			}

			n++;
		}
		k++;
	}

	printf("Najmniejszy element w tablicy to %lf o wspolrzednych %i,%i\n\n", wynik, x, y);

	double liczba = 0;

	//Mnożenie macierzy przez D
	for (j = 0;j < K;j++)
	{
		liczba += C[j][x] * D1[j];
	}

	printf("Iloczyn skalarny = %lf", liczba);

	double D_2[N];

	//Wektor macierzy i wektora
	for (i = 0;i < N;i++)
		{
			D_2[i] = 0;
			for (k = 0;k < K ;k++)
			{
				D_2[i] = (C[i][k] * D1[k]) + D_2[i];
			}

			
		}


	//drukowanie D2
	printf("\nDrukowanie D2:\n\n\n");
	

	
		n = 0;
		while (n < N)
		{
			printf("%lf ", D_2[n]);
			n++;
		}
		printf("\n");
		
	
		//zwalnianie pamięci zaalokowanej na tablicę
		if (A)
		{
			for ( i = 0; i < N; i++)
			{
				if (A[i])
				{
					free(A[i]);
				}
			}
			free(A);
			A = NULL;
		}


		//zwalnianie pamięci zaalokowanej na tablicę
		if (B)
		{
			for (i = 0; i < M; i++)
			{
				if (B[i])
				{
					free(B[i]);
				}
			}
			free(B);
			B = NULL;
		}
		//zwalnianie pamięci zaalokowanej na wektor
		free(D1);

		//zwalnianie pamięci zaalokowanej na tablicę
		if (C)
		{
			for (i = 0; i < N; i++)
			{
				if (C[i])
				{
					free(C[i]);
				}
			}
			free(C);
			C = NULL;
		}

	fclose(fd); /* zamknij plik */

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
