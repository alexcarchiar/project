#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b;
    printf("Give me two numbers\n");
    scanf("%lg",&a);
    scanf("%lg",&b);

    if (a > b) {
        printf("Max is %g\n", a);
    } else {
        printf("Max is %g\n", b);
    }

    return 0;
}
