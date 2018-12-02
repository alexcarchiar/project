//pow
//lab06 05
#include <stdio.h>

int main(){
	
	int base, exponent, result;
	printf("Base?\n");
	scanf("%d", &base);
	printf("Exponent?\n");
	scanf("%d", &exponent);
	printf("Result: ");
	if(exponent == 0){
		printf("1");
	} else if(exponent == 1){
		printf("%d", base);
	} else if (exponent == -1){
		printf("1/%d", base);
	} else if(exponent > 1){
		result = base;
		for(int i = 1; i<exponent; ++i){
			result *= base;
		}
		printf("%d", result);
	} else if(exponent < -1){
		result = base;
		for(int i = 1; i<-exponent; ++i){
			result *= base;
		}
		printf("1/%d", result);
	}

	return 0;
}
