//Lab03 ex 02
#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, c;

    a = 3;
    b = 5;

    c=(a==b);
    printf("%d\n", c);
    c = ((a&&b) || !b && !a);
    printf("%d\n", c);
    int x = 4;
    c = (a<x) && x<b;
    printf("%d\n", c);

    return 0;
}
