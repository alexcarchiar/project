//Lab07 ex 06
#include <stdio.h>
#include <ctype.h>

#define MAX 256

int main(){
    
    char string[MAX];
    printf("Type string\n");
    for(int i = 0; i<MAX && string[i-1] != EOF; ++i)
        string[i] = getchar();
    /*for(int i = 0; i<MAX && string[i-1] != EOF; ++i){
        if(i== 0 && isalpha(string[i]))
            string[i] = toupper(string[i]);
        else if(islower(string[i]) && string[i-1] =='\n')
            string[i] = toupper(string[i]);
        printf("%c", string[i]);
    }
     this is only for new line */
    printf("\n\n");
    for(int i = 0; i<MAX && string[i-1] != EOF; ++i){
        if(i== 0 && isalpha(string[i]))
            string[i] = toupper(string[i]);
        else if(islower(string[i]) && !(isalpha(string[i-1])))
            string[i] = toupper(string[i]);
        if(!(string[i] == EOF))
            printf("%c", string[i]);
    }
    return 0;
}
