//Lab03 ex 04
#include <stdio.h>
#include <stdlib.h>

#define BASE_PRICE 100
#define FEATURE 40
#define POSSESSED -20

int main(){

    int price, features, months, years;
    printf("How many features?\n");
    scanf("%d", &features);
    printf("How many years was it possessed?\n");
    scanf("%d", &years);
    months = years * 12;
    price = BASE_PRICE + FEATURE * features + POSSESSED * months;
    printf("The price is: %d\n", price);
    

    return 0;
}
