#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char line[256];
	gets(line);

	for(int i = 0; line[i] != '\0'; ++i)
		printf("%s (len: %d)\n", &line[i], strlen(&line[i]));
	return 0;

}