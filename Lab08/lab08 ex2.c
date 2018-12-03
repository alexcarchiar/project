//Lab08 ex2
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 15

//protos
void lower_case(char *string);
void replace_non_alnum(char *string);
void replacing_num(char *string);


int main(){ //version 1
    printf("Insert string\n");
    char string[N];
    int num_words = 0;
    for(int i = 0; i<N; ++i)
        string[i] = getchar();
    
    lower_case(string);
    replace_non_alnum(string);
    replacing_num(string);
    
    for(int i = 0; i<N; ++i){
        if(isalpha(string[i]) && i == 0)
            ++num_words;
        if(isalpha(string[i]) && string[i-1] == '_'){
            ++num_words;
        }
        printf("%c", string[i]);
    }
    
    printf("\nNum words: %d\n", num_words);
    
    return 0;
}

/* version 2 the order affects the output
 int main(){
 	printf("Insert string\n");
    char string[N];
    int num_words = 0;
    for(int i = 0; i<N; ++i)
        string[i] = getchar();
    
    lower_case(string);
    replacing_num(string);
    replace_non_alnum(string);
    
    
    for(int i = 0; i<N; ++i){
        if(isalpha(string[i]) && i == 0)
            ++num_words;
        if(isalpha(string[i]) && string[i-1] == '_'){
            ++num_words;
        }
        printf("%c", string[i]);
    }
    
    printf("\nNum words: %d\n", num_words);

 return 0;
 }
 */

void lower_case(char *string){
    for(int i = 0; i<N; ++i){
        string[i] = tolower(string[i]);
    }
    
    return;
}

void replace_non_alnum(char *string){
    for(int i = 0; i<N; ++i){
        if(!isalnum(string[i]))
            string[i] = '_';
    }
    
    return;
}

void replacing_num(char *string){
    for(int i = 0; i<N; ++i){
        if(isdigit(string[i]))
            string[i] = '*';
    }
    
    return;
}
