#include <stdio.h>

int main(){

	printf("Type 1 char: \n");
	int c = getchar(); 
	printf("Hey! You typed %d (%c)\n,c c");
	//the program gives command to the OS. We type what we need and then press enter: we fill up a pipe
	//every tipe we call getchar() we pick one item of the pipe, one at a time, in order.
	return 0;
}