//Lab05 ex 2
//Handle with some arrays
#include <stdio.h>

int main(){
	
	int array[10], sum, max;
	float ave;
	sum = 0;
	max = 0;
	for(int i = 0; i < 10; ++i){
		printf("Give me the number index %d\n", i);
		scanf("%d", &array[i]);
		sum += array[i];
		if(array[i] > max){
			max = array[i];
		}
	}
	ave = sum / 10;
	for(int i = 0; i < 10; ++i){
		printf("\n%d", array[i]);
	}
	printf("\nThe average is: %g\n", ave);
	printf("The maximum is: %d at indexes:\n", max);
	for(int i = 0 ; i < 10; ++i){
		if(array[i] == max){
			printf("%d ", i);
		}
	}

	return 0;
}