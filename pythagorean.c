//Pythagorean triples
//lab 06 ex08
//broken
#include <stdio.h>
#include <math.h>

int main(){

	double a, b, c; //all Pythagorean triples are a^2 + b^2 = c^2
  	int c_ok; //used as a flag to check that our current triple is a valid one
  	printf("Given a range, I give you all the Pythagorean triples. Give me the range.\n")
	printf("First number of the range: \n");
	scanf("%lg", &a);
	printf("Second number of the range: \n");
	scanf("%lg", &b);
	printf("Pythagorean triples:\n");
	for(double i = a; i <= b; ++i){ //the program looks for all triples in the range a, b
		for(double j = a; j<= b; ++j){
			c = sqrt(i*i + j*j);
			c_ok =(int)(c); //used the cast to check that c is a perfect square
			if(((double)c_ok == c && c_ok > i) && (i <= j)){ //if c is a perfect square, then the triple is a valid one. i<=j makes sure we print each triple only once
				printf("%lg %lg %d \n", i, j, c_ok );
			}
		}
	}


	return 0;
}