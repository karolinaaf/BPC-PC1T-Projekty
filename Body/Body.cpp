// Body.cpp : Defines the entry point for the application.
//

#include "Body.h"
#include "Body2d.h"

#define POCET_BODU 10


using namespace std;

int main()
{
	int body[POCET_BODU][2] = {
		{5,10},
		{-14,2},
		{45,4},
		{-9,8},
		{58,-3},
		{47,5},
		{-18,-86},
		{75,7},
		{-25,51},
		{17,98}
	};
	int Xref, Yref, max_vzdalenost;

	printf("Zadej souradnice referencniho bodu:\n");
	printf("Souradnice x:\n");
	scanf("%d", &Xref);
	printf("Souradnice y:\n");
	scanf("%d", &Yref);
	printf("Maximalni vzdalenost od referencniho bodu:\n");
	scanf("%d", &max_vzdalenost);
	printf("\n");

	int nejblizsi_index = indexNejblizsi(POCET_BODU, body, Xref, Yref);

	printf("Nejblizsi bod je [%d,%d]\n", body[nejblizsi_index][0], body[nejblizsi_index][1]);
	printf("Prumerna vzdalenost je %lf\n", prumernaVzdalenost(POCET_BODU, body, Xref, Yref));
	printf("Body v blizkosti:");

	bodyVBlizkosti(max_vzdalenost, POCET_BODU, body, Xref, Yref);

	return 0;
}
