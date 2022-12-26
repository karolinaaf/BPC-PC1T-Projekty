// KomplexniCisla.cpp : Defines the entry point for the application.
//

#include "KomplexniCisla.h"


void soucet(double a[2], double b[2], double c[2]);
void rozdil(double a[2], double b[2], double c[2]);
void soucin(double a[2], double b[2], double c[2]);
void tisk(double c[2]);
void tisk2(double c[2]);


using namespace std;

int main() {
	double a[2], b[2], c[2];
	char select;

	printf("Vlozte realnou cast prvniho komplexniho cisla: ");
	scanf("%lf", &a[0]);
	printf("Vlozte imaginarni cast prvniho komplexniho cisla: ");
	scanf("%lf", &a[1]);
	printf("Vlozte realnou cast druheho komplexniho cisla: ");
	scanf("%lf", &b[0]);
	printf("Vlozte imaginarni cast druheho komplexniho cisla: ");
	scanf("%lf", &b[1]);

	printf("Zvolte operaci:\n+ pro soucet\n- pro rozdil\n* pro soucin\n");
	scanf(" %c", &select);

	if (select == '+') soucet(a, b, c);
	else if (select == '-') rozdil(a, b, c);
	else if (select == '*') soucin(a, b, c);
	else return 1;

	tisk(c);
	tisk2(c);

	return 0;
}

void soucet(double a[2], double b[2], double c[2]) {
	for (int i = 0; i < 2; i++) {
		c[i] = a[i] + b[i];
	}
}

void rozdil(double a[2], double b[2], double c[2]) {
	for (int i = 0; i < 2; i++) {
		c[i] = a[i] - b[i];
	}
}

void soucin(double a[2], double b[2], double c[2]) {
	c[0] = (a[0] * b[0]) - (a[1] * b[1]);
	c[1] = (a[0] * b[1]) + (a[1] * b[0]);
} 

void tisk(double c[2]) {
	printf("Vysledek je %.1lf + %.1lf i\n", c[0], c[1]);
}

void tisk2(double c[2]) {
	printf("Vysledek je %.1lf (cos(%.1lf) + i sin(%.1lf)) \n", sqrt(c[0] * c[0] + c[1] * c[1]), atan(c[1] / c[0]), atan(c[1] / c[0]));
}

