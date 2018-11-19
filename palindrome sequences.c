//Palindrome sequences
//Lab06 ex 1
#include <stdio.h>

#define N 5

int main(){
	int sequence[N];
	for(int i = 0; i<N; ++i){ //getting the values
		printf("Write the term index %d\n", i);
		scanf("%d", &sequence[i]);
	}
	int copy[N];
	int i = N - 1;
	int j = 0;
	while(j<N && i >= 0){ //copying the reversed array
		copy[i] = sequence[j];
		++j;
		--i;
	}
	int flag = 0; //used to check if the sequence is palindrome, it is if flag = 0
	for(int t = 0; t<N && flag == 0; ++t){
		if(sequence[t] != copy[t])
			++flag;
	}
	if(flag == 0)
		printf("The sequence is palindrome");
	else
		printf("The sequence is not palindrome");

	return 0;

}