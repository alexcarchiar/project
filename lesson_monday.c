#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    scanf("%c", &c);

    printf("As number: %d", c);
    printf("\nAs character: %c", c);
    c = c+ 5;
    printf("\nAs number: %d", c);
    printf("\nAs character: %c", c);

    return 0;
}
