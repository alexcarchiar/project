//
//  main.c
//  lab01
//
//  Created by Alessandro Carmelo Chiarelli on 09/10/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    int x, y, z;
    
    printf("Enter an integer: ");
    scanf("%d", &x);
    y = 3;
    z = x/y;
    
    printf("%d/%d=%d\n", x, y, z);
    return 0;
}
