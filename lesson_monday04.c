#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**int bob = 0; //init
    while (bob < 10) { //condition
        printf(" %d", bob); //body
        bob++; //closing update
    }
    printf("\n"); **/

    for(int alice = 0; alice < 10; alice++) {
        for(int bob = 0; bob < 10; bob++) {
            printf("%4d", (1 + alice) * (1 + bob));
        }
        printf("\n");
    }
    double g = 3.2;
    printf("%14.7f", g);
    //while and for are basically the same
    return 0;
}
