#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 42;
    signed char c_s;
    unsigned char c_u;

    short int si = 42;
    int i = 42;
    long int li = 42;
    long long int lli = 42;

    printf("%d\n%d\n%d\n%ld\n%lld\nsize: %d\n", c, si, i, li, lli, sizeof(c));

    float f = 4.2;
    double d = 4.2;
    long double ld = 4.2;

    printf("%g\n%g\n%lg\n", f, d, ld);

    return 0;
}
