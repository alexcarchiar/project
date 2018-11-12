#include <stdio.h>
#include <stdlib.h>

int main()
{
    float price, tax, receipt;
    printf("I calculate the receipt\n Give me price\n");
    scanf("%g", &price);
    printf("Give me tax\n");
    scanf("%g", &tax);
    receipt = price + price * tax / 100.0;
    printf("The receipt is: %g", receipt);
    return 0;
}
