//Pascal's triangle
/* Should be able to build a triangle like this one:
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
  .........
  I'm already able to build the correct shape, how to build the numbers??? */
#include <stdio.h>
#define SIZE 128
#define BLANK 0

int main(){
	printf("What is your exponent?\n");
	int exponent;
	scanf("%d", &exponent);
	++exponent;
  ++exponent;
	/*for(int i = 0; i < exponent; ++i){ //prints the shape of the triangle and all the 1s.
		int j = 2 + exponent;
		while(j > i){
			printf(" ");
			j--;
		}
		printf("1 ");
		for(int k = 0; k < (i - 1); ++k){
			printf("* ");
		}
		if(i > 0){
			printf("1\n");
		} else {
			printf("\n");
		}
	} */
	//try to create
	int line[SIZE] = {1, 1};
	int temp[SIZE] = {1};
	for(int i = 1; i <= exponent; ++i){ //prints the shape of the triangle and all the 1s.
		int j = 1 + exponent;
		while(j > i){
			printf(" ");
			j--;
		}
		
		if(i > 1){
			for(int k = 0; k <= i; ++k){
				if(line[k] != BLANK)
					printf("%d ", line[k]);
			}
		}
		printf("\n");
		for(int t = 1; t < i; ++t){
			temp[t] = line[t] + line [t-1];
			}
		for(int z = 1; z <= i; ++z){
			line[z] = temp[z];
		}
	}


	return 0;
}
