//Lab09 ex 06
//it works... Yay!
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define N 4

int matrix[N][N];
int fill_ring(int min, int max, int flag);

int main(){
    
    /*
     I need to like divide the matrix into sub-matrixes.
     The most extern matrix should be filled: [0][0], [0][1], [0][2], [0][3],
     [1][3], [2][3], [3][3], [3][2], [3][1], [3][0].
     Then, the inner matrix becomes: [1][1], [1][2], [2][2], [2][1]
     */
    int min = 0;
    int max = N-1;
    //this two coordinates are useful to fill up the matrix, min is the minimum
    //coordinate, max is the maximum one. We use a variable because it may change
    int flag = 0; //this flag variable is used in order to know if the matrix is completely filled
    int filled = N*N; //this indicates the total number of cells. If flag == filled,
    //then it means that the whole matrix is fool
    while(flag != filled){
        flag = fill_ring(min, max, flag);
        //have to decrease the number of max and increase min because the rings get smaller
        ++min;
        --max;
    }
    for(int i = 0; i<N; ++i){ //printing the matrix
        for(int j = 0; j<N; ++j){
            printf("%2d ", matrix[i][j]);
                   }
        printf("\n");
        }
    return 0;
}

int fill_ring(int min, int max, int flag){
    
    int number = 0;
    
    for(int i = min; i <= max; ++i){ //filling first horizontal line
        matrix[min][i] = ++number;
        ++flag;
    }
    
    for(int i = min+1; i<= max; ++i){ //starts at 1 because otherwise it would overwrite the cell matrix[min][max]; filling the first vertical line
        matrix[i][max] = ++number;
        ++flag;
    }
    
    for(int i = max-1; i >= min; --i){ //filling the second horizontal line
        matrix[max][i] = ++number; //i>min-1 in order to fill up to the left
        ++flag;
    }
    
    for(int i = max -1; i > min; --i){ //filling the vertical line; i> min not to overwrite the first cell we have written
        matrix[i][min] = ++number;
        ++flag;
    }
    
    return flag;
}
