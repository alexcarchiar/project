//Lab09 ex 05
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//protos
void print_Q(void);
void find_path(int x, int y);
//definitions
#define N 10
float Q[N][N] = {
     {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
     {0.1, 0.2, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3, 0.3, 0.1},
     {0.1, 0.2, 0.3, 0.3, 0.4, 0.5, 0.5, 0.5, 0.5, 0.1},
     {0.1, 0.2, 0.3, 0.3, 0.5, 0.5, 0.5, 0.7, 0.7, 0.1},
     {0.1, 0.2, 0.4, 0.4, 0.5, 0.5, 0.7, 0.8, 0.7, 0.1},
     {0.1, 0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 0.8, 0.1},
     {0.1, 0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 1.4, 0.1},
     {0.1, 0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 1.2, 0.1},
     {0.1, 0.2, 0.4, 0.4, 0.5, 0.7, 0.8, 0.9, 1.1, 0.1},
     {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}
};

int main(){
    
    int x, y; //x and y are the coordinates of the starting point
    //I should put here the input
    
    print_Q();
    printf("Insert coordinates in format: x y\n");
    scanf("%d", &x);
    scanf("%d", &y);
    --x;
    --y;
    
    find_path(x, y);
    printf("\n");
    
    return 0;
}

void print_Q(void){
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<N; ++j)
            printf("%g ", Q[i][j]);
        printf("\n");
    }
}

void find_path(int x, int y){
    
    int end = 0; //0 means we are not in the end, it's a flag variable. It changes when the last movement is made
    printf("(%d, %d)", x+1, y+1);
    while(end == 0){
        for(int i = (x-1); i < (x+2) && i<N; ++i){
            if(i == 0){
                ++i;
            }
            int counter = 0; //counts the number of values lower than Q[x][y]
            int moved = 0; //0 means there is no variation in x, y. Without this, the computer prints more than once every single couple
            for(int j = (y-1); j < (y+2) && j<N; ++j){
                if(j == 0){
                    ++j;
                }
                if(Q[i][j] > Q[x][y]){
                    x = i;
                    y = j;
                    moved = 1;
                } else{
                    ++counter;
                }
                if(counter == 1){
                    end = 1;
                }
            }
            if(moved == 1){
                printf(", (%d, %d)", x+1, y+1);
            }
        }
    
    }
}
