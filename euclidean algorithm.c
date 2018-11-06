//lab05 exercise 1
//find the MCD using the Euclidean algorithm

#include <stdio.h>

int main(){
	int a, b, temp, counter, flag; //the two numbers and a temporary variable
	printf("I compute the MCD. Write the first number:\n");
	scanf("%d", &a);
	printf("Write the second number:\n");
	scanf("%d", &b);
	if(a < b){ //used to make sure that a is the maximum, useful to exectute the while
		temp = a;
		a = b;
		b = temp;
	}
	counter = flag = 0;
	do{
		temp = a % b;
		a = b;
		b = temp;
		++counter;
		if(temp == 0)
			++flag;
	}while(flag == 0);
	if(counter > 1){
		printf("The MCD is: %d", a);
	} else
		printf("The MCD is: 1");

	return 0;
}