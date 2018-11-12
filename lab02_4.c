#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var1;
    int var2;
    var1 = 25;
    var2 = - 53;
    var1 = var1 + var2;
    var2 = var1 - var2;
    var1 = var1 - var2;
    printf("%d %d", var1, var2);
    return 0;
}
