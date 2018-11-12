#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Hi! My job is to compute the sum of integer numbers in an interval with your given step.\n");
    int a, b, step, sum;
    sum = 0;
    // a and b are the extremes of the interval
    printf("Give me the first extreme of the interval.\n");
    scanf("%d", &a);
    printf("Give me the second extreme of the interval.\n");
    scanf("%d", &b);
    printf("Give me the step.\n");
    scanf("%d", &step);
    if (a >= b) {
        printf("You gave me a wrong interval!\nProgram failed");
        return EXIT_FAILURE;
    }
    else if (step <= 0){
        printf("You gave me a wrong step!\nProgram Failed");
        return EXIT_FAILURE;
    }
    else {
        while (a <= b){
            sum = sum + a;
            a = a + step;
        }
        printf("Your sum is: %d", sum);
        return EXIT_SUCCESS;
    }

}
