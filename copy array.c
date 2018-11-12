#include <stdio.h>
#include <stdlib.h>
#define N 10


int main()
{
    int v1[N], v2[N];

    for(int i = 0; i<N; i++){
        printf("Please enter an integer value %d: \n", ++i);
        scanf("%d", &v1[i]);
    }
    for(int i = 0; i<N;i++){
        printf("v1[%d] = %d\n", i, v1[N]);
    }
     for(int i = 0; i<N;i++){
        v2[N-i-1] = v1[i];
    }
     for(int i = 0; i<N;i++){
        printf("v2[%d] = %d\n", i, v2[N]);
    }

    printf("Hello world!\n");
    return 0;
}
