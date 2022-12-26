// SoucinKomplexnichCisel.cpp : Defines the entry point for the application.
//

#include "SoucinKomplexnichCisel.h"

using namespace std;

int main()
{
	double real1 = 0, real2 = 0, imag1 = 0, imag2 = 0;

	printf("Zadejte realnou slozku 1: ");
	scanf("%lf", &real1);
	printf("Zadejte imaginarni slozku 1: ");
	scanf("%lf", &imag1);
	printf("Zadejte realnou slozku 2: ");
	scanf("%lf", &real2);
	printf("Zadejte imaginarni slozku 2: ");
	scanf("%lf", &imag2);

	double soucetReal = real1 + real2;
	double soucetImag = imag1 + imag2;

	printf("Soucet se rovna %lf + %lfi\n", soucetReal, soucetImag);

	return 0;
}
