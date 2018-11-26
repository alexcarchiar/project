#include <stdio.h>
#include <stdlib.h>

int main(){
	char str = "1970";
	int val;

	//method 1
	val = 0;
	for(int i = 0; str[i] != '\0'; ++i){
		val = val*10 + str[i] - '0';
	}
	printf("Method 1: %d\n", val);

	//method 2
	val = atoi(str);
	printf("Method 2: %d\n", val); //in this way we are not able to do any error control
	//this is to go to integer

	//method 3 --> recommended by professor
	sscanf(str, "%d", &val); //the first argument is constant
	printf("Method 3: %d\n", val);

	//jolly: sprintf
	char tmp[256];
	sprintf(tmp, "Hey pi is %.2f", 3.1495); //used to create a string in the format of printf

	return 0;
}