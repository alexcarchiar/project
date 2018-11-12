#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("I calculate the fibonacci number of your choice\n");

    long a, b, c, i, n;
    printf("Give n\n");
    scanf("%l", &n);
    i = 0;
    printf ("Fibonacci: 0 1 ");
    b = 0;
    c = 1;
    while (i < n) {
        a = b;
        b = c;
        c = a + b;
        printf(" %d", c);
        ++i;
    }
    printf("\n");
    return 0;
}
