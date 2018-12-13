//Lab10 ex1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//protos


int main(int argc, char **argv){
    
    if(argc > 3){
        printf("Too many arguments inserted\n");
        exit(1);
    } else if(argc < 3){
        printf("Too few arguments inserted\n");
        exit(1);
    }
    
    int int_1 = atoi(argv[1]);
    int int_2 = atoi(argv[2]);
    
    
    if(int_1 < -10000 || int_1 > 10000){
        printf("The first argument is out of range\n");
        exit(1);
    }
    if(int_2 < -10000 || int_2 > 10000){
        printf("The second argument is out of range\n");
        exit(1);
    }
    printf("%d\n", int_1 + int_2);
    return 0;
}
