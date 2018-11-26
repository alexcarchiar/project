#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 4096

int my_own_strcmp_case_insensitive(const char *s1, const char *s2);

int main(){
	printf("Hello string functions!\n");
	char str1[MAX_STR_SIZE], str2[MAX_STR_SIZE];

	scanf("%s", str1);
	scanf("%s", str2);

	printf("\"%s\" len: %d\n", str1, strlen(str1));
	printf("\"%s\" len: %d\n", str2, strlen(str2));

	//concatenate: str1 += str2
	strcat(str1, str2);
	printf("str1 is now \"%s\"\n", str1);

	//copy: str3 = str1
	char str3[MAX_STR_SIZE];
	strcpy(str3, str1);

	//comparison
	if(my_own_strcmp_case_insensitive(str1, str2)<0){
		printf("\"%s\" < \"%s\"\n", str1, str2);
	} else if(my_own_strcmp_case_insensitive(str1, str2) == 0){
			printf("\"%s\" = \"%s\"\n", str1, str2);
		} else if(my_own_strcmp_case_insensitive(str1, str2) > 0){
			printf("\"%s\" > \"%s\"\n", str1, str2);
	}
}

int my_own_strcmp_case_insensitive(const char *s1, const char *s2){
	char ts1[MAX_STR_SIZE], ts2[MAX_STR_SIZE];

	//copy ts1 = ts2, then I lowercase everything
	strcpy(ts1, s1);
	for(int i = 0; ts1[i] != '\0'; ++i){
		ts1[i] = tolower(ts1[i]);
	}
	//same for ts2
	strcpy(ts2, s2);
	for(int i = 0; ts1[i] != '\0'; ++i)
		ts2[i] = tolower(ts2[i]);
	return strcmp(ts1, ts2);
}