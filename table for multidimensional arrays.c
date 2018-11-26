#include <stdio.h>
#include <stdlib.h>

#define DIM 12
int Table[DIM][DIM] //all values are 0 because it is a global variable

void fill(void);
void print(void);
void sum_rows(int *rs);
void sum_coloumns(int *);

int main(){
	fill();
	print();

	int tmp_array[DIM];
	sum_rows(tmp_array); //or I  could have written sum_rows(&tmp_array[0])
	printf("\n");
	for(int i = 0; i<DIM; ++i)
		printf("%d ", tmp_array[i]);
	sum_coloumns(tmp_array);
	printf("\n");
	for(int i = 0; i<DIM; ++i)
		printf("%d ", tmp_array[i]);
	
	return 0;
}

void fill(void){
	for(int i = 0; i<DIM; ++i)
		for(int j = 0; j<DIM; ++j)
			Table[i][j] = (i+1) * (u+1);
	
	return;
}

void print(){
	for(int i = 0; i<DIM; ++i)
		for(int j = 0; j<DIM; ++j)
			print("%3d", Table[i][j]);
	
	return;
}

void sum_rows(){

	for(int i = 0; i<DIM; ++i)
		rs[i] = 0;
	for(int i = 0; i<DIM; ++i)
		for(int j = 0; j<DIM; ++j)
			rs[i] += Table [i][j];

	return;
}

void sum_coloumns(int *){
	for(int i = 0; i<DIM; ++i)
		rs[i] = 0;
	for(int i = 0; i<DIM; ++i)
		for(int j = 0; j<DIM; ++j)
			rs[i] += Table [j][i];

	return;
}