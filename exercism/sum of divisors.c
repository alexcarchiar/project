//Sum of Multiples from exercism
//sum the multpiles of multiples of a few numbers form keyboard up to a certain number from keyboard
#include <stdio.h>

int main(){

	int maximum_number, num_of_divisors, sum, verified_multiple;
	sum = 0;
	verified_multiple = 0;
	printf("What is the maximum number? (Note that it will not be included among the multiples)");
	scanf("%d", &maximum_number);
	printf("How many divisors do you have?\n");
	scanf("%d", &num_of_divisors);
	int multiples[maximum_number], divisors[num_of_divisors], array[maximum_number];
	printf("Give the divisors:\n");
	for(int i = 0; i < num_of_divisors; ++i){
		scanf("%d", &divisors[i]);
		printf("\n");
	}
	for (int i = 0; i < maximum_number; ++i){
		array[i] = i;
	}
	for (int i = 0; i < maximum_number; ++i){
		verified_multiple = 0;
		for(int j = 0; j < num_of_divisors; ++j){
			if( (array[i] >= divisors[j])&&(array[i] % divisors[j]) == 0){
				verified_multiple = array[i];
			}
		}
		sum += verified_multiple;
	}
	printf("The sum is: %d", sum);

	return 0;
}
