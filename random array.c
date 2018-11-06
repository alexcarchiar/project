#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define SIZE 15

int main(){

	int array[SIZE]; //generating a random sequence
  int second = time(NULL);
 srand(second);
	for(int i = 0; i<SIZE; ++i){
		array[i] = rand() %100;
		printf("%d ", array[i]);
	}

	//count 42s
	int counter = 0;
	for(int t = 0; t<SIZE; ++t){
		if(array[t] == 42){
			++counter;
		}
	}
  printf("\n The number is: %d", counter);

  printf("\nMax random number is: %d", RAND_MAX);

	return 0;
}