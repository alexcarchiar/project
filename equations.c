#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//This is an equation solver for up to 2nd degree
//equations already reduced in canonical form
int main()
{
    double a, b, c, delta, x, x_1, x_2;

    printf("I am an equation solver. Write an equation in its canonical form\n");
    scanf("%lg", &a);
    scanf("%lg", &b);
    scanf("%lg", &c);

    if (a == 0.0) {
            if (b == 0.0){
                if (c == 0.0) {
                    printf("Indeterminate\n");
                    }
                else {
                    printf("Impossible\n");
            }
            } else{
                x = - c / b;
                printf("Solution: x = %g", x);
        }
    } else {
        delta = b*b - 4.0*a*c;
        if (delta < 0.0){
            printf("Impossible\n");
        } else if(delta >0) {
            x_1 = (-b - sqrt(delta)) / (2.0*a);
            x_2 = (-b + sqrt(delta)) / (2.0*a);
            printf("Your solutions are:\n");
            printf("x1 = %g\n", x_1);
            printf("x2 = %g\n", x_2);
        } else if(delta == 0) {
            x = - b /(2 * a);
            printf("Solution: x = %g", x);
        }
    }

    return 0;
}
