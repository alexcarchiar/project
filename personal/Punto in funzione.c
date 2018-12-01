#include <stdio.h>
#include <math.h>
//Programma per vedere se un punto appartiene ad una funzione
//Il programma è ancora in fase beta. Funziona per funzioni di rette (senza intercette) e inversamente proporzionali (senza parametro)

int main()
{
	float x, y, gino;
	printf("Dammi il punto di coordinate x e y");
	scanf("%f %f", &x, &y);
	printf("\n La funzione è nella forma: y = f(x). Dammi il secondo membro");
	scanf("%f", &gino);
	if (gino == y)
	{
		printf("\nIl punto appartiene alla retta\n");	
	}
	else 
	{
		printf("\nIl punto non appartiene alla retta");
	}

	return 0;
}
