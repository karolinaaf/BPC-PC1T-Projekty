// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

int jePrestupny(int rok);
int jePrvocislo(int cislo);


using namespace std;

int main()
{
	printf("1000\t %d\n", jePrestupny(1000));
	printf("2000\t %d\n", jePrestupny(2000));
	printf("2002\t %d\n", jePrestupny(2002));
	printf("2012\t %d\n", jePrestupny(2012));
	printf("2022\t %d\n", jePrestupny(2022));
	printf("2200\t %d\n", jePrestupny(2200));

	printf("\n");

	for (int i = 1; i <= 10; i++) {
		printf("%d\t %d\n", i, jePrvocislo(i));
	}

	return 0;
}

int jePrestupny(int rok) {
	if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) return 1;
	else return 0;
}

int jePrvocislo(int cislo) {
	if (cislo == 1) return 0;

	for (int i = 2; i <= cislo - 1; i++) {
		if (cislo % i == 0) return 0;
	}

	return 1;
}
