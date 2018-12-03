//
//  main.c
//  farehneit to celsius
//
//  Created by Alessandro Carmelo Chiarelli on 09/10/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    char scale;
    printf("What scale are you converting from? Write \"C\" for Celsius or \"F\" for Fahrenheit\n");
    scanf("%c", &scale);
    printf("What is the value of the temperature?\n");
    float temp, conv;
    scanf("%g", &temp);
    if (scale == 'C' || scale == 'c'){
        conv = (temp * 9 / 5) + 32;
        printf("The temperature in Fahrenheit is: %g F ", conv);
    } else if (scale == 'F' || scale == 'f') {
        conv = (temp - 32) * 5 / 9;
        printf("The temperature in Celsius is: %g C", conv);
    }
        else {
            printf("I don't know your scale, just write \"0\" or \"1\"");
        }
    
    
    return 0;
}
