//lab10 ex05

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE_MAT 5

int main(){
    
    
    
    int number;
    int lenght_of_sequence;
    int matrix[SIZE_MAT][SIZE_MAT];
    char reader[SIZE_MAT][10];
    
    //Getting input from file
    FILE *fin = fopen("/Users/alexcarchiar/Desktop/matrix.alexcarchiar", "r");
    for(int i = 0; i<SIZE_MAT; ++i){
        fgets(reader[i], 10, fin);
        sscanf(reader[i], "%d %d %d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4]);
    }
    
    printf("What number do you wanna check?\n");
    scanf("%d", &number);
    printf("Lenght of sequence?\n");
    scanf("%d", &lenght_of_sequence);
    
    for(int i = 0; i<SIZE_MAT; ++i){ // print matrix
        for(int j = 0; j<SIZE_MAT; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    
    
    /*for(int i = 0; i<SIZE_MAT; ++i){ //checking rows
     for(int j = 0; j<SIZE_MAT; ++j){
     if(matrix[i][j] == number && matrix[i][j+1] == number && matrix[i][j+2] == number){
     printf("The sequence is found in row %d\n", i);
     j = SIZE_MAT;
     }
     }
     }
     for(int i = 0; i<SIZE_MAT; ++i){ //checking coloumns
     for(int j = 0; j<SIZE_MAT; ++j){
     if(matrix[j][i] == number && matrix[j+1][i] == 0 && matrix[j+2][i]){
     printf("The sequence is found in coloumn %d\n", i);
     j = SIZE_MAT;
     }
     }
     } */
    
    for(int i = 0; i<SIZE_MAT; ++i){ //checking rows
        int equal = 0;
        for(int j = 0; j<SIZE_MAT; ++j){
            if(matrix[i][j] == number){
                for(int k = j; k<j+lenght_of_sequence; ++k){ //once it finds a value equal to number, it checks if the subsequent values are also equal up to the desired lenght of the sequence
                    if(matrix[i][k] == number)
                        ++equal;
                }
            }
            if(equal == lenght_of_sequence)
                printf("The sequence is found in row %d\n", i);
        }
    }
    
    for(int i = 0; i<SIZE_MAT; ++i){ //checking coloumns
        int equal = 0;
        for(int j = 0; j<SIZE_MAT; ++j){
            if(matrix[j][i] == number){
                for(int k = j; k<j+lenght_of_sequence; ++k){ //once it finds a value equal to number, it checks if the subsequent values are also equal up to the desired lenght of the sequence
                    if(matrix[k][i] == number)
                        ++equal;
                }
            }
            if(equal == lenght_of_sequence)
                printf("The sequence is found in coloumn %d\n", i);
        }
    }
    return 0;
}
