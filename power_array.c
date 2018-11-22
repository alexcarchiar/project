//lab07 ex 1
#include <stdio.h>

#define N 5

float power(int base, int exponent);
int scan_array(int array[]);

int main(){
    int vbase[N];
    int vexponent[N];
    int vres[N];
    printf("Give %d bases\n", N);
    scan_array(vbase);
    printf("Give %d exponents\n", N);
    scan_array(vexponent);
    for(int i = 0; i<N; ++i){
        vres[i] = power(vbase[i], vexponent[i]);
        printf("%d\n", vres[i]);
    }
    return 0;
}

float power(int base, int exponent){
    
    float result;
    if(exponent == 0){
        result = 1.0;
    } else if(exponent == 1){
        result = base;
    } else if (exponent == -1){
        result = 1.0/((float)base);
    } else if(exponent > 1){
        result = (float)base;
        for(int i = 1; i<exponent; ++i){
            result *= (float)base;
        }
    } else if(exponent < -1){
        result = (float)base;
        for(int i = 1; i<-exponent; ++i){
            result *= (float)base;
        }
        result = 1.0/result;
    }
    
    return result;
}
int scan_array(int array[]){
    for(int i = 0; i<N; ++i){
        printf("Index %d\n", i);
        scanf("%d", &array[i]);
    }
    return 0;
}
