//lab05 ex 5
//determine growing sequence of three numbers
#include <stdio.h>
#define N 4

int main(){
	int array[N], position, flag;
	flag = 0;
	for(int i = 0; i < N; ++i){
		printf("Give number:\n");
		scanf("%d", &array[i]);
		if((i > 1)&&(array[i] > array[i-1]) && (array[i-1] > array[i-2])){
			position = i - 2;
			flag = 1;
		}
	}
	if(flag == 1){
		printf("The series is: %d %d %d\n", array[position], array[position + 1], array[position + 2]);
		printf("The starting position is: %d", position);
	}
	return 0;
}
