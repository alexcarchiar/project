//Lab08 ex 01
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 4095
#define EXIT_SUCCESS 1


int main(){
    
    char string[MAX+1], string_contained[MAX+1];
    int counter = 0;
    int num_or_alpha = 0;
    int counter_contained = 0;
    char flag = 0; //used to check if the second string is contained into the first one; 0 means no
    
    
    printf("Insert your first string\n");
    scanf("%s", string);
    while(string[counter] != '\0'){ //checking alphanumeric chars and counting the lenght of the string
        if(isalnum(string[counter])== EXIT_SUCCESS)
            ++num_or_alpha;
        ++counter;
    }
    printf("Insert your second string\n");
    scanf("%s", string_contained);
    while(string_contained[counter_contained] != '\0')
        ++counter_contained;
    
    
    
    for(int i = 0; i<counter; ++i){ //checking if the second  string is contained in the first
        int counter_same_letters = 0;
        for(int j = 0; j<(counter_contained); ++j)
            if(string[i+j] == string_contained[j]){
                ++counter_same_letters;
                if(counter_same_letters == counter_contained)
                    ++flag;
            }
        if(flag > 0)
            i = counter;
    }
    
    
    
    printf("There are %d characters in the string\n", counter);
    printf("There are %d alphanumeric characters\n", num_or_alpha);
    
    if(flag){
        printf("The second string is contained\n");
    } else{
        printf("The string is not contained\n");
    }
    
    
    
    return 0;
}
