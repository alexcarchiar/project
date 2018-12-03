//lab08 ex6
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


int main(){
    
    int sequences[MAX+1][MAX+1];
    int flag_eof = 0; //means the eof has not been input
    int counter_of_sequences = 0;
    
    for(int i = 0; i<MAX+1 && flag_eof == 0; ++i){ //getting the sequences
        printf("Insert sequence index %d\n", i);
        int flag_new_line = 0; //means the new line has not been input
        for(int j = 0; j<MAX+1 && flag_new_line == 0; ++j){
            sequences[i][j] = getchar();
            if(sequences[i][j] == '\n'){
                flag_new_line = 1;
            } else if(sequences[i][j] == EOF){
                flag_new_line = 1;
                flag_eof = 1;
            }
        }
        counter_of_sequences = i;
    }
    for(int i = 0; i<counter_of_sequences; ++i){//prints the sequences
        for(int j = 0; j<MAX+1 && sequences[i][j-1] != '\n'; ++j){
            if(sequences[i][j] == 'c' && sequences[i][j+1] == 'h'){ //checks the ch
                printf("k");
                ++j; //need to skip an iteration
            } else if(sequences[i][j] == sequences[i][j+1]){ //checks the doubles
                printf("%c", sequences[i][j]);
                ++j; //need to skip an iteration
            } else{
                printf("%c", sequences[i][j]);
            }
        }
    }
    
    return 0;
}
