#include <stdio.h>
#include <stdlib.h>

//proto
int sum(int v[], int n_elem);

//global variables
#define DIM_X 3
#define DIM_Y 2
int array[DIM_X][DIM_Y] = {1, 2, 3, 4, 5, 5};

int main(){
	

	for(int i = 0; i<3; ++i)
		for(int j = 0; j<2; ++j)
			printf("%3d", array[i][u]);
		printf("\nSum: %d\n", sum());
	return 0;
}

//only good reason to use global variables
int sum(){
	int tot = 0;
	for(int t = 0; t<DIM_X; ++t)
		for(int u = 0; u< DIM_Y; ++u)
			tot += array[t][u]
		
	return tot;
}