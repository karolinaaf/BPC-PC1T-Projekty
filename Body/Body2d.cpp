#include <math.h>
#include <limits.h>
#include <stdio.h>

int indexNejblizsi(int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	int nejblizsi_index;
	double vzdalenost, nejblizsi_vzdalenost = LONG_MAX;

	for (int i = 0; i < velikost; i++) {
		vzdalenost = sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));

		if (vzdalenost < nejblizsi_vzdalenost) {
			nejblizsi_index = i;
			nejblizsi_vzdalenost = vzdalenost;
		}
	}

	return nejblizsi_index;
}

double prumernaVzdalenost(int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	double vzdalenost = 0;

	for (int i = 0; i < velikost; i++) {
		vzdalenost += sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));
	}

	return vzdalenost / velikost;
}

void bodyVBlizkosti(int maxVzdalenost, int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	double vzdalenost;
	int pocetBoduVBlizkosti = 0;
	
	for (int i = 0; i < velikost; i++) {
		vzdalenost = sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));

		if (vzdalenost <= maxVzdalenost) {
			printf("Bod[%d, %d] ", poleBodu[i][0], poleBodu[i][1]);
			pocetBoduVBlizkosti++;
		}
	}

	if (pocetBoduVBlizkosti == 0) printf("V blizkosti nejsou zadne body");
}