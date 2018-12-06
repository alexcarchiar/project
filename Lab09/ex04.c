//Lab09 ex 04
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//definitions
#define N 10 //number of products
#define M 100 //lenght of the name
#define EMPTY_PRICE -2


//protos
int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product);
void print_all(char warehouse[][M], float price[], int n, float *avg, float *max);
int update_product(char warehouse[][M], float price[], int n, char product[] , float new_price);
int remove_product(char warehouse[][M], float price[], int n, char old_product[]);



int main(){
    
    char warehouse[N][M];
    //filling up the warehouse with empty strings
    for(int i = 0; i<N; ++i){
        strcpy(warehouse[i], "");
    }
    
    float price[N];
    for(int i = 0; i<N; ++i){
        price[i] = EMPTY_PRICE;
    }
    int user_choice = 0;
    float avg = 0;
    float max = 0;
    char new_product[M]; //it's a string  that must be copied in order to insert a new product
    float price_new_product = 0;
    char product[M];
    char old_product[M];
    float new_price = 0;
    printf("Warehouse program\n");
    while(user_choice != 3){
        printf("What do you want to do? Press:\n[1] Insertion of a new product and the associated price\n[2] Print the current list\n[3] Exit the program\n[4] Update product\n[5] Remove a product\n");
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
            case 4:
                update_product(warehouse, price, N, product, new_price);
                break;
            case 5:
                remove_product(warehouse, price, N, old_product);
                break;
        }
    }
    
    return 0;
}

void print_all(char warehouse[][M], float price[], int n, float *avg, float *max){
    
    *avg = 0.0;
    *max = 0.0;
    int counter = 0;
    printf("The products and prices are:\n");
    for(int i = 0; i<n; ++i){
        if(strcmp("", warehouse[i]) != 0){
            printf("%s: %g\n", warehouse[i], price[i]);
            if(price[i] != EMPTY_PRICE){
                *avg +=price[i];
                ++counter;
            }
            if(*max < price[i]){
                *max = price[i];
            }
        }
    }
    *avg/=counter;
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
int update_product(char warehouse[][M], float price[], int n, char product[] , float new_price){
    printf("Insert the name of the product you wish to update\n");
    scanf("%s", product);
    int index_found = 0;
    int found = 0; //means we have not found the product yet
    for(int i = 0; i<N && found == 0; ++i){
        if(strcmp(warehouse[i], product) == 0){
            found = 1;
            index_found = i;
        }
    }
    
    if(found == 0){
        printf("The product is not in the warehouse\n");
        return 0;
    } else {
        printf("Insert the new price\n");
        scanf("%g", &new_price);
        price[index_found] = new_price;
        return 1;
    }
    
}

int remove_product(char warehouse[][M], float price[], int n, char old_product[]){
    
    printf("Insert the name of the product you wish to remove\n");
    scanf("%s", old_product);
    
    int index_found = 0;
    int found = 0; //means we have not found the product yet
    for(int i = 0; i<N && found == 0; ++i){
        if(strcmp(warehouse[i], old_product) == 0){
            found = 1;
            index_found = i;
        }
    }
    
    if(found == 0){
        printf("The product is not in the warehouse\n");
        return 0;
    } else {
        printf("The product is removed\n");
        strcpy(warehouse[index_found], "");
        price[index_found] = EMPTY_PRICE;
        return 1;
    }
    
}
