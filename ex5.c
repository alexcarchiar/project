//
//  main.c
//  lab1
//
//  Created by Alessandro Carmelo Chiarelli on 09/10/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    int operand1, operand2, result;
    
    printf("Write the first operand ");
    scanf("%d", &operand1);
    printf("\nWrite the second operand ");
    scanf("%d", &operand2);
    result = operand1 + operand2;
    
    printf("\nThe result is: %d", result);
    
    return 0;
}
