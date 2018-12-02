//Lab07 ex 2
#include <stdio.h>

#define N 5

void mult(int v[], int x);
int scan_array(int array[]);

int main(){
    int vect[N], x;
    scan_array(vect);
    printf("Give x\n");
    scanf("%d", &x);
    mult(vect, x);
    for(int i = 0; i<N; ++i){
        printf("%d\n", vect[i]);
    }
    return 0;
}
int scan_array(int array[]){
    for(int i = 0; i<N; ++i){
        printf("Index %d\n", i);
        scanf("%d", &array[i]);
    }
    return 0;
}
void mult(int v[], int x){
    for(int i = 0; i<N; ++i){
        v[i] *= x;
    }
    return;
}
