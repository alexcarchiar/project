//print char in string
#include <stdio.h>
#include <ctype.h>

void print_char(char s[]){
	int pos = 0;
	while(s[pos] != '\0'){
		printf("%d (%c)\n", s[pos], s[pos]);
		++pos;
	}
	return;
}

int main(){
	char str[] = "Rosario compra lo shampoo!";
	print_char(str);
	printf("There are %d tokens\n", count_tokens(str));
	return 0;
}

int count_tokens(char string[]){
	int words = 0;
	for(int i = 0; string[i] |= '\0'; ++i){
		if(!isspace(string[i]) && 
		(isspace(string[i+1] || string[i] == '\0')))
			++words;
	}
	return words;
}