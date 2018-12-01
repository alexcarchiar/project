//
//  main.c
//  p
//
//  Created by Alessandro Carmelo Chiarelli on 07/11/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//
//Lab05 ex 3
//create two arrays end end program when one of the two is full
#include <stdio.h>
#define SIZE 5

int main(){
    
    int v1[SIZE], v2[SIZE]; //arrays
    int input;
    int index_1, index_2;
    index_2 = index_1 = 0;
    while(index_1 < SIZE && index_2 < SIZE){
        printf("Insert number:\n");
        scanf("%d", &input);
        if(input >= 0 ||( input < 0 && (input % 3)==0)) {
            v1[index_1] = input;
            index_1++;
        } else if((input < 0) || ((input % 2) != 0) && (input % 3) != 0) {
            v2[index_2] = input;
            index_2++;
        }
    }
    printf("v1\n");
    for(int j = 0; j <SIZE; j++)
        printf("%d\n", v1[j]);
    printf("v2\n");
    for(int j = 0; j <SIZE; j++)
        printf("%d\n", v2[j]);
    
    
    return 0;
}
