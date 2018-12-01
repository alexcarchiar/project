//lab5 ex 6

#include <stdio.h>
#define N 10
#define BLANK -1

int main(){

	int array[N], position[N], input;
	for(int j = 0; j<N; ++j)
		position[j] = BLANK;
	//is_negative = 0; //if one means there's a negative number
	int i = 0;
	while(i<N){
		printf("Give number:\n");
		scanf("%d", &input);
		if(input >= 0){
			array[i] = input;
			i++;
		} else{
			break;
		}
	}
	printf("Give value to check:\n");
	scanf("%d", &input);
	printf("positions:\n");
	for(int j = 0; j < i; ++j){
		if(input == array[j]){
			position[j] = j;
			printf("%d ", j);
		} else if (input < 0){
			break;
		}
	}


	return 0;
}
