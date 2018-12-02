//Lab07 ex 04
#include <stdio.h>

#define N 5
float over_Avg(int v[], int n, int *greater);

int main(){
    
    int array[N], greater;
    greater = 0;
    float average;
    printf("Insert %d values\n", N);
    for(int i = 0; i<N; ++i){
        printf("Index %d\n", i);
        scanf("%d", &array[i]);
    }
    average = over_Avg(array, N, &greater);
    printf("Average: %g \nGreater: %d\n", average, greater);
    return 0;
}

float over_Avg(int v[], int n, int *greater){
    
    float average = 0;
    for(int i = 0; i<N; ++i){
        average += v[i];
    }
    average /= N;
    for(int i = 0; i<N; ++i){
        if(v[i]>average)
            ++*greater;
    }
    
    return average;
}
