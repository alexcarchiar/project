//there's a problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_FRIENDS 100
#define MAX_NAME_LENGHT 80

//last friend -> ""
char Friends[MAX_NUM_FRIENDS+1][MAX_NAME_LENGHT+1];

//protos
void print_friends();
void sort_friends();
int count_friends();
int index_of_last_friend(int start, int end);
void swap(int f1, int f2);

int main(){
    
    printf("Let's add new friends! (empty line to end)\n");
    char name[MAX_NAME_LENGHT];
    int num_friends = 0;
    
    do{
        gets(name);
        strcpy(Friends[num_friends++], name);
        printf("\"%s\" is my new friend\n", name);
    } while(strcmp(name, "")!=0);
    printf("That's all\n");
    print_friends();
    sort_friends();
    printf("\n\n\n\n");
    print_friends();
    
    return 0;
}

void print_friends(){
    
    for(int f = 0; strcmp(Friends[f], "") != 0; ++f)
        printf("%d) %s\n", f, Friends[f]);
    return;
}

void sort_friends(){
    
    int num_friends = count_friends();
    while(num_friends > 1){
        int i = index_of_last_friend(0, num_friends);
        swap(i, num_friends - 1);
        --num_friends;
    }
    
    return;
}

int count_friends(){
    
    int cnt;
    for(cnt = 0; strcmp(Friends[cnt], "") != 0; ++cnt)
        ;
    return cnt;
}

int index_of_last_friend(int start, int end){
    
    int max = start;
    for(int i = start; i<end; ++i){
        if(strcmp(Friends[i], Friends[max]) > 0)
            max = i;
    }
    return max;
}

void swap(int f1, int f2){
    char tmp[MAX_NAME_LENGHT + 1];
    strcpy(tmp, Friends[f1]);
    strcpy(Friends[f1], Friends[f2]);
    strcpy(Friends[f2], tmp);
    return;
}
