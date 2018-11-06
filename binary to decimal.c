//program to convert binary numbers into decimal
#include <stdio.h>
#define MAX_DIGITS 128

int main(){
	
	int num_digits;
	int number[MAX_DIGITS];
	int quantity;

	printf("How many digits?\n");
	scanf("%d", &num_digits);
	//input
	for(int i = 0; i<num_digits; ++i){
		scanf("%d", &number[i]);
	}

	printf("You entered: ");
	for(int i = 0; i < num_digits; ++i){
		printf("%d", number[i]);
	}
	printf("\n");

	//conversion
	quantity = 0;
	int weight = 1;
	for(int i = num_digits; i >= 0; --i){
		quantity += number[i] * weight;
		weight *= 2;
	}
//output
	printf("\nYour number is: %d", quantity);

	return 0;
}