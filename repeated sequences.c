//arrays containing same values with different orders
//Lab 06 ex 2
#include <stdio.h>

#define N 5

int main(){
	//Simple exercise
	int v1[N], v2[N], repeated_values[N]; //defining the arrays
	for(int i = 0; i<N; ++i){ //initializing repeated to 0, 1 means the number has been repeated
		repeated_values[i] = 0;
	}
	printf("Give the first array\n");
	for(int i = 0; i<N; ++i){
		printf("Value index %d\n", i);
		scanf("%d", &v1[i]);
	}
	printf("Give the second array\n");
	for(int i = 0; i<N; ++i){
		printf("Value index %d\n", i);
		scanf("%d", &v2[i]);
	}
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<N && repeated_values[i] == 0; ++j){
			if(v1[i]==v2[j]){
				repeated_values[i] = 1;
			}
		}
	}
	int flag = 0; //used to check if all repeated_values are 1
	for(int i = 0; i<N; ++i){
		if(repeated_values[i] == 1)
			++flag;
	}
	if(flag == N){
		printf("The sequences have the same values");
	} else{
		printf("The sequences do not have the same values");
	}
	return 0;
	/*
	//Repeating for further insight --> not done yet, there are bugs
	int v1[N], v2[N], repeated_values_v1_and_v2[N], repeated_values[N], times_repeated[N], not_in_sequence, flags[N]; //defining the arrays
	for(int i = 0; i<N; ++i){ //initializing repeated to 0, 1 means the number has been repeated
		repeated_values[i] = 0;
		flags[i] = 0;
	}
	printf("Give number which is not in the sequences:\n");
	scanf("%d", &not_in_sequence);
	printf("Give the first array\n");
	for(int i = 0; i<N; ++i){
		printf("Value index %d\n", i);
		scanf("%d", &v1[i]);
	}

	for(int i = 0; i<N; ++i){
		repeated_values[i] = not_in_sequence;
		times_repeated[i] = 0;
	}
	for(int i = 0; i<N; ++i){
		int n = -1;
		for(int j = 0; j<N; j++){
			if(v1[i] == v1[j]){
				++n;
			}
		}
		if(n > 0){
			int flag = 0;
			for(int j = 0; j<N; ++j){
				if(v1[i] == repeated_values[j])
					flag++;
			}
			if(flag == 0){
					repeated_values[i] = v1[i];
					times_repeated[i] = n;
				}
		}
	}

	printf("Give the second array\n");
	for(int i = 0; i<N; ++i){
		printf("Value index %d\n", i);
		scanf("%d", &v2[i]);
	}
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<N && repeated_values_v1_and_v2[i] == 0; ++j){
			if(v1[i]==v2[j]){
				repeated_values_v1_and_v2[i] = 1;
			}
		}
		if(repeated_values_v1_and_v2[i] == 1){
			int m = 0;
			for(int j = 0; j<N; ++j){
				if(v1[i] == v2[j]){
					++m;
				}
				if(m == repeated_values[i]){
					flags[i] = 1;
				}
			}
		}
	}
	int flag = 0; //used to check if all repeated_values are 1
	for(int i = 0; i<N; ++i){
		if(repeated_values_v1_and_v2[i] == 1 && flags[i] == 1)
			++flag;
	}
	if(flag == N){
		printf("The sequences have the same values");
	} else{
		printf("The sequences do not have the same values");
	}
	return 0; */
}