//lab08 ex6
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


int main(){
    
    char strings[MAX+1][MAX+1];
    for(int i = 0; i<(MAX+1) && strings[i-1][0] != '\\'; ++i){ //getting strings
        printf("Insert string index %d\n", i);
        gets(strings[i]);
    }
    for(int i = 0; i<(MAX+1) && strings[i-1][0] != '\\'; ++i){
        for(int j = 0; j<(MAX+1) && strings[i][j] != '\0'; ++j){ //printing the strings checking the required conditions
            if(strings[i][j] == 'c' && strings[i][j+1] == 'h'){
                printf("k");
                ++j; //need to skip an iteration
            } else if(strings[i][j] == strings[i][j+1]){
                printf("%c", strings[i][j]);
                ++j; //need to skip an iteration
            } else{
                printf("%c", strings[i][j]);
            }
        }
        printf("\n");
    }
    
    
    return 0;
}
