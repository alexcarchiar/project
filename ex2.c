//
//  main.c
//  lab2
//
//  Created by Alessandro Carmelo Chiarelli on 09/10/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    int x;
    
    printf("Insert a number: ");
    scanf("%d", &x);
    
    if (x>0) {
        printf("The value %d is positive\n", x);
    } else {
        printf("The value %d is negative or equal to 0\n", x);
    }
    return 0;
}
