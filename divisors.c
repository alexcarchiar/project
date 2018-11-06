#include <stdio.h>

int main()
{
	int i = 1;
  printf("Give a number, I'll give you its divisors \n");
	int n;
  scanf("%d", &n);
  while(i <= n) {
		if((n % i) == 0) {
			printf("\n %d",i);
        }
      i = i+1;
	}
	return 0;
}
