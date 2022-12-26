// Hudba.cpp : Defines the entry point for the application.
//

#include "Hudba.h"

#include <stdio.h>
#include <ctype.h>              // tolower
#include <stdlib.h>				// system

#include "HudbaDB.h"

struct t_album* prvni = NULL; // globalni ukazatel na prvni album

void OnAdd()
{
	char my_interpret[CHAR_ARRAY_SIZE];
	char my_album[CHAR_ARRAY_SIZE];
	int my_year;

	printf("\nInterpret : ");         // dotazeme se na polozky
	scanf_s("%s", my_interpret, CHAR_ARRAY_SIZE);
	while (getchar() != '\n');

	printf("\nAlbum : ");         // dotazeme se na polozky
	scanf_s("%s", my_album, CHAR_ARRAY_SIZE);
	while (getchar() != '\n');

	printf("\nRok : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');

	add(my_interpret, my_album, my_year, &prvni);         // volame pridavaci funkci
}

void OnDel()
{
	char my_interpret[CHAR_ARRAY_SIZE];

	printf("\nInterpret : ");
	scanf_s("%s", &my_interpret, CHAR_ARRAY_SIZE);
	while (getchar() != '\n');
	del(my_interpret, &prvni);         // volame mazaci funkci
}

void ShowAlbums()
{
	struct t_album* aktAlbum = prvni; // ukazatel na aktualni album
	printf("\n\n");
	while (aktAlbum) // prochazeni seznamu
	{
		printf("%d: %s: %s\n", aktAlbum->rok, aktAlbum->interpret, aktAlbum->album); // tisk radku
		aktAlbum = aktAlbum->dalsi; // posun na dalsi album
	}
	getchar();
}

void ShowInterpret() {
	char input;

	printf("Zacatecni pismeno interpreta: ");
	scanf("%c", &input);
	while (getchar() != '\n');

	struct t_album* aktAlbum = prvni; // ukazatel na aktualni album
	printf("\n\n");
	while (aktAlbum) // prochazeni seznamu
	{
		if (aktAlbum->interpret[0] == input)
			printf("%d: %s: %s\n", aktAlbum->rok, aktAlbum->interpret, aktAlbum->album); // tisk radku
		aktAlbum = aktAlbum->dalsi; // posun na dalsi album
	}
	getchar();
}


int main()
{
	char  cmd;

	do
	{
		system("cls");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("F: Tisk dle interpreta     ");
		printf("Q: Konec\n\n");
		 
		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowAlbums();
			break;
		case 'f':
			ShowInterpret();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
}


