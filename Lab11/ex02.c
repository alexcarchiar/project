//Lab11 ex02
//basically I have to create a contacts program to manage it
//Since it is not specified, I assume that we can also accept empty strings as input
//I should add a sorting algorithm in order to simplify the search for contacts
//I arrange by name and not surname
//it is not specified to use files
//update to manage files? --> maybe
/******
 * for input from file:
 * just consider the file as:
 * <number of contacts>
 * <name1>
 * <surname1>
 * <Phone number1>
 * <Mobile number1>
 * <name2>
 * <surname2>
 * etc
 ******/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//definitions
typedef struct names {
    char name[20]; /*Name*/
    char surname[20]; /*Surname*/
    char number[20]; /*Phone Number*/
    char mobile[20]; /*Mobile Number*/
} Names;
#define MAX_CONTACTS 100

//protos
int insert_new_contact(Names *book, int num_of_contacts);
void display_all(Names *book, int num_of_contacts);
void sort_by_name(Names *book, int num_of_contacts);
int input_from_file(Names *book, int *num_of_contacts);
int output_to_file(Names *book, int num_of_contacts);
void remove_new_lines(char *string);



int main(){
    
    Names contacts[MAX_CONTACTS];
    //initializing the array with empty strings
    for(int i = 0; i<MAX_CONTACTS; ++i){
        strcpy(contacts[i].name, "");
        strcpy(contacts[i].surname, "");
        strcpy(contacts[i].number, "");
        strcpy(contacts[i].mobile, "");
    }
    int num_of_contacts = 0;
    int user_choice = 0;
    int choice_input = 0;
    int flag_input, flag_output;
    int choice_output;
    
    printf("Contact book management program\nDo you want to use an existing file?\nInsert:\n[1] for yes;\n[2] for no\n");
    scanf("%d", &choice_input);
    
    if(choice_input == 1){
        flag_input = input_from_file(contacts, &num_of_contacts);
        if(flag_input == EXIT_FAILURE){
            printf("Couldn't find the file; insert the contacts manually\n");
        } else{
            num_of_contacts = flag_input;
        }
    }
    
    while(user_choice != 3){ //menu
        printf("Press:\n[1] to insert a contact;\n[2] to display the currunt list;\n[3] to quit\n");
        scanf("%d", &user_choice);
        switch(user_choice){
            case 1:
                num_of_contacts = insert_new_contact(contacts, num_of_contacts);
                break;
            case 2:
                display_all(contacts, num_of_contacts);
                break;
            case 3:
                printf("Do you want to save your contact list?\nInsert:\n[1] for yes;\n[2] for no\n");
                scanf("%d", &choice_output);
                if(choice_output == 1){
                    flag_output = output_to_file(contacts, num_of_contacts);
                    if(flag_output != 0){
                        printf("Couldn't find the file, so the list will not be saved.\n");
                    }
                }
                printf("Goodbye\n");
                break;
            default:
                break;
        }
    }
    
    return 0;
}

int insert_new_contact(Names *book, int num_of_contacts){
    Names input;
    int warning = 0; //indicates if the program finds a duplicate to give the required warning
    printf("Insert name\n");
    scanf("%s", &input.name);
    input.name[0] = toupper(input.name[0]); //just to make sure the first letter is uppercase
    printf("Insert surname\n");
    scanf("%s", &input.surname);
    input.surname[0] = toupper(input.surname[0]);//just to make sure the first letter is upper case
    printf("Insert phone number\n");
    scanf("%s", &input.number);
    printf("Insert mobile number\n");
    scanf("%s", &input.mobile);
    
    for(int i = 0; i<num_of_contacts; ++i){
        if(strcmp(input.name, book[i].name) == 0 && strcmp(input.surname, book[i].surname) == 0){
            warning = 1;
        }
    }
    if(warning == 0){
        book[num_of_contacts] = input;
        num_of_contacts++;
        sort_by_name(book, num_of_contacts);
    }
    int choice_warning = 0;
    while(warning == 1 && (choice_warning != 1 && choice_warning != 2)){
        printf("I already found the contact %s &s\nDo you want to add it anyway?\nInsert:\n[1] for yes;\n[2] for no\n", input.name, input.surname);
        scanf("%d", &choice_warning);
        if(choice_warning == 2){
            ;
        } else if(choice_warning == 1){
            book[num_of_contacts] = input;
            num_of_contacts++;
            sort_by_name(book, num_of_contacts);
        } else{
            printf("Invalid input\n");
        }
    }
    
    
    return num_of_contacts;
}

void display_all(Names *book, int num_of_contacts){
    
    for(int i = 0; i<num_of_contacts; ++i){
        printf("%d) %s %s %s %s\n", i+1, book[i].name, book[i].surname, book[i].number, book[i].mobile);
    }
    
    return;
}

void sort_by_name(Names *book, int num_of_contacts){
    
    //I have to sort alphabetically by name, remembering that every string in C is ordered
    //like a dictionary
    Names temp;
    for(int i = 0; i<num_of_contacts-1; ++i){
        for(int j = i+1; j<num_of_contacts; ++j){
            if(strcmp(book[i].name, book[j].name) > 0){
                temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            } else if(strcmp(book[i].name, book[j].name) == 0 && strcmp(book[i].surname, book[j].surname) > 0){
                temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
    
    return;
}

int input_from_file(Names *book, int *num_of_contacts){
    
    char path[4096];
    char number[5];
    printf("Insert the path of the file\n");
    scanf("%s", path);
    FILE *fin = fopen(path, "r");
    if(fin == NULL){
        exit(EXIT_FAILURE);
    }
    int counter = 0;
    int end = 0;
    
    //getting input, look at the beginning of the code to see
    //the format of the file
    //fgets(number, 4096, fin);
    //sscanf(number, "%d", *num_of_contacts);
    for(int i = 0; i<MAX_CONTACTS && end == 0; ++i){
        fgets(book[i].name, 20, fin);
        remove_new_lines(book[i].name);
        fgets(book[i].surname, 20, fin);
        remove_new_lines(book[i].surname);
        fgets(book[i].number, 20, fin);
        remove_new_lines(book[i].number);
        fgets(book[i].mobile, 20, fin);
        remove_new_lines(book[i].mobile);
        if(strcmp(book[i].name, "") == 0 && strcmp(book[i].surname, "") == 0 && strcmp(book[i].number, "") == 0 && strcmp(book[i].mobile, "") == 0){
            end = 1;
        }
        counter = i;
    }
    
    fclose(fin);
    
    return counter;
}

int output_to_file(Names *book, int num_of_contacts){
    
    char path[4096];
    printf("Insert the path of the file\n");
    scanf("%s", path);
    FILE *fout = fopen(path, "w");
    if(fout == NULL){
        exit(EXIT_FAILURE);
    }
    //fprintf(fout, "%d\n", num_of_contacts);
    for(int i = 0; i<num_of_contacts; ++i){
        fprintf(fout, "%s\n", book[i].name);
        fprintf(fout, "%s\n", book[i].surname);
        fprintf(fout, "%s\n", book[i].number);
        fprintf(fout, "%s\n", book[i].mobile);
    }
    
    
    fclose(fout);
    
    return 0;
}

void remove_new_lines(char *string){

    for(int i = 0; i<20; ++i){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
    }

    return;
}
