//Lab10 ex2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//protos


int main(int argc, char **argv){
    
    if(argc > 4){
        printf("Too many arguments inserted\n");
        exit(1);
    } else if(argc < 4){
        printf("Too few arguments inserted\n");
        exit(1);
    }
    
    int val_1 = atoi(argv[1]);
    int val_2 = atoi(argv[2]);
    
    if(strlen(argv[3]) != 1){
        printf("Error: invalid input\n");
        exit(1);
    }
    if(val_2 == 0){
        printf("Invalid input\n");
        exit(1);
    }
    char ch = argv[3][0];
    switch(ch){
        case 'a':
            printf("%d\n", val_1 + val_2);
            break;
        case 'b':
            printf("%d\n", val_1 - val_2);
            break;
        case 'c':
            printf("%d\n", val_1 * val_2);
            break;
        case 'd':
            printf("%d\n", val_1 / val_2);
            break;
        default:
            ;
    }
    
    return 0;
}
