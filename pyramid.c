#include <stdio.h>
#include <stdlib.h>

int main()
{
    int order, i, t, s;
    printf("Hi! I make asterisk pyramids!\n Give me the order of the pyramid: ");
    scanf("%d", &order);
    i = 1;
    while(i <= order) {
        t = 1;
        s = 1;
        while(t <= (order - i)) {
               printf(" ");
               ++t;
        }
        while (s <= i){
                printf("* ");
                ++s;
        }
        printf("\n");
        i++;
    }

    return 0;
}
