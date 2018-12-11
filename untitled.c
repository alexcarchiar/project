//from lecture
/*******PROBLEM SOMEWHERE; NEED TO REVISE*****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

//protos
int palindrome1(const char *word);
void strip(const char *word; char tmp);
int palindrome2(const char *w1);

int main(){
    
    char word[MAX_LEN];

    scanf("%s", word);

    if(palindrome2(word)){
    	printf("The word is palindrome!\n");
    }
    
    
    return 0;
}

int palindrome2(const char *w1){ //good for single words
	int len = strlen(word);
    int palindrome = 1;
    for(int i = 0; i<len; ++i){
        if(toupper(w1[t]) != toupper(word[len-i-1]))
            palindrome = 0;
    }
    
	return strcmp(tw1, tw2) == 0; //strcmp returns 0 if the strings are equal, >0 if the first is greater, <0 if the second is greater
	//the "==" checks if the return value and 0 are equal, if they are, palindrome1 returns 1
} 

int palindrome1(const char *word){
    char tmp[MAX_LEN];
    strip(word, tmp);
    return palindrome2(tmp);
}

void strip(const char *word, char *word2){

    int iw, iw2;
    iw = iw2 = 0;
    while(word[iw] != '\0'){
        if(alnum(word[iw])){
            word2[iw2++] = toupper(word[iw]);
        }
        ++iw;
    }
    word2[iw] = '\0';
}