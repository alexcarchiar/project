//Lab07 ex 3
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define EXIT_SUCCESS 1

#define MAX 128

int main(){
    int string[MAX], num_char, num_alpha, num_upper, num_digit, num_space, num_words;
    num_words =num_char = num_alpha = num_upper = num_digit = num_space = 0;
    int is_word = 0; //0 means not a word, 1 means we have a word
    printf("Write your sequence of characters\n");
    for(int i = 0; i<MAX && string[i-1] != '\n'; ++i){
        string[i] = getchar();
        ++num_char; //this way num_char counts \n as a character
        if(isalpha(string[i])== EXIT_SUCCESS)
            ++num_alpha;
        if(isupper(string[i])== EXIT_SUCCESS)
            ++num_upper;
        if(isdigit(string[i])== EXIT_SUCCESS)
            ++num_digit;
        if(isspace(string[i]) == EXIT_SUCCESS)
            ++num_space; //counts also the \n
        if(isalpha(string[i]) == EXIT_SUCCESS && is_word == 0){
            is_word = 1;
            ++num_words;
        } else if(!(isalpha(string[i]) == EXIT_SUCCESS))
            is_word = 0;
    }
    printf("Total characters: %d\n", num_char);
    printf("Total alphabetic characters: %d\n", num_alpha);
    printf("Total uppercase characters: %d\n", num_upper);
    printf("Total digits: %d\n", num_digit);
    printf("Total spacing characters: %d\n", num_space);
    printf("Number of words: %d\n", num_words);
    return 0;
}
