// BourkovaKalkulacka.cpp : Defines the entry point for the application.
//

#include "BourkovaKalkulacka.h"

using namespace std;



int main()
{
	double cas;
	printf("Zadejte cas v sekundach: ");
	scanf("%lf", &cas);

	double vzdalenost = (cas * 340) / 1000;

	printf("Bourka je %lf kilometru daleko\n");

	return 0;
}
