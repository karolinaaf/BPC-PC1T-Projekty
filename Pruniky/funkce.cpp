int prunik(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec) {
	double zacatek = 0, konec = 0, temp = 0;

	if (!(zacatek1 <= konec1)) {
		temp = zacatek1;
		zacatek1 = konec1;
		konec1 = temp;
	}

	if (!(zacatek2 <= konec2)) {
		temp = zacatek2;
		zacatek2 = konec2;
		konec2 = temp;
	}

	if (!(zacatek1 < zacatek2)) {
		temp = zacatek1;
		zacatek1 = zacatek2;
		zacatek2 = temp;

		temp = konec1;
		konec1 = konec2;
		konec2 = temp;
	}


	if (konec1 < zacatek2) return 0;

	if (zacatek1 <= zacatek2 && konec1 >= konec2) {
		*vysl_zacatek = zacatek2;
		*vysl_konec = konec2;

		return 1;
	}

	if (konec1 >= zacatek2) {
		if (konec1 < konec2) konec = konec1;
		else konec = konec2;

		*vysl_zacatek = zacatek2;
		*vysl_konec = konec;

		return 1;
	}
}