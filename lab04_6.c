//Lab04_6

#include <stdio.h>

int main() {

	int n, list[10], ave, sum;
	sum = 0;
	ave = 0;
	printf("N: \n");
	scanf("%d", &n);
	for(int i = 0; i < 10 && ave < n; i++){
		printf("Number: \n");
		scanf("%d", &list[i]);
		for(int j = 0; j < ++i; j++){
			sum += list[j];
		}
		ave = sum / i;
	}

	return 0;
}