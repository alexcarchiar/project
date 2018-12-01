#include <stdio.h>
#include <stdlib.h>

int main()
{
    float length;
    float width;
    float perimeter;
    printf("Give me the data, I'll calculate the perimeter\nLength\n");
    scanf("%g", &length);
    printf("Width");
    scanf("%g", &width);
    perimeter = (length + width) * 2.0;
    printf("The perimeter is: %g", perimeter);
    return 0;
}
