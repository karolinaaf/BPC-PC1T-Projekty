// pruniky.cpp : Defines the entry point for the application.
//

#include "pruniky.h"
#include "funkce.h"

#define POCET_INTERVALU 5


int main()
{
	double intervaly[POCET_INTERVALU][4] = {
		1.5, 2.8, 1.6, 2.0,
		1.5, 2.8, 3.6, 7.5,
		1.5, 4.8, 2.6, 7.5,
		3.0, 6.0, 1.5, 9.0,
		3.0, 6.0, 4.0, 2.0
	};

	double vysl_zacatek = 0;
	double vysl_konec = 0;
	int exists = 0;

	for (int i = 0; i < POCET_INTERVALU; i++) {
		exists = prunik(intervaly[i][0],
			intervaly[i][1],
			intervaly[i][2],
			intervaly[i][3],
			&vysl_zacatek,
			&vysl_konec);

		if (exists == 1) printf("Prunik intervalu (%0.1lf,%0.1lf) a (%0.1lf,%0.1lf) je (%0.1lf,%0.1lf).\n", intervaly[i][0], intervaly[i][1], intervaly[i][2], intervaly[i][3], vysl_zacatek, vysl_konec);
		else if (exists == 0) printf("Prunik intervalu (%0.1lf,%0.1lf) a (%0.1lf,%0.1lf) neexistuje.\n", intervaly[i][0], intervaly[i][1], intervaly[i][2], intervaly[i][3]);
		else printf("Neco slo spatne\n");

	}

	return 0;
}
