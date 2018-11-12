#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Draw square 1\n");
    int columns;
    int rows;
    scanf("%d", &rows);
    scanf("%d", &columns);

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
