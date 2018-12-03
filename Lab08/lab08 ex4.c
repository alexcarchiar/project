//Lab08 ex4
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 60
#define MAX_NUM_WORDS 5
#define EXIT_SUCCESS 1

int main(){
    int num_words, num_alpha_char;
    num_alpha_char = 0;
    float ave_lenght = 0.0;
    char string[MAX+1];
    char char_in_word[5] = {0, 0, 0, 0, 0};
    int temp_i = 0;
    printf("Insert your line\n");
    gets(string);
    num_words = 0;
    int is_word = 0; //0 means not a word, 1 means we have a word
    for(int i = 0; i<MAX && string[i-1] != '\n'; ++i){ //basically it's a word counter
        if(isalpha(string[i]) == EXIT_SUCCESS && is_word == 0){
            is_word = 1;
            ++num_words;
            temp_i = i;
            char_in_word[num_words-1] = 1;
        } else if(!(isalpha(string[i]) == EXIT_SUCCESS)){
            is_word = 0;
        } else if(is_word==1){ //counts chars in every word
            char_in_word[num_words-1]++;
        }
    }
    if(num_words > 5){
        printf("You inserted too many words\n");
    } else{
        printf("The string contains %d words\n", num_words);
        for(int i = 0; i<MAX && string[i-1] != '\n'; ++i){
            if(isalpha(string[i]))
                ++num_alpha_char;
        }
        ave_lenght = (float)num_alpha_char / (float)num_words;
        printf("The average word length is %g characters \n", ave_lenght);
        for(int i = 0; i<num_words; ++i){
            int equal_lenght = 0;
            int word_lenght = char_in_word[i];
            for(int j = i; j<num_words; ++j){
                if(char_in_word[i] == char_in_word[j]){
                    equal_lenght++;
                    if(j!=i) //to make sure we do not change the value at index i
                        char_in_word[j] = 0;
                }
            }
            if(equal_lenght == 1 &&word_lenght > 0)
                printf("%d word of %d characters\n", equal_lenght, word_lenght);
            else if(equal_lenght > 1 &&word_lenght > 0){
                printf("%d words of %d characters\n", equal_lenght, word_lenght);
            }
        }
    }
}
