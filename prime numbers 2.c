#include <stdio.h>
#include <stdlib.h>

//Need to revise this program
int main()
{
    printf("This numbers are primes between 1 and 100\n");
    int number; //This is an important number
    number = 1;
    while (number < 100){
            ++number;
             int i = 1;
    int counter = 0;
    while (i <= number) {
        if(number % i == 0) {
            ++counter;
        }
        ++i;
    }
    if(counter == 2) {
        printf("%d ", number);
    }

    }


    return 0;
}
