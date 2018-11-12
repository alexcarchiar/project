#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, t, s;
    printf("I make number triangles. Try me!\nGive me a number between 1 and 9. ");
    scanf("%d", &s);
    if (s < 1 || s > 9) {
        printf("You gave me a wrong number");
    } else {
        i = 1;
        while (i <= s) {
            printf("\n");
            t = 1;
            while (t <= i){
                printf("%d", i);
                ++t;
            }
            ++i;
        }
    }

    return 0;
}
