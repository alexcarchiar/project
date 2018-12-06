//Lab09 ex 04
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//protos
int path_from_row(int row);

//definitions
#define ROWS 5 //number of products
#define COLOUMNS 11 //lenght of the name

//* represents rocky area, . represents muddy area
char swamp[ROWS][COLOUMNS];
int path[COLOUMNS];


int main(){
    //get the swamp from keyboard; to be later implemented
    char reader[COLOUMNS+1];
    
    
    
    printf("Insert the swamp line by line. \"*\" are rocks, \".\" are muddy areas.\nThe swamp has a %d*%d size\nRemark that if you put something other than those two keys, it will be considered a muddy area\n", ROWS, COLOUMNS);
    
    for(int i = 0; i<ROWS; ++i){
        gets(reader);
        strncpy(swamp[i], reader, COLOUMNS);
    }
    /*printf("\n\n\n");
    for(int i = 0; i<ROWS; ++i){
        for(int j = 0; j<COLOUMNS; ++j){
            printf("%c", swamp[i][j]);
        }
        printf("\n");
    }*/
    
    int found_path = 0; //indicates if the path is found; it is 0 if the path is not found
    
    for(int i = 0; i<ROWS && found_path == 0; ++i){
        if(swamp[i][0] == '*'){
            path[0] = i;
            found_path = path_from_row(i);
        }
    }
    
    if(found_path == 0){
        printf("No path found\n");
    } else {
        printf("Found a path\n");
        printf("Path: ");
        for(int i = 0; i<COLOUMNS; ++i){
            printf("%d ", path[i]);
        }
    }
    
    return 0;
}

int path_from_row(int row){
    
    int counter_paces = 1;
    
    for(int coloumn = 1; coloumn < COLOUMNS; ++coloumn){
        for(int i = row - 1; i< row + 2 && i < ROWS; ++i){
            if(i < 0){
                ++i;
            } else {
                if(swamp[i][coloumn] == '*'){
                    path[coloumn] = i;
                    row = i;
                    ++counter_paces;
                }
            }
        }
    }
    if(counter_paces == COLOUMNS){
        return 1;
    } else{
        return 0;
    }
}

