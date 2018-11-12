#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val;

    scanf("%d", &val);

    if(val %2 == 1) {
        printf("odd!\n");
    } else if(val > 100) {
        printf("big!\n");
    } else if (val < 0) {
        printf("negative!\n");
    } else {
    printf("neither odd, big, negative\n");
    }

    return 0;
}
