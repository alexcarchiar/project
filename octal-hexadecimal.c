#include <stdio.h>

int main(){
	int x = 10;
	printf("Decimal: %d\n", x);
	printf("Octal: %o\n", x);
	printf("Hexadecimal lowercase: %x\n", x);
	printf("Hexadecimal uppercase: %X\n", x);
  	int x_ = 0x10;
	printf("Decimal: %d\n", x_);
	printf("Octal: %o\n", x_);
	printf("Hexadecimal lowercase: %x\n", x_);
	printf("Hexadecimal uppercase: %X\n", x_);
	return 0;
}