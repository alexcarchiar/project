//Lab04_3
//sum of input numbers until 0 is submitted

#include <stdio.h>

int main(){

	int sum, n;
	do{
		printf("Give me the number: \n");
		scanf("%d", &n);
		sum += n;
	} while(n != 0)
	printf("The sum is: %d", sum);

	return 0;
}
