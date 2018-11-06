#include <stdio.h>
#include <math.h>
//Programma per vedere se due rette sono paralleli, perpendicolari o incidenti
//Programma non terminato

int main()
{
	float m, q, n, r, x, y;
	printf("Ogni retta è nella forma y = mx + q. Ho bisogno del coefficiente m e del parametro q.\n m1 = ");
	scanf("%f", &m);
	printf("\n q1 = ");
	scanf("%f", &q);
	printf("Dammi la seconda retta. \n m2 = ");
	scanf("%f", &n);
	printf("\n q2 = ");
	scanf("%f", &r);
	if((m == 0 || n == 0) && q != r)
	{
		printf("Hai dato due rette parallele all'asse y. L'interezione è: I( ");
      x = (r - q)/(m - n);
		y = m * x + q;
		printf("%f", x);
		printf("; ");
		printf("%f", y);
		printf(")");      
	}
    else if (m == n)
	{
		printf(" Le rette sono parallele e dunque non hanno intersezioni\n");
	}
	else if (m == -1/n)
	{
		printf("Le rette sono perpendicolari. La loro intersezione e': I( ");
		x = (r - q)/(m - n);
		y = m * x + q;
		printf("%f", x);
		printf("; ");
		printf("%f", y);
		printf(")");
	}
	else if (m != n && m != -1/n)
	{
		printf("Le rette sono incidenti. La loro intersezione e': I( ");
		x = (r - q)/(m - n);
		y = m * x + q;
		printf("%f", x);
		printf("; ");
		printf("%f", y);
		printf(")");
	}

	return 0;
}