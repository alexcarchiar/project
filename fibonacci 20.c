//Lab04_5
//print first 20 values of Fibonacci series

#include <stdio.h>

int main() {

	int xn, xn_1, temp;
	xn = 0;
	xn_1 = 1;
	printf("%d %d ", xn, xn_1);
	for(int i = 0; i < 18; i++){
		temp = xn_1;
		xn_1 += xn;
		xn = temp;
		printf("%d ", xn_1);
	}

	return 0;
}