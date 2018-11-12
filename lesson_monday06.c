#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Draw triangle 1\n");
    int rows;
    scanf("%d", &rows);

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < r + 1; c++){
            printf("#");
        }
        printf("\n");
    }
    for(int r = 1; r < rows; r++){
        for(int c = 0; c < rows - r; c++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
