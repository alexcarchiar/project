#include <stdio.h>
#include <math.h>
// Programma per calcolare area e perimetro rombo date le diagonali

int main()
{
  printf("Per far funzionare il programma è necessario scrivere i numeri in cifre decimali o intere, arrotondando se necessario.");
  float dmag, dmin, lato, area, peri;
  printf("\nDammi le diagonali e ti calcolo perimetro e area del rombo\n");
  printf("Diagonale maggiore: ");
  scanf("%f", &dmag);
  printf("Diagonale minore: ");
  scanf("%f", &dmin);
  lato = (sqrt(dmag*dmag+dmin*dmin))/2;
  peri = lato*4;
  area = dmag*dmin*0.5;
  printf("Il perimetro vale: ");
  printf("%f", peri);
  printf("\nL'area vale: ");
  printf("%f", area);
		
	return 0;
}
