//lab08 ex7
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(){
    
    int matrix[5][5];
    for(int i = 0; i<5; ++i){
        printf("Insert row index %d\n", i);
        scanf("%d %d %d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4]);
    }
    printf("\n");
    for(int i = 0; i<5; ++i){
        for(int j = 0; j<5; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
