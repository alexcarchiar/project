#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    printf("Absolute value. Give me a number\n");
    scanf("%g", &num);
    if (num < 0) {
        num = - num;
    }
    printf("\nThe absolute value is: %g", num);
    return 0;
}
