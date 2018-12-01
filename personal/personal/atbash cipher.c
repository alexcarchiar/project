//atbash cipher from exercism
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGHT 256
int main(){
    int plain[26], cipher[26], text[MAX_LENGHT];
    for(int i = 0; i<26; ++i)
        plain[i] = i + 'a';
    printf("Plain\n");
    for(int i = 0; i<26; ++i)
        printf("%c", plain[i]);
    for(int i = 0; i<26; ++i)
        cipher[i] = 'z' - i;
    printf("\nCipher\n");
    for(int i = 0; i<26; ++i)
        printf("%c", cipher[i]);
    printf("\nEnter text\n");
    int c;
    int i = 0;
    do{
        c = getchar();
        if(isupper(c) == 1)
            c = tolower(c);
        text[i] = c;
        ++i;
    } while(c != '\n');
    printf("String\n");
    for(int k = 0; k<MAX_LENGHT; ++k)
        if(isalpha(text[k]) == 1){
            printf("%c", text[k]);
        }
    printf("\n");
    for(int k = 0; k<MAX_LENGHT; ++k){
            if(text[k] == 'a'){
                text[k] = 'z';
            } else if(text[k] == 'b'){
                text[k] = 'y';
            } else if(text[k] == 'c'){
                text[k] = 'x';
            } else if(text[k] == 'd'){
                text[k] = 'w';
            } else if(text[k] == 'e'){
                text[k] = 'v';
            } else if(text[k] == 'f'){
                text[k] = 'u';
            } else if(text[k] == 'g'){
                text[k] = 't';
            } else if(text[k] == 'h'){
                text[k] = 's';
            } else if(text[k] == 'i'){
                text[k] = 'r';
            } else if(text[k] == 'j'){
                text[k] = 'q';
            } else if(text[k] == 'k'){
                text[k] = 'p';
            } else if(text[k] == 'l'){
                text[k] = 'o';
            } else if(text[k] == 'm'){
                text[k] = 'n';
            } else if(text[k] == 'n'){
                text[k] = 'm';
            } else if(text[k] == 'o'){
                text[k] = 'l';
            } else if(text[k] == 'p'){
                text[k] = 'k';
            } else if(text[k] == 'q'){
                text[k] = 'j';
            } else if(text[k] == 'r'){
                text[k] = 'i';
            } else if(text[k] == 's'){
                text[k] = 'h';
            } else if(text[k] == 't'){
                text[k] = 'g';
            } else if(text[k] == 'u'){
                text[k] = 'f';
            } else if(text[k] == 'v'){
                text[k] = 'e';
            } else if(text[k] == 'w'){
                text[k] = 'd';
            } else if(text[k] == 'x'){
                text[k] = 'c';
            } else if(text[k] == 'y'){
                text[k] = 'b';
            } else if(text[k] == 'z'){
                text[k] = 'a';
            }
            /*switch(text[k]){
                case 'a': text[k] = 'z';
                    break;
                case 'b': text[k] = 'y';
                    break;
                case 'c': text[k] = 'x';
                    break;
                case 'd': text[k] = 'w';
                    break;
                case 'e': text[k] = 'v';
                    break;
                case 'f': text[k] = 'u';
                    break;
                case 'g': text[k] = 't';
                    break;
                case 'h': text[k] = 's';
                    break;
                case 'i': text[k] = 'r';
                    break;
                case 'j': text[k] = 'q';
                    break;
                case 'k': text[k] = 'p';
                    break;
                case 'l': text[k] = 'o';
                    break;
                case 'm': text[k] = 'n';
                    break;
                case 'n': text[k] = 'm';
                    break;
                case 'o': text[k] = 'l';
                    break;
                case 'p': text[k] = 'k';
                    break;
                case 'q': text[k] = 'j';
                    break;
                case 'r': text[k] = 'i';
                    break;
                case 's': text[k] = 'h';
                    break;
                case 't': text[k] = 'g';
                    break;
                case 'u': text[k] = 'f';
                    break;
                case 'v': text[k] = 'e';
                    break;
                case 'w': text[k] = 'd';
                    break;
                case 'x': text[k] = 'c';
                    break;
                case 'y': text[k] = 'b';
                    break;
                case 'z': text[k] = 'a';
                    break;
            }*/
           /* if((text[k] == plain[j])&&(isalpha(text[k]) == 1)){
                printf("%c", text[k]);
                text[k] = cipher[j];
            } */ //don't know why this doesn't work
        }
    printf("\n");
    for(int t = 0; t<MAX_LENGHT; ++t){
        if(isalpha(text[t]) == 1){
            printf("%c", text[t]);
        }
    }
    printf("\n");
    return 0;
}
