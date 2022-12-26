// text.cpp : Defines the entry point for the application.
//

#include "text.h"

using namespace std;

int pocetPismen(char *text);
int pocetCisel(char *text);
int maxDelkaSlova(char* text);

int main()
{
	char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi. Auto Hyundai ix35 ma pres 120 konskych sil.";

	printf("Statistiky textu:\n");
	printf(" Pismena: %d\n", pocetPismen(text));
	printf(" Cisla: %d\n", pocetCisel(text));
	printf(" Nejdelsi slovo: %d\n", maxDelkaSlova(text));

	return 0;
}

int pocetPismen(char* text) {
	char* c;
	int pocet = 0;

	for (c = text; *c != '\0'; c++) {
		if (isalpha(*c)) pocet++;
	}

	return pocet;
}

int pocetCisel(char* text) {
	int delka = strlen(text);
	int pocet = 0;

	for (int i = 0; i <= delka; i++) {
		if (isdigit(text[i])) pocet++;
	}

	return pocet;
}

int maxDelkaSlova(char* text) {
	char* c;
	int delka = 0, delkaMax = 0;

	for (c = text; *c != '\0'; c++) {
		if (*c != ' ' && *c != '\0') {
			delka++;
			continue;
		}

		if (delka > delkaMax) {
			delkaMax = delka;
		}

		delka = 0;
	}


	return delkaMax;
}
