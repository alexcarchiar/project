//Lab 07 ex 7
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define EXIT_SUCCESS 1
#define MAX 256



int main(){
    
    int string[MAX];
    int num_lines, num_words, is_word;
    float average_lenght = 0.0;
    is_word = num_lines = num_words = 0;
    printf("Insert your string\n");
    for(int i = 0; i<MAX && string[i-1] != EOF; ++i)
        string[i] = getchar();
    for(int i = 0; i<MAX && string[i-1] != EOF; ++i){
        if(string[i] == '\n')
            ++num_lines;
        if(isalpha(string[i]) == EXIT_SUCCESS && is_word == 0){
            is_word = 1;
            ++num_words;
        } else if(!(isalpha(string[i]) == EXIT_SUCCESS))
            is_word = 0;
        if(isalpha(string[i])==EXIT_SUCCESS)
            ++average_lenght;
    }
    printf("Number of lines: %d\nNumber of words: %d\nAverage length of a word: %.2g\n", num_lines, num_words, average_lenght/num_words);
    
    
    return 0;
}
