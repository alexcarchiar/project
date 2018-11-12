#include <stdio.h>
#include <stdlib.h>
//Celcius ti Farheneit with switch
//program doesn't work
int main()
{
    char c;

    scanf("%c", &c);

    switch(c) {
    case 'f':
    case 'F':
        printf("One!\n");
        break;
    case 'c':
    case 'C':
        printf("Two!\n");
        break;
    default:
        printf("D'ho");
        break;
    }
    return 0;
}
