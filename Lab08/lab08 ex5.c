//Lab08 ex5
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGHT_STRING 100
#define MAX_NUMBER_OF_PRODUCT 3

int main(){
    
    char array[3][MAX_LENGHT_STRING+1], last_string[MAX_LENGHT_STRING+1];
    char products[3][MAX_LENGHT_STRING+1], last_product[MAX_LENGHT_STRING+1];
    int prices[3], last_price;
    
    for(int i = 0; i<MAX_NUMBER_OF_PRODUCT; ++i){ //getting the strings
        printf("Insert product index: %d\n", i);
        gets(array[i]);
    }
    for(int i = 0; i<MAX_NUMBER_OF_PRODUCT; ++i){ //seperates name of product and prices
        int num_alpha_char = 0;
        int price = 0;
        for(int j = 0; j<MAX_LENGHT_STRING+1; ++j){
            if(isalpha(array[i][j])){
                ++num_alpha_char;
                products[i][j] = array[i][j];
            } else if(isdigit(array[i][j])){
                price = 10*price +array[i][j] - '0';
            }
        }
        prices[i] = price;
    }
    
    prices[1] = prices[1] / 10;
    
    int flag = 0; //0 means no equal products
    int store_i;
    while(flag == 0){ //this while allows us to iterate until the user inserts a correct input
        printf("\nInsert last product and quantity\n");
        gets(last_string);
        int num_alpha_char = 0;
        int price = 0;
        for(int j = 0; j<MAX_LENGHT_STRING+1; ++j){ //seperates name and quantity (last_price is a mistake actually)
            if(isalpha(last_string[j])){
                ++num_alpha_char;
                last_product[j] = last_string[j];
            } else if(isdigit(last_string[j])){
                price = 10*price + last_string[j] - '0';
            }
        }
        last_price = price;
        for(int i = 0; i<3; ++i){ //compares the strings and checks if there is a correct one
            if(strcmp(last_product, products[i]) == 0){
                flag = 1;
                store_i = i;
            }
        }
        
    }
    
    if(flag == 1){
        printf("Total price: %d", prices[store_i] * last_price);
    }
    
    return 0;
}

