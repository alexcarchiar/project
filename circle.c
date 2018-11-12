#include <stdio.h>
#include <stdlib.h>
#define RADIUS 5
int main()
{
    for(int i = 0; i< RADIUS * 2+1; i++){
        for(int j = 0; j < RADIUS * 2 + 1; j++){
            if( ((i-5)*(i-5) + (j-5)*(j-5) <= RADIUS*RADIUS + 2 )&& ((i-5)*(i-5) + (j-5)*(j-5) >= RADIUS*RADIUS - 2))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
