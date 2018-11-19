//EOF
#include <stdio.h>

int main(){

	/*while(1==1){ //program will never end, but it will copy all input
		int c = getchar();
		printf("%c", c);
	}*/
	int c;
	do { //In this way, we are able to end the problem
		c = getchar();
		printf("%c", c);
	} while (c != EOF)
}