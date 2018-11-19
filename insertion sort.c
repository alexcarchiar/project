//insertion sort
//Lab06 04
#include <stdio.h>

#define N 5

int main(){

	int v[N], temp;
	printf("Insertion sort.\n");
	for(int i = 0; i<N; ++i)
		scanf("%d", &v[i]);
	for(int i = 1; i < N; ++i){
		for(int j = i; j > 0 && v[j-1] > v[j] ; --j){
			temp = v[j-1];
			v[j-1] = v[j];
			v[j] = temp; 
		}
	}

	printf("\n");
	for(int i = 0; i<N; ++i)
		printf("%d\n", v[i]);

	return 0;
}