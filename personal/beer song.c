#include <stdio.h>
#include <stdlib.h>
#define BEERS 99
int main()
{
    int i = BEERS;
    int j = i- 1;
    while(i > 0){
            if(j == 0){
                printf("1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall\n");
            }
        printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n", i, i, j);
        j--;
        i--;
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottles of beer on the wall.\n", BEERS);
    return 0;
}
