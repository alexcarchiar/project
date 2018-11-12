#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char c;

    scanf("%c", &c);
    c = 0;
    while (c <= 254) {
        printf("%c ", c);
        c++;
    }
    return 0;
}
