//lab10 ex05

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE_MAT 5


int main(){

    int number;
    int lenght_of_sequence;
    int matrix[SIZE_MAT][SIZE_MAT];
    char reader[10];

    //opening file
    FILE *fin = fopen("C:\\Users\\alexcarchiar\\Desktop\\matrix.alexcarchiar", "r");
    if(fin == NULL){
        printf("File not found\n");
        exit(1);
    }
    //getting input
    for(int i = 0; i<SIZE_MAT; ++i){
        fgets(reader, 11, fin);
        sscanf(reader, "%d %d %d %d %d", &matrix[i][0],  &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4]);
    }


    //closing file
    fclose(fin);
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
