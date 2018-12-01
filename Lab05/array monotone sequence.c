//
//  main.c
//  p
//
//  Created by Alessandro Carmelo Chiarelli on 07/11/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//
//Lab05 ex 4
//monotone sequence of numbers
#include <stdio.h>
#define N 10

int main(){
    
    int array[N], input;
    int i = 0;
    int order;//if 0, then ascending, if 1 then descending
    printf("Give number: \n");
    scanf("%d", &array[i]);
    i++;
    printf("Give number: \n");
    scanf("%d", &array[i]);
    i++;
    if(array[1] >= array[0]){ //ascending: also equal
        order = 0;
    } else if(array[1] < array[0]){//descending
        order = 1;
    }
    while( i < N){
        printf("Give number: \n");
        scanf("%d", &input);
        if(order == 0 && input > array[i -1]){
            array[i] = input;
            i++;
        } else if(order == 0 && input < array[i-1]){
            array[i] = input;
            i++;
            break;
        }
        if(order == 1 && input < array[i -1]){
            array[i] = input;
            i++;
        } else if(order == 1 && input > array[i-1]){
            array[i] = input;
            i++;
            break;
        }
    }
    for (int j = 0; j < i; ++j)
        printf("%d ", array[j]);
    return 0;
}
