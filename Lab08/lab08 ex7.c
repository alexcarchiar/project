//lab08 ex7

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE_MAT 5

int main(){

    int number;
    int lenght_of_sequence;
    int matrix[SIZE_MAT][SIZE_MAT];

    for(int i = 0; i<SIZE_MAT; ++i){ //scanning matrix
        printf("Insert row index %d\n", i);
        for(int j = 0; j<SIZE_MAT; ++j)
            scanf("%d", &matrix[i][j]);

    }
    printf("\n");
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

    // searching rows
    for(int i=0; i<SIZE_MAT; i++){
        int j = 0;
        int found = 0;
            for(int j = 0; j<SIZE_MAT && !found; ++j){
                int counter = 0;

                for(int k = j; matrix[i][k] == number && !found; ++k){ //it picks up a subsequence and tries to find if it is of the required lenght
                    counter++;
                    if (counter >= lenght_of_sequence) {
                    printf("Sequence found in row %d\n", i);
                    found = 1;
                }
                }
            }
    }
    //searching in a coloums
    for(int i=0; i<SIZE_MAT; i++){
        int j = 0;
        int found = 0;
            for(int j = 0; j<SIZE_MAT && !found; ++j){
                int counter = 0;

                for(int k = j; matrix[k][i] == number && !found; ++k){ //it picks up a subsequence and tries to find if it is of the required lenght
                    counter++;
                    if (counter >= lenght_of_sequence) {
                    printf("Sequence found in coloumn %d\n", i);
                    found = 1;
                }
                }
            }
    }
    return 0;
}
