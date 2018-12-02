// main.c
// base converter for all bases from binary to decimal and vice versa
//
//  Created by Alessandro Carmelo Chiarelli
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//
#include <stdio.h>
#define MAX_DIGITS 128

int to_decimal(int original_base, int num_digits, int number[MAX_DIGITS]);
int to_another_base(int decimal_number, int end_base);

int main(){ //main function, we use it for all bases and call the to_decimal when needed to convert from a base such as 3 to base 7
    
    printf("+-----------------------------------------------------------------------------------------+\n");
    printf("|                                       Base converter                                    |\n");
    printf("|                                        version: 1.0                                     |\n");
    printf("|(C) alexcarchiar, realised as an exercise                                                |\n");
    printf("|Choose a conversion (example: binary to decimal) and give the input. All numbers shall be|\n");
    printf("|inserted digit by digit, from left to right, except decimal base numbers.                |\n");
    printf("|For any base, we can currently have at most %d digits.                                   |\n", MAX_DIGITS);
    printf("+-----------------------------------------------------------------------------------------+\n");
    
    int original_base, num_digits, number[MAX_DIGITS], end_base, flag; //flag is used to check if the input digit is correct
    int decimal_number, end_number; //used to get the decimal number, useful in almost every conversion
    printf("Insert original base:\n");
    scanf("%d", &original_base);
    printf("Insert end_base:\n");
    scanf("%d", &end_base);
    if(original_base < 2 || original_base > 10 || end_base == original_base || end_base < 2 || end_base > 10){
        printf("Error: invalid input.\n");
    } else if (original_base > 1 && original_base < 10){ //from a base to another one
        printf("Insert the number of digits\n");
        scanf("%d", &num_digits);
        printf("Insert number digit by digit, from left to right.\n");
        for(int i = 0; i<num_digits;){ //no increment because there could be an error, the increment is present when the input is valid
            scanf("%d", &flag);
            if (flag >=0 && flag < original_base){
                number[i] = flag;
                ++i;
            } else {
                printf("You inserted &d as input which is invalid. Insert only digits between 0 and %d.\n", flag, (flag - 1));
            }
        }
        decimal_number = to_decimal(original_base, num_digits, number); //all numbers must be converted to decimal for the sake of simplicity
        if(end_base == 10){ //if the desired base is 10
            printf("%d\n", decimal_number);
        } else{ //if the desired base is another one
            to_another_base(decimal_number, end_base);
        }
    } else if(original_base == 10 && (end_base > 1 && end_base < 10)){ //from decimal to another base
        printf("Insert number:\n");
        scanf("%d", &decimal_number);
        to_another_base(decimal_number, end_base);
    }
    
    return 0;
}

int to_decimal(int original_base, int num_digits, int number[]){ //conversion to decimal base
    
    int quantity = 0;
    int weight = original_base;
    for(int i = 0; i <= num_digits; ++i){
        quantity += number[i] * weight;
        weight *= original_base;
    }
    return quantity;
}

int to_another_base(int decimal_number, int end_base){
    //the idea is to use the modulus operator and add up the various remainders
    int end_array[MAX_DIGITS] = {0};
    printf("The binary number is: ");
    for(int i = 0; decimal_number > 0; ++i){
        end_array[i] = decimal_number % end_base;
        decimal_number = decimal_number / end_base;
        printf("%d", end_array[i]);
    }
    return 0;
}

