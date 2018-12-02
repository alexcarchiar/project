#include <stdio.h>
#include <stdlib.h>
//creating a project for exercism: binary conversion
int main()
{
    printf("I am a conversion tool from decimal to binary.\nGive me your number: ");
    int number[0];
    scanf("%d", &number);
    for(int i = 0; i < 3; i++)
        printf("%d", number[i]);
    return 0;
}
