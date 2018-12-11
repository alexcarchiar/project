//Lab09 ex 04c with files
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
void input_from_file(char warehouse[N][M], float price[N]);
void save_file(char warehouse[][M], float price[], int n);
void get_desktop_path(char p[]);
void get_home(char path[]);


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
    int save_to_file = 0; //it's a flag variable used to allow the user to save the output in a file; for case 5
    
    printf("Warehouse program by alexcarchiar\n");
    printf("Do you want to import from an old file? Press:\n[1], yes;\n[2], no\n");
    int import_from_file = 0;
    scanf("%d", &import_from_file);
    if(import_from_file == 1){
        input_from_file(warehouse, price);
    }
    
    
    
    while(user_choice != 5){
        printf("What do you want to do? Press:\n[1] Insertion of a new product and the associated price\n[2] Print the current list\n[3] Remove a product\n[4] Update product\n[5] Exit the program\n");
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
            case 5:
                printf("Do you want to save the current list? Press:\n[1] to save\n[2] to quit without saving\n");
                scanf("%d", & save_to_file);
                if(save_to_file == 1){
                    save_file(warehouse, price, N);
                }
                printf("Goodbye\n");
                break;
            case 4:
                update_product(warehouse, price, N, product, new_price);
                break;
            case 3:
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

void input_from_file(char warehouse[N][M], float price[N]){
    
    printf("Insert the path of the file\n");
    char path[4096];
    scanf("%s", path);
    
    FILE *file = fopen(path, "r");
    if(file == NULL){ //always add NULL case if we are in only reading
        fprintf(stderr, "We have a problem\n");
        exit(EXIT_FAILURE);
    }
    
    char line[M+sizeof(float)+2];
    
    for(int i = 0; i<N; ++i){
        if(fgets(line, M+sizeof(float)+2, file)!=NULL) {//M is the size of the name, 2 acconts for space and :
            int after_space = 0;
            float pri = 0.0;
            int decimal_digits = 0;
            int after_decimal_point = 0;
            /* writing content to stdout */
            for(int j = 0; j<M; ++j){
                if(isalpha(line[j])){
                    warehouse[i][j] = line[j];
                } else if(line[j] == ' '){
                    after_space = 1;
                } else if(after_space == 1){
                    if(isdigit(line[j])){
                        pri = pri * 10 + line[j] - '0';
                        if(after_decimal_point == 1){
                            decimal_digits++;
                        }
                    } else if(line[j] == '.')
                        after_decimal_point = 1;
                }
            }
            pri = pri / 100.0; //because our program counts the '.' and the '\n' as digits, so we need to divide by 100
            if(decimal_digits>0)
                pri = pri /(float)(10 * decimal_digits);
            price[i] = pri;
            //printf("%s: ", warehouse[i]);
            //printf("%g\n", price[i]);
        }
    }
    
    fclose(file);
    
    return;
}

void save_file(char warehouse[][M], float price[], int n){ //the path works only for Unix Systems; so it won't work for windows
    
    char name_of_file[M];
    printf("Write the name of the file (max lenght: %d, it will be stored on the desktop\n", M);
    scanf("%s", name_of_file);
    char path_[4096];
    get_home(path_); //gets the home directory for MacOS
    strcat(path_, "/Desktop/");
    strcat(path_, name_of_file);
    strcat(path_, ".alexcarchiar"); //adding the extension
    
    FILE *file = fopen(path_, "w");
    if(file == NULL){
        exit(1);
    }
    
    for(int i = 0; i<n; ++i){
        if(strcmp("", warehouse[i]) != 0){
            fprintf(file, "%s: %g\n", warehouse[i], price[i]);
        }
    }
    
    fclose(file);
    return;
    
}

void get_home(char path[]){ //I think it only works for MacOS, so if compiling in windows, find a solution or forget about the home diretory
    
    const char *homeDir = getenv("HOME");
    char home[4096];
    
    if (homeDir)
        strcpy(path, homeDir);
    else{
        fprintf(stderr, "Couldn't figure home directory out.\nWhat is your username?\n");
        scanf("%s", home);
        strcpy(path, home);
    }
    
    return;
}
