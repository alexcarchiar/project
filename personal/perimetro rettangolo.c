#include <stdio.h>
//Programma per calcolare il perimetro del rettangolo
int main()
{

	float base, altezza, perimetro;
	printf("Calcolo il perimetro del rettangolo.");
	printf("\nDammi la base");
	scanf("%f", &base);
	printf("\nDammi l'altezza");
	scanf("%f", &altezza);
	perimetro = 2*(base + altezza);
	printf("Il perimetro è: %f", perimetro);

	return 0;
}
