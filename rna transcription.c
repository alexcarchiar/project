//RNA transcription from exercism
//Nucleotide counter from exercism
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 4095
//protos
int scan_dna(char dna[]);
int is_valid(char nucleotide);
void print(char array[], int counter);

int main(){
    
    char dna[MAX_LEN+1], rna[MAX_LEN+1];
    printf("Write a DNA sequence with maximum %d nucleotides\n", MAX_LEN);
    int counter = scan_dna(dna);
    for(int i = 0; i<counter; ++i){
        switch(dna[i]){
            case 'A':
                rna[i] = 'U';
                break;
            case 'T':
                rna[i] = 'T';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'G':
                rna[i] = 'C';
                break;
        }
    }
    printf("The RNA sequence is:\n");
    print(rna, counter);
    
    return 0;
}

int scan_dna(char dna[]){ //we scan a dna string using an auxiliary string to allow for non alphabetic character, then we pick only the alphabetic ones and store them into the dna string and allow the user to modify the wrong inputs
    int counter = 0;
    char string_1[MAX_LEN];
    for(int i = 0; i<MAX_LEN && string_1[i-1] != '\n'; ++i){
        string_1[i] = toupper(getchar());
    }
    for(int i = 0; i<MAX_LEN && string_1[i-1] != '\n'; ++i){
        if(isalpha(string_1[i])){
            if(!(is_valid(string_1[i]))){
                printf("Invalid input. You entered: %c at index %d\nEnter your correction: ", string_1[i], i);
                scanf("%c", &string_1[i]);
                printf("\n");
                --i;
            } else if(is_valid(string_1[i])){
                dna[counter] = string_1[i];
                ++counter;
            }
        }
    }
    return counter;
    
}

int is_valid(char nucleotide){
    int flag = 0; //0 means invalid
    switch(nucleotide){ //A nucleotide in DNA can only be gcta
        case 'G':
        case 'C':
        case 'T':
        case 'A':
            flag = 1;
    }
    return flag;
}

void print(char array[], int counter){
    for(int i = 0; i<counter; ++i)
        printf("%c", array[i]);
    printf("\n");
    return;
}
