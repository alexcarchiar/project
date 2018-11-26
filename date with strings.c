#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Insert a date (dd-mm-yyyy)\n");
	char date[256];
	scanf("%s" date);

	//parser!
	int d, m, y;
	sscanf(date, "%d-%d-%d", &d, &m, &y); //the sscanf tries to recognise the pattern %d-%d-%d
	printf("Day: %d\n", d);
	printf("Month: %d\n", m);
	printf("Year: %d\n", y);
	return 0;
}