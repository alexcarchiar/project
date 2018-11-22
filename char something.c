//Lab07 05
#include <stdio.h>
#include <ctype.h>

int main(){
    
    char a, b, lower_a, lower_b;
    printf("Type the two chars\n");
    scanf("%c %c", &a, &b);
    if(isalpha(a) == 1 && isalpha(b) == 1){
        if(!(a == b)){
            lower_a = tolower(a);
            lower_b = tolower(b);
            if(lower_a<lower_b)
                printf("%c %c", a, b);
            else printf("%c %c", b, a);
        }
    } else if(isdigit(a) == 1 || isdigit(b) == 1)
        printf("At least one of them is a digit\n");
    
    return 0;
}
