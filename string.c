//strings
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME 20

int main(){
	char prof[] = "Giovanni"
	char name[MAX_NAME + 1]; //add +1 for the NULL; it is recommened to leave it explicit
	printf("What is your name? ");
	scanf("%s", name); //Magic: no &; scanf() is reading tokens: a group of non space chars surrounded by space chars
	//equal to
	//gets(name) but this takes all the characters, even the non-tokens.
	/* long way
	if(name[0] >= 'a' && name[0] <= 'z') //This makes sure we print the string with a first capital letter
		name[0] = name[0] - 'a' + 'A';
	printf("Hello %s, how are you?"); */
	//short way
	name[0] = toupper(name[0]); //toupper is a macro, we can think of it as a predefined function
	/* This piece of code doesn't work because strings (arrays) aren't basic types 
	if (name == prof){
		printf("Yay!\n");
	}*/
	if(strcmp(name, prof) == 0) //strcmp is 0 if arrays are equal, 1 if different
		printf("Yay!\n");
	for(int i = 0; i<MAX_NAME; ++i){ //It shows that NULL = 0 and we have garbage values after 0
		printf("\n%d (%c)", name[t], name[t]);
	}
}