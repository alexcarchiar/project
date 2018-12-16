//Lab11 ex 01: it's basically the same exercise as Lab10ex03
//In Lab10 I used the struct because the professor already taught us, whereas here 
//I am told to use them now; that means that I simply copy and paste here the code and
//If I remember I should modify the previous program without using the struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//definitions
struct _POINTS {
    float x;
    float y;
    float lenght;
};
typedef struct _POINTS POINT;
#define NUM_POINTS 4

//protos


int main(int argc, char **argv){
    
    if(argc > 2){
        printf("Too many arguments inserted\n");
        exit(1);
    } else if(argc < 2){
        printf("Too few arguments inserted\n");
        exit(1);
    }
    
    POINT coordinates[NUM_POINTS];
    
    //Input
    printf("Insert coordinates");
    for(int i = 0; i<NUM_POINTS; ++i){
        printf("\nPoint %d\nx : ", i);
        scanf("%g", &coordinates[i].x);
        printf("\ny: ");
        scanf("%g", &coordinates[i].y);
        coordinates[i].lenght = sqrtf((coordinates[i].x * coordinates[i].x + coordinates[i].y * coordinates[i].y));
    }
    float path = 0;
    float min = coordinates[0].lenght;
    if(strcmp(argv[1], "-m")){
        for(int i = 0; i<NUM_POINTS; ++i){
            path += coordinates[i].lenght;
        }
        printf("The lenght of the path is: %g\n", path);
    }else if(strcmp(argv[2], "-a")){
        for(int i = 1; i<NUM_POINTS; ++i){
            if(min > coordinates[i].lenght)
                min = coordinates[i].lenght;
        }
        printf("Minimum lenght is: %g\n", min);
    }else {
        printf("Error: wrong parameter\n");
    }
    
    return 0;
}
