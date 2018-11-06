#include <stdio.h>

int main()
{
	float conto, interesse;
  	int giorni;
  	printf("Dai il valore del conto, dell'interesse annuo e dei giorni \n");
    scanf("%f %f %d", &conto, &interesse, &giorni);
  	interesse= 1+interesse/100;
  	interesse = ((conto*interesse) - conto)/365;
    conto = conto + interesse*giorni;
  	printf("Al giorno %d il conto sarà:", giorni);
  	printf("%f", conto);	
	return 0;
}