//Lab06 ex 7
//Write an algorithm able to tabulate the value of arcsin x given as input:
//the range [a, b] (so we need to numbers to determine the range)
//the step c (so we can proceed and tabulate only a finite number of values)
//e is the error (accuracy) of the computation
//need to define the function invsin() which basically is the  arcsin() macro that we can't use for the purpose of this exercise
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

float invsin(double k, double e);

int main(void){
    double a, b, c, e;
    printf("I tabulate the values of arcsin(x) for x in a given range [a,b] with a given step c.\nGive a:\n");
    scanf("%lg", &a);
    printf("Give b:\n");
    scanf("%lg", &b);
    printf("Give c:\n");
    scanf("%lg", &c);
    printf("How much accurate do you want your values?\n");
    scanf("%lg", &e);
    if(a<-1 || b >1){
        printf("Error: arcsin can only have values in range [-1, 1]. You entered an invalid range");
    } else{
        printf("x:       arcsin(x)\n");
        for(double i = a; i<=b; i+=c){
            if(i == 0){
                printf("%6lg    %6lg\n", 0, 0);
            } else if(i == 1){
                printf("%6lg    %6lg\n", 1, PI/2.0);
            } else if(i == -1){
                printf("%6lg    %6lg\n", -1, -PI/2.0);
            } else{
                printf("%6lg    %6lg \n", i, invsin(i,e));
            }
        }
    }
    return 0;
}

float invsin(double k, double e){
    double z;
    double sin_z;
    double a = -PI/2.0;
    double sin_a;
    double sin_b;
    double b = PI/2.0;
    if(k >= 0.0){
        a = 0.0;
    } else{
        b = 0.0;
    } double flag =((a-b)/2.0);
    if (flag < 0){
        flag *= -1;
    }
    sin_a = sin(a);
    sin_b = sin(b);
    while(flag > e && sin_a!= sin_b){
        sin_a = sin(a);
        sin_b = sin(b);
        z = (a+b)/2.0;
        sin_z = sin(z);
        if(k<= sin_b && k>= sin_z){
            a = z;
        } else if(k<= sin_z && k>= sin_a){
            b = z;
        }
        flag =((a-b)/2.0);
        if (flag < 0){
            flag *= -1;
        }
    }
    
    return z;
}

/*int main(){
    double k = -0.1;
    double e = 0.002;
    double z;
    double sin_z;
    double a = -PI/2.0;
    double sin_a;
    double sin_b;
    double b = PI/2.0;
    if(k >= 0.0){
        a = 0.0;
    } else{
        b = 0.0;
    } double flag =((a-b)/2.0);
    if (flag < 0){
        flag *= -1;
    }
    sin_a = sin(a);
    sin_b = sin(b);
    while(flag > e && sin_a!= sin_b){
        sin_a = sin(a);
        sin_b = sin(b);
        z = (a+b)/2.0;
        sin_z = sin(z);
        if(k<= sin_b && k>= sin_z){
            a = z;
        } else if(k<= sin_z && k>= sin_a){
            b = z;
        }
        flag =((a-b)/2.0);
        if (flag < 0){
            flag *= -1;
        }
    }
    
    
    printf("%lg",z);
    return 0;
}
*/
