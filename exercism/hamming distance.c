//From exercism
//Hamming distance from two strings of DNA
#include <stdio.h>
#include <ctype.h>

#define MAX 256

int is_valid(char nucleotide);
int scan_dna(char dna[]);
//insert in main a flag for is_valid to make sure someone can retype the mistaken nucleotide
int main(){
    char verified_dna_1[MAX], verified_dna_2[MAX];
    int counter_1, counter_2, hamming_distance;
    hamming_distance = 0;
    counter_1 = counter_2 = 0;
    printf("Print the first DNA string with all letters on the same line\n");
    counter_1 = scan_dna(verified_dna_1);
    printf("Print the second DNA string with all letters on the same line\n");
    counter_2 = scan_dna(verified_dna_2);
    if(counter_1 != counter_2)
        printf("InvaLid input: your strings are different.\n");
    else{
        for(int i = 0; i<counter_1; ++i){
            if(verified_dna_1[i] != verified_dna_2[i])
                ++hamming_distance;
        }
        printf("Hamming distance: %d\n", hamming_distance);
    }
    /*for(int j = 0; j<counter_1; ++j)
        printf("%c", verified_dna_1[j]);
    printf("\nCounter: %d", counter_1); */
    return 0;
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

int scan_dna(char dna[]){ //we scan a dna string using an auxiliary string to allow for non alphabetic character, then we pick only the alphabetic ones and store them into the dna string and allow the user to modify the wrong inputs
    int counter = 0;
    char string_1[MAX];
    for(int i = 0; i<MAX && string_1[i-1] != '\n'; ++i){
        string_1[i] = toupper(getchar());
    }
    for(int i = 0; i<MAX && string_1[i-1] != '\n'; ++i){
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

