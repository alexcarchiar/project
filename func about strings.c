//
#include <stdio.h>

void swap(int a, int b);
int week_total(int d[]);

int main(){
	int x = 1;
	int y = 2;

	printf("x: %d - y: %d\n", x, y);
	swap(x, y);
	printf("x: %d - y: %d\n", x, y); //same as line 10; swap can't change variables in main

	int days[7] = {10, 4, 5, 23, 35, 34, 67};
	printf("Week total: %d\n", week_total(days))
	return 0;



void swap(int a, int b){
	int c = a;
	a = b;
	b = c;
	return;
}
int week_total(int d[]){
	int tot = 0;
	for(int i = 0; i<7; ++i)
		tot += d[i];
	return tot;
}