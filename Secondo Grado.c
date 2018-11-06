#include <stdio.h>
#import <math.h>
//Versione 2.0 del mio risolutore di equazioni di secondo grado: ora anche i numeri complessi
int main()
{
	float a, b, c, delta, x, y;
	printf("Risolutore di equazioni fino al grado 2\nL'equazione deve essere nella forma ax^2 + bx + c = 0");
	printf("\nDammi a: ");
	scanf("%f", &a);
	printf("\nDammi b: ");
	scanf("%f", &b);
	printf("\nDammi c: ");
	scanf("%f", &c);
	if (a==0)
	{
		x = -c/b;
		printf("La soluzione e':\nx1 = ");
		printf("%f", x );
	}
	else
	{
		delta = b*b - 4 * a * c;
		if (delta > 0)
		{
			x = (-b - sqrt(delta))/(2*a);
			y = (-b + sqrt(delta))/(2*a);
			printf("Le soluzioni sono:\nx1 = ");
			printf("%f", x );
			printf("\nx2 = ");
			printf("%f", y);
		}
		else if (delta ==0)
		{
			x = -b/(2*a);
			printf("La soluzione e':\nx1 = ");
			printf("%f", x );
		}
		else if (delta < 0)
		{
			printf("Le soluzioni sono numeri complessi\n");
			delta = sqrt(-delta)/(2*a);
			x = -b/(2*a);
			y = x;
			printf("x1= ");
			printf("%f", x );
			printf(" - ");
			printf("%f", delta);
			printf("i \n");
			printf("x2= ");
			printf("%f", y );
			printf(" + ");
			printf("%f", delta);
			printf("i \n");

		}
	}
	return 0;
}