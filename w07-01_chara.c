#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	printf("Hello ASCII world\n");
	char c;
	printf("Insert a char: ");
	scanf("%c", &c);

	printf("%c\n", c);
	printf("%d\n", c);

	//if(c>= '0'&&c<='9')
	if(isdigit(c))
		printf("C is a number\n");
	if(isalnum(c)) //alnum means c is either a number or a letter (both capital and lower)
		printf("Hey it's alnum!\n")

	return 0;
}