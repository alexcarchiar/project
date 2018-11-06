#include <stdio.h>
#define SIZE 128

int main(){
	//the idea is to use the modulus operator and add up the various remainders
    int binary[SIZE] = {0};
    int number;
    printf("Write the number:\n");
	scanf("%d", &number);
    printf("The binary number is: ");
    for(int i = 0; number > 0; ++i){
        binary[i] = number % 2;
        number = number / 2;
        printf("%d", binary[i]);
    }
	return 0;
}
