#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HudbaDB.h"

void add(char* interpret, char* album, int rok, struct t_album** uk_prvni) // pridani alba
{
	struct t_album* noveAlbum; // ukazatel pro novy vkladany album
	struct t_album* aktAlbum; // ukazatel na aktualni album

	// alokace dynamicke promenne
	noveAlbum = (struct t_album*)malloc(sizeof(struct t_album));

	strcpy_s(noveAlbum->interpret, CHAR_ARRAY_SIZE, interpret); // naplneni struktury
	strcpy_s(noveAlbum->album, CHAR_ARRAY_SIZE, album);
	noveAlbum->rok = rok;
	noveAlbum->dalsi = NULL;

	if (*uk_prvni == NULL) // linearni seznam je prazdny
	{
		*uk_prvni = noveAlbum;
		return;
	}
	else if (strcmp(noveAlbum->interpret, (*uk_prvni)->interpret) < 0) // vlozime na zacatek
	{
		noveAlbum->dalsi = *uk_prvni;
		*uk_prvni = noveAlbum;
		return;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum) // prochazeni seznamu
	{
		if (aktAlbum->dalsi == NULL) // jsme na poslednim aute
		{
			aktAlbum->dalsi = noveAlbum; // pridavame na konec
			return;
		}
		else if (strcmp(noveAlbum->interpret, aktAlbum->dalsi->interpret) < 0)
		{
			noveAlbum->dalsi = aktAlbum->dalsi; // vlozime za aktAlbum
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi; // posun na dalsi album
	}
}

void del(char* interpret, struct t_album** uk_prvni)
{
	struct t_album* aktAlbum;

	while (*uk_prvni && strcmp((*uk_prvni)->interpret, interpret) == 0)
	{
		struct t_album* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni);  // uvolneni auta z pameti
		*uk_prvni = newPrvni;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum && aktAlbum->dalsi) // prochazeni seznamu
	{
		if (strcmp(aktAlbum->dalsi->interpret, interpret) == 0) // auto je ke smazani
		{
			struct t_album* newDalsi = aktAlbum->dalsi->dalsi;
			free(aktAlbum->dalsi);  // uvolneni alba z pameti
			aktAlbum->dalsi = newDalsi;
		}
		aktAlbum = aktAlbum->dalsi; // posun na dalsi album
	}
}