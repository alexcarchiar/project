//
//  main.c
//  lab3
//
//  Created by Alessandro Carmelo Chiarelli on 09/10/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    
    printf("This program can solve first degree functions of the tipe ax=b\n");
    
    int a, b, x;
    
    printf("Give a: ");
    scanf("%d", &a);
    printf("\n Give b:");
    scanf("%d", &b);
    
    if(a == 0){
        printf("There are infinite solutions");
    } else {
        x = a/b;
        printf("%d", x);
    }
    
    return 0;
}
