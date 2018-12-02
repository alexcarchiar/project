//nth prime number
//give a number and it will give the nth prime number (ex: 3 is the second orime number, 7 is the fourth, etc
#include <stdio.h>
#define SIZE 256

int is_prime(int number);
int main(){
	int position, list_primes[SIZE];
	int j = 0;
	int i = 2;
	while(j<SIZE){ //loop to fill the array with prime numbers
	int flag = is_prime(i);
	if(flag == 1){
		list_primes[j] = i;
		++j;
		} 
	++i;
	}
	printf("Give me the nth postion of the prime number you're interested in: (remark that for the moment the maximum index is %d)\n", SIZE);
	int nth;
	scanf("%d", &nth);
	--nth;
	printf("The number you're looking for is: %d", list_primes[nth]);
	
	return 0;
}

int is_prime (int number){
	int num_of_divisors = 0;
	for(int i = 1; i <= number; ++i){
		if((number % i) == 0){
			num_of_divisors++;
		}
	}
	if (num_of_divisors < 3){
		return 1; //the number is prime
	} else {
		return 0; //the number is not prime
	}
}
