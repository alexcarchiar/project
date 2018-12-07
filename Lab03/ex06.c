//Lab03 ex 06
#include <stdio.h>
#include <stdlib.h>



int main(){

    int a, b;
    float avg;
    printf("Insert a\n");
    scanf("%d", &a);
    printf("Insert b\n");
    scanf("%d", &b);
    avg = a+b;
    avg/=2;
    printf("The average is: %g\n", avg);
    

    return 0;
}
