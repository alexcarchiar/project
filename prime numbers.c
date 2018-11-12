#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number; //This is an important number

    printf("Give me a number, I'll tell if it's prime or give its factors.\nEnter number: ");
    scanf("%d", &number);
    printf("\n");

    int i = 1;
    int counter = 0;
    while (i <= number) {
        if(number % i == 0) {
            printf("%d ", i);
            ++counter;
        }
        ++i;
    }
    printf("\nThere are %d factors\n", counter);
    if(counter == 2) {
        printf("%d is a prime number", number);
    }

    return 0;
}
