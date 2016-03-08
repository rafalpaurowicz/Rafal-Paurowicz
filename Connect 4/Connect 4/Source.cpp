#include<stdio.h>
#include<iostream>
#include<windows.h>

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

///////////////////////////////////////////////////
void Wybor(int kol, int &k1, int &k2, int &k3, int &k4, int &k5, int &k6, int &k7, int &tmp, int &tmp2);
///////////////////////////////////////////////////
void Wybor2(int kol, int &k1, int &k2, int &k3, int &k4, int &k5, int &k6, int &k7, int &tmp, int &tmp2);
///////////////////////////////////////////////////
void Sprawdzanie(int &kol, int &wygrany, int &tmp, int &tmp2, int pnk[13][8]);
///////////////////////////////////////////////////
void winner(int i, int wygrany);
///////////////////////////////////////////////////
void mapa();
///////////////////////////////////////////////////


int main()
{
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);

	int numerg;
	int x, y, i, j, kgracza=0;
	int kol = 0;
	int k1 = 12, k2 = 12, k3 = 12, k4 = 12, k5 = 12, k6 = 12, k7 = 12;
	int pnk[13][8];
	int tmp=0, tmp2=0;
	int wygrany=0;
	int ponowna=0;
	mapa();

	gotoxy(50, 1);
	printf("4 W RZEDZIE");

		for (i = 1; i < 43; i++)
		{
			if (kgracza == 0)
			{

				gotoxy(40, 4);

				Wybor(kol, k1, k2, k3, k4, k5, k6, k7, tmp, tmp2);

				pnk[tmp2][tmp] = 1;
				Sprawdzanie(kol, wygrany, tmp, tmp2, pnk);
				kgracza = 1;
			}
			else
			{
				gotoxy(40, 4);

				Wybor2(kol, k1, k2, k3, k4, k5, k6, k7, tmp, tmp2);
				gotoxy(35, 7);
				printf("                                                     ");
				pnk[tmp2][tmp] = 2;
				Sprawdzanie(kol, wygrany, tmp, tmp2, pnk);
				kgracza = 0;
			}

			if (wygrany != 0)
			{
				break;
			}
		}
		gotoxy(35, 4);
		printf("                                                     ");
		gotoxy(35, 7);
		printf("                                                     ");

		winner(i, wygrany);


	gotoxy(50, 13);

	system("PAUSE");
	return 0;
}

void Wybor(int kol, int &k1, int &k2, int &k3, int &k4, int &k5, int &k6, int &k7, int &tmp, int &tmp2)
{
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	int wyb = 0, zgoda = 0;
	printf("GRACZ 1 [");
	SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("X");
	SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
	printf("]");
	do
	{
		gotoxy(35, 7);
		printf("Ktora kolumne wybierasz?[1-7]: ");
		scanf("%d", &wyb);
		gotoxy(35, 6);
		printf("                                                     ");
		tmp = wyb;
		if (tmp > 0 || tmp < 8)
		{
			kol = ((tmp * 4) - 1);
			if (wyb == 1) {
				gotoxy(kol, k1);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k1;
				k1 = k1 - 2;
			}if (wyb == 2) {
				gotoxy(kol, k2);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k2;
				k2 = k2 - 2;
			}if (wyb == 3) {
				gotoxy(kol, k3);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k3;
				k3 = k3 - 2;
			}if (wyb == 4) {
				gotoxy(kol, k4);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k4;
				k4 = k4 - 2;
			}if (wyb == 5) {
				gotoxy(kol, k5);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k5;
				k5 = k5 - 2;
			}if (wyb == 6) {
				gotoxy(kol, k6);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k6;
				k6 = k6 - 2;
			}if (wyb == 7) {
				gotoxy(kol, k7);
				SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("X");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k7;
				k7 = k7 - 2;
			}
		}
		if(tmp < 1 || tmp > 7)
		{
			gotoxy(35, 7);
			printf("                                                    ");
			gotoxy(35, 6);
			printf("LICZBA MUSI BYC Z ZAKRESU OD 1 DO 7! Podaj ponownie.");
		}
		gotoxy(35, 7);
		printf("                                                     ");
	} while (tmp < 1 || tmp>7);
	
	
}

void Wybor2(int kol, int &k1, int &k2, int &k3, int &k4, int &k5, int &k6, int &k7, int &tmp, int &tmp2)
{
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	int wyb = 0;
	printf("GRACZ 2 [");
	SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("O");
	SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
	printf("]");
	do
	{
		gotoxy(35, 7);
		printf("Ktora kolumne wybierasz?[1-7]: ");
		scanf("%d", &wyb);
		gotoxy(35, 6);
		printf("                                                     ");
		tmp = wyb;
		if (tmp > 0 || tmp < 8)
		{
			kol = ((tmp * 4) - 1);
			if (wyb == 1) {
				gotoxy(kol, k1);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k1;
				k1 = k1 - 2;
			}if (wyb == 2) {
				gotoxy(kol, k2);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k2;
				k2 = k2 - 2;
			}if (wyb == 3) {
				gotoxy(kol, k3);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k3;
				k3 = k3 - 2;
			}if (wyb == 4) {
				gotoxy(kol, k4);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k4;
				k4 = k4 - 2;
			}if (wyb == 5) {
				gotoxy(kol, k5);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k5;
				k5 = k5 - 2;
			}if (wyb == 6) {
				gotoxy(kol, k6);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k6;
				k6 = k6 - 2;
			}if (wyb == 7) {
				gotoxy(kol, k7);
				SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("O");
				SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
				tmp2 = k7;
				k7 = k7 - 2;
			}
		}
		if (tmp < 1 || tmp > 7)
		{
			gotoxy(35, 7);
			printf("                                                    ");
			gotoxy(35, 6);
			printf("LICZBA MUSI BYC Z ZAKRESU OD 1 DO 7! Podaj ponownie.");
		}
	} while (tmp < 1 || tmp>7);

}

void Sprawdzanie(int &kol, int &wygrany, int &tmp, int &tmp2, int pnk[13][8])
{
	int x, y, rzad = 0;
	x = tmp;
	y = tmp2;
	/////////////////////////////////////////////////////////////////////////////////////	PION
	if (pnk[y][x] == 1 && pnk[y + 2][x] == 1 && pnk[y + 4][x] == 1 && pnk[y + 6][x] == 1)
	{
		wygrany = 1;
		return;
	}
	if (pnk[y][x] == 2 && pnk[y + 2][x] == 2 && pnk[y + 4][x] == 2 && pnk[y + 6][x] == 2)
	{
		wygrany = 2;
		return;
	}
	///////////////////////////////////////////////////////////////////////////////////// Poziom
	if (pnk[y][x] == 1 && pnk[y][x + 1] == 1 && pnk[y][x + 2] == 1 && pnk[y][x + 3] == 1 || pnk[y][x] == 1 && pnk[y][x - 1] == 1 && pnk[y][x - 2] == 1 && pnk[y][x - 3] == 1)
	{
		wygrany = 1;
		return;
	}
	if (pnk[y][x] == 2 && pnk[y][x + 1] == 2 && pnk[y][x + 2] == 2 && pnk[y][x + 3] == 2 || pnk[y][x] == 2 && pnk[y][x - 1] == 2 && pnk[y][x - 2] == 2 && pnk[y][x - 3] == 2)
	{
		wygrany = 2;
		return;
	}
	///////////////////////////////////////////////////////////////////////////////////// SKOS
	if (pnk[y][x] == 1 && pnk[y + 2][x + 1] == 1 && pnk[y + 4][x + 2] == 1 && pnk[y + 6][x + 3] == 1 ||
		pnk[y][x] == 1 && pnk[y + 2][x - 1] == 1 && pnk[y + 4][x - 2] == 1 && pnk[y + 6][x - 3] == 1 ||
		pnk[y][x] == 1 && pnk[y - 2][x + 1] == 1 && pnk[y - 4][x + 2] == 1 && pnk[y - 6][x + 3] == 1 ||
		pnk[y][x] == 1 && pnk[y - 2][x - 1] == 1 && pnk[y - 4][x - 2] == 1 && pnk[y - 6][x - 3] == 1)
	{
		wygrany = 1;
		return;
	}
	if (pnk[y][x] == 2 && pnk[y + 2][x + 1] == 2 && pnk[y + 4][x + 2] == 2 && pnk[y + 6][x + 3] == 2 ||
		pnk[y][x] == 2 && pnk[y + 2][x - 1] == 2 && pnk[y + 4][x - 2] == 2 && pnk[y + 6][x - 3] == 2 ||
		pnk[y][x] == 2 && pnk[y - 2][x + 1] == 2 && pnk[y - 4][x + 2] == 2 && pnk[y - 6][x + 3] == 2 ||
		pnk[y][x] == 2 && pnk[y - 2][x - 1] == 2 && pnk[y - 4][x - 2] == 2 && pnk[y - 6][x - 3] == 2)
	{
		wygrany = 2;
		return;
	}

}

void winner(int i, int wygrany)
{
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);

	if (i == 43)
	{
		gotoxy(42, 3);
		printf("Wszystkie pola zostaly zapelnione.");
		gotoxy(42, 8);
		printf("\t	REMIS");
	}

	if (wygrany == 1)
	{
		gotoxy(42, 3);
		printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
		gotoxy(42, 4);
		printf("\xBA ");
		SetConsoleTextAttribute(kolor, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("WYGRYWA GRACZ 1");
		SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
		printf(" \xBA");
		gotoxy(42, 5);
		printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
		gotoxy(35, 9);
	}
	if (wygrany == 2)
	{
		gotoxy(42, 3);
		printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
		gotoxy(42, 4);
		printf("\xBA ");
		SetConsoleTextAttribute(kolor, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("WYGRYWA GRACZ 2");
		SetConsoleTextAttribute(kolor, 15 | FOREGROUND_INTENSITY);
		printf(" \xBA");
		gotoxy(42, 5);
		printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
		gotoxy(35, 9);
	}
}

void mapa()
{
	int i;
	system("cls");
	int nastepny;

	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB\n");
	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB\n");
	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB\n");
	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB\n");
	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB\n");
	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB   \xDB\n");
	for (i = 0; i < 29; i++)
		printf("\xDB");// 29 nakow
	printf("\n\xDB 1 \xDB 2 \xDB 3 \xDB 4 \xDB 5 \xDB 6 \xDB 7 \xDB\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(" Created by Rafal Paurowicz");
}