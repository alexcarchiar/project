//Lab09 ex 02
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//definitions
#define N 10 //number of products
#define M 100 //lenght of the name


//protos
int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product);
void print_all(char warehouse[][M], float price[], int n, float *avg, float *max);



int main(){
    
    char warehouse[N][M];
    //filling up the warehouse with empty strings
    for(int i = 0; i<N; ++i){
        strcpy(warehouse[i], "");
    }
    
    float price[N];
    int user_choice = 0;
    float avg = 0;
    float max = 0;
    char new_product[M]; //it's a string  that must be copied in order to insert a new product
    float price_new_product = 0;
    printf("Warehouse program\n");
    while(user_choice != 3){
        printf("What do you want to do? Press:\n[1] Insertion of a new product and the associated price\n[2] Print the current list\n[3] Exit the program\n");
        scanf("%d", &user_choice);
        switch(user_choice){
            default:
                printf("Error: wrong input. Try again.\n");
                break;
            case 1:
                insert_product(warehouse, price, N, new_product, price_new_product);
                break;
            case 2:
                print_all(warehouse, price, N,
                          &avg, &max);
                break;
            case 3:
                printf("Goodbye\n");
                break;
        }
    }
    
    return 0;
}

void print_all(char warehouse[][M], float price[], int n, float *avg, float *max){
    
    *avg = 0.0;
    *max = 0.0;
    printf("The products and prices are:\n");
    for(int i = 0; i<n; ++i){
        if(strcmp("", warehouse[i]) != 0){
            printf("%s: %g\n", warehouse[i], price[i]);
            *avg += price[i];
            if(*max < price[i]){
                *max = price[i];
            }
        }
    }
    *avg/=n;
    printf("Average: %g\nMaximum price: %g\n", *avg, *max);
    
    return;
}

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product){
    
    int full = 0; //used to check if warehouse is full; 0 means not full
    int index_new_product = 0;
    int already_in_list = 0;//used to check if a product is already in list
    for(int i = n-1; i>-1; --i){
        if(warehouse[i][0] != '\0'){
            ++full;
        }
        if(warehouse[i][0] == '\0'){
            index_new_product = i;
        }
    }
    
    if(full == n){
        printf("The warehouse is full\n");
        return 2;
    } else {
        printf("What is the name of the product?\n");
        scanf("%s", new_product);
        for(int i = 0; i<n; ++i){
            if(strcmp(warehouse[i], new_product)==0)
                already_in_list = 1;
        }
            if(already_in_list == 1){
                printf("The product is already in the list\n");
                return 0;
            } else {
                strcpy(warehouse[index_new_product], new_product);
                printf("What is the price?\n");
                scanf("%g", &price[index_new_product]);
                return 1;
            }
    }
}
