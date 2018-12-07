//Lab03 ex 07
#include <stdio.h>
#include <stdlib.h>



int main(){

    int a, b, c, d;
    int max, min, difference;

    printf("Insert a\n");
    scanf("%d", &a);
    max = a;
    min = a;
    if(!(a >= 0 && a <1000)){
        a = 0;
        printf("Error: value assinged to 0\n");
    }

    printf("Insert b\n");
    scanf("%d", &b);
    if(!(b >= 0 && b <1000)){
        b = 0;
        printf("Error: value assinged to 0\n");
    }
    if(max<b){
        max = b;
    }
    if(min > b && b!= 0){
        min = b;
    }

    printf("Insert c\n");
    scanf("%d", &c);
    if(!(c >= 0 && c <1000)){
        c = 0;
        printf("Error: value assinged to 0\n");
    }
    if(max<c){
        max = c;
    }
    if(min > c && c!= 0){
        min = c;
    }

    printf("Insert d\n");
    scanf("%d", &d);
    if(!(d >= 0 && d <1000)){
        d = 0;
        printf("Error: value assinged to 0\n");
    }
    if(max<d){
        max = d;
    }
    if(min > d && d!= 0){
        min = d;
    }

    difference = max - min;
    printf("The maximum difference is: %d\n", difference);

    return 0;
}
